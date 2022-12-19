#pragma once

#include <atlbase.h>
#include <d3d11.h>
#include <dxgi1_2.h>
#include <comdef.h>
#include <wincodec.h>
#include <functional>

#include <wrl/client.h>
using Microsoft::WRL::ComPtr;

BOOL WINAPI InitializeWICFactory(PINIT_ONCE, PVOID, PVOID *ifactory) noexcept
{
    return SUCCEEDED(CoCreateInstance(
        CLSID_WICImagingFactory2,
        nullptr,
        CLSCTX_INPROC_SERVER,
        __uuidof(IWICImagingFactory2),
        ifactory)) ? TRUE : FALSE;
}

bool _IsWIC2() { return true; }
IWICImagingFactory2* _GetWIC()
{
    static INIT_ONCE s_initOnce = INIT_ONCE_STATIC_INIT;

    IWICImagingFactory2* factory = nullptr;
    (void)InitOnceExecuteOnce(
        &s_initOnce,
        InitializeWICFactory,
        nullptr,
        reinterpret_cast<LPVOID*>(&factory));

    return factory;
}

class auto_delete_file_wic
{
public:
    auto_delete_file_wic(Microsoft::WRL::ComPtr<IWICStream>& hFile, LPCWSTR szFile) : m_filename(szFile), m_handle(hFile) {}

    auto_delete_file_wic(const auto_delete_file_wic&) = delete;
    auto_delete_file_wic& operator=(const auto_delete_file_wic&) = delete;

    ~auto_delete_file_wic()
    {
        if (m_filename)
        {
            m_handle.Reset();
            DeleteFileW(m_filename);
        }
    }

    void clear() { m_filename = nullptr; }

private:
    LPCWSTR m_filename;
    Microsoft::WRL::ComPtr<IWICStream>& m_handle;
};

#ifndef IID_GRAPHICS_PPV_ARGS
#define IID_GRAPHICS_PPV_ARGS(x) IID_PPV_ARGS(x)
#endif

DXGI_FORMAT EnsureNotTypeless( DXGI_FORMAT fmt )
{
    // Assumes UNORM or FLOAT; doesn't use UINT or SINT
    switch( fmt )
    {
    case DXGI_FORMAT_R32G32B32A32_TYPELESS: return DXGI_FORMAT_R32G32B32A32_FLOAT;
    case DXGI_FORMAT_R32G32B32_TYPELESS:    return DXGI_FORMAT_R32G32B32_FLOAT;
    case DXGI_FORMAT_R16G16B16A16_TYPELESS: return DXGI_FORMAT_R16G16B16A16_UNORM;
    case DXGI_FORMAT_R32G32_TYPELESS:       return DXGI_FORMAT_R32G32_FLOAT;
    case DXGI_FORMAT_R10G10B10A2_TYPELESS:  return DXGI_FORMAT_R10G10B10A2_UNORM;
    case DXGI_FORMAT_R8G8B8A8_TYPELESS:     return DXGI_FORMAT_R8G8B8A8_UNORM;
    case DXGI_FORMAT_R16G16_TYPELESS:       return DXGI_FORMAT_R16G16_UNORM;
    case DXGI_FORMAT_R32_TYPELESS:          return DXGI_FORMAT_R32_FLOAT;
    case DXGI_FORMAT_R8G8_TYPELESS:         return DXGI_FORMAT_R8G8_UNORM;
    case DXGI_FORMAT_R16_TYPELESS:          return DXGI_FORMAT_R16_UNORM;
    case DXGI_FORMAT_R8_TYPELESS:           return DXGI_FORMAT_R8_UNORM;
    case DXGI_FORMAT_BC1_TYPELESS:          return DXGI_FORMAT_BC1_UNORM;
    case DXGI_FORMAT_BC2_TYPELESS:          return DXGI_FORMAT_BC2_UNORM;
    case DXGI_FORMAT_BC3_TYPELESS:          return DXGI_FORMAT_BC3_UNORM;
    case DXGI_FORMAT_BC4_TYPELESS:          return DXGI_FORMAT_BC4_UNORM;
    case DXGI_FORMAT_BC5_TYPELESS:          return DXGI_FORMAT_BC5_UNORM;
    case DXGI_FORMAT_B8G8R8A8_TYPELESS:     return DXGI_FORMAT_B8G8R8A8_UNORM;
    case DXGI_FORMAT_B8G8R8X8_TYPELESS:     return DXGI_FORMAT_B8G8R8X8_UNORM;
    case DXGI_FORMAT_BC7_TYPELESS:          return DXGI_FORMAT_BC7_UNORM;
    default:                                return fmt;
    }
}

using Microsoft::WRL::ComPtr;

//--------------------------------------------------------------------------------------
HRESULT CaptureTexture(
    _In_ ID3D11DeviceContext* pContext,
    _In_ ID3D11Resource* pSource,
    D3D11_TEXTURE2D_DESC& desc,
    ComPtr<ID3D11Texture2D>& pStaging)
{
    if (!pContext || !pSource)
        return E_INVALIDARG;

    D3D11_RESOURCE_DIMENSION resType = D3D11_RESOURCE_DIMENSION_UNKNOWN;
    pSource->GetType(&resType);

    if (resType != D3D11_RESOURCE_DIMENSION_TEXTURE2D)
    {
        //DebugTrace("ERROR: ScreenGrab does not support 1D or volume textures. Consider using DirectXTex instead.\n");
        return HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
    }

    ComPtr<ID3D11Texture2D> pTexture;
    HRESULT hr = pSource->QueryInterface(IID_GRAPHICS_PPV_ARGS(pTexture.GetAddressOf()));
    if (FAILED(hr))
        return hr;

    assert(pTexture);

    pTexture->GetDesc(&desc);

    if (desc.ArraySize > 1 || desc.MipLevels > 1)
    {
        //DebugTrace("WARNING: ScreenGrab does not support 2D arrays, cubemaps, or mipmaps; only the first surface is written. Consider using DirectXTex instead.\n");
    }

    ComPtr<ID3D11Device> d3dDevice;
    pContext->GetDevice(d3dDevice.GetAddressOf());

    if (desc.SampleDesc.Count > 1)
    {
        // MSAA content must be resolved before being copied to a staging texture
        desc.SampleDesc.Count = 1;
        desc.SampleDesc.Quality = 0;

        ComPtr<ID3D11Texture2D> pTemp;
        hr = d3dDevice->CreateTexture2D(&desc, nullptr, pTemp.GetAddressOf());
        if (FAILED(hr))
            return hr;

        assert(pTemp);

        DXGI_FORMAT fmt = EnsureNotTypeless(desc.Format);

        UINT support = 0;
        hr = d3dDevice->CheckFormatSupport(fmt, &support);
        if (FAILED(hr))
            return hr;

        if (!(support & D3D11_FORMAT_SUPPORT_MULTISAMPLE_RESOLVE))
            return E_FAIL;

        for (UINT item = 0; item < desc.ArraySize; ++item)
        {
            for (UINT level = 0; level < desc.MipLevels; ++level)
            {
                UINT index = D3D11CalcSubresource(level, item, desc.MipLevels);
                pContext->ResolveSubresource(pTemp.Get(), index, pSource, index, fmt);
            }
        }

        desc.BindFlags = 0;
        desc.MiscFlags &= D3D11_RESOURCE_MISC_TEXTURECUBE;
        desc.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
        desc.Usage = D3D11_USAGE_STAGING;

        hr = d3dDevice->CreateTexture2D(&desc, nullptr, pStaging.ReleaseAndGetAddressOf());
        if (FAILED(hr))
            return hr;

        assert(pStaging);

        pContext->CopyResource(pStaging.Get(), pTemp.Get());
    }
    else if ((desc.Usage == D3D11_USAGE_STAGING) && (desc.CPUAccessFlags & D3D11_CPU_ACCESS_READ))
    {
        // Handle case where the source is already a staging texture we can use directly
        pStaging = pTexture;
    }
    else
    {
        // Otherwise, create a staging texture from the non-MSAA source
        desc.BindFlags = 0;
        desc.MiscFlags &= D3D11_RESOURCE_MISC_TEXTURECUBE;
        desc.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
        desc.Usage = D3D11_USAGE_STAGING;

        hr = d3dDevice->CreateTexture2D(&desc, nullptr, pStaging.ReleaseAndGetAddressOf());
        if (FAILED(hr))
            return hr;

        assert(pStaging);

        pContext->CopyResource(pStaging.Get(), pSource);
    }

#if defined(_XBOX_ONE) && defined(_TITLE)

    if (d3dDevice->GetCreationFlags() & D3D11_CREATE_DEVICE_IMMEDIATE_CONTEXT_FAST_SEMANTICS)
    {
        ComPtr<ID3D11DeviceX> d3dDeviceX;
        hr = d3dDevice.As(&d3dDeviceX);
        if (FAILED(hr))
            return hr;

        ComPtr<ID3D11DeviceContextX> d3dContextX;
        hr = pContext->QueryInterface(IID_GRAPHICS_PPV_ARGS(d3dContextX.GetAddressOf()));
        if (FAILED(hr))
            return hr;

        UINT64 copyFence = d3dContextX->InsertFence(0);

        while (d3dDeviceX->IsFencePending(copyFence))
        {
            SwitchToThread();
        }
    }

#endif

    return S_OK;
}

HRESULT __cdecl SaveWICTextureToFile(
    _In_ ID3D11DeviceContext* pContext,
    _In_ ID3D11Resource* pSource,
    _In_ REFGUID guidContainerFormat,
    _In_z_ const wchar_t* fileName,
    _In_opt_ const GUID* targetFormat = nullptr,
    _In_opt_ std::function<void __cdecl(IPropertyBag2*)> setCustomProps = nullptr);

HRESULT SaveWICTextureToFile(
    ID3D11DeviceContext* pContext,
    ID3D11Resource* pSource,
    REFGUID guidContainerFormat,
    const wchar_t* fileName,
    const GUID* targetFormat,
    std::function<void(IPropertyBag2*)> setCustomProps)
{
    if (!fileName)
        return E_INVALIDARG;

    D3D11_TEXTURE2D_DESC desc = {};
    ComPtr<ID3D11Texture2D> pStaging;
    HRESULT hr = CaptureTexture(pContext, pSource, desc, pStaging);
    if (FAILED(hr))
        return hr;

    // Determine source format's WIC equivalent
    WICPixelFormatGUID pfGuid;
    bool sRGB = false;
    switch (desc.Format)
    {
        case DXGI_FORMAT_R32G32B32A32_FLOAT:            pfGuid = GUID_WICPixelFormat128bppRGBAFloat; break;
        case DXGI_FORMAT_R16G16B16A16_FLOAT:            pfGuid = GUID_WICPixelFormat64bppRGBAHalf; break;
        case DXGI_FORMAT_R16G16B16A16_UNORM:            pfGuid = GUID_WICPixelFormat64bppRGBA; break;
        case DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM:    pfGuid = GUID_WICPixelFormat32bppRGBA1010102XR; break; // DXGI 1.1
        case DXGI_FORMAT_R10G10B10A2_UNORM:             pfGuid = GUID_WICPixelFormat32bppRGBA1010102; break;
        case DXGI_FORMAT_B5G5R5A1_UNORM:                pfGuid = GUID_WICPixelFormat16bppBGRA5551; break;
        case DXGI_FORMAT_B5G6R5_UNORM:                  pfGuid = GUID_WICPixelFormat16bppBGR565; break;
        case DXGI_FORMAT_R32_FLOAT:                     pfGuid = GUID_WICPixelFormat32bppGrayFloat; break;
        case DXGI_FORMAT_R16_FLOAT:                     pfGuid = GUID_WICPixelFormat16bppGrayHalf; break;
        case DXGI_FORMAT_R16_UNORM:                     pfGuid = GUID_WICPixelFormat16bppGray; break;
        case DXGI_FORMAT_R8_UNORM:                      pfGuid = GUID_WICPixelFormat8bppGray; break;
        case DXGI_FORMAT_A8_UNORM:                      pfGuid = GUID_WICPixelFormat8bppAlpha; break;

        case DXGI_FORMAT_R8G8B8A8_UNORM:
            pfGuid = GUID_WICPixelFormat32bppRGBA;
            break;

        case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
            pfGuid = GUID_WICPixelFormat32bppRGBA;
            sRGB = true;
            break;

        case DXGI_FORMAT_B8G8R8A8_UNORM: // DXGI 1.1
            pfGuid = GUID_WICPixelFormat32bppBGRA;
            break;

        case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB: // DXGI 1.1
            pfGuid = GUID_WICPixelFormat32bppBGRA;
            sRGB = true;
            break;

        case DXGI_FORMAT_B8G8R8X8_UNORM: // DXGI 1.1
            pfGuid = GUID_WICPixelFormat32bppBGR;
            break;

        case DXGI_FORMAT_B8G8R8X8_UNORM_SRGB: // DXGI 1.1
            pfGuid = GUID_WICPixelFormat32bppBGR;
            sRGB = true;
            break;

        default:
            //DebugTrace("ERROR: ScreenGrab does not support all DXGI formats (%u). Consider using DirectXTex.\n", static_cast<uint32_t>(desc.Format));
            return HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED);
    }

    auto pWIC = _GetWIC();
    if (!pWIC)
        return E_NOINTERFACE;

    ComPtr<IWICStream> stream;
    hr = pWIC->CreateStream(stream.GetAddressOf());
    if (FAILED(hr))
        return hr;

    hr = stream->InitializeFromFilename(fileName, GENERIC_WRITE);
    if (FAILED(hr))
        return hr;

    auto_delete_file_wic delonfail(stream, fileName);

    ComPtr<IWICBitmapEncoder> encoder;
    hr = pWIC->CreateEncoder(guidContainerFormat, nullptr, encoder.GetAddressOf());
    if (FAILED(hr))
        return hr;

    hr = encoder->Initialize(stream.Get(), WICBitmapEncoderNoCache);
    if (FAILED(hr))
        return hr;

    ComPtr<IWICBitmapFrameEncode> frame;
    ComPtr<IPropertyBag2> props;
    hr = encoder->CreateNewFrame(frame.GetAddressOf(), props.GetAddressOf());
    if (FAILED(hr))
        return hr;

    if (targetFormat && memcmp(&guidContainerFormat, &GUID_ContainerFormatBmp, sizeof(WICPixelFormatGUID)) == 0 && _IsWIC2())
    {
        // Opt-in to the WIC2 support for writing 32-bit Windows BMP files with an alpha channel
        PROPBAG2 option = {};
        option.pstrName = const_cast<wchar_t*>(L"EnableV5Header32bppBGRA");

        VARIANT varValue;
        varValue.vt = VT_BOOL;
        varValue.boolVal = VARIANT_TRUE;
        (void)props->Write(1, &option, &varValue);
    }

    if (setCustomProps)
    {
        setCustomProps(props.Get());
    }

    hr = frame->Initialize(props.Get());
    if (FAILED(hr))
        return hr;

    hr = frame->SetSize(desc.Width, desc.Height);
    if (FAILED(hr))
        return hr;

    hr = frame->SetResolution(72, 72);
    if (FAILED(hr))
        return hr;

    // Pick a target format
    WICPixelFormatGUID targetGuid;
    if (targetFormat)
    {
        targetGuid = *targetFormat;
    }
    else
    {
        // Screenshots don't typically include the alpha channel of the render target
        switch (desc.Format)
        {
        #if (_WIN32_WINNT >= _WIN32_WINNT_WIN8) || defined(_WIN7_PLATFORM_UPDATE)
            case DXGI_FORMAT_R32G32B32A32_FLOAT:
            case DXGI_FORMAT_R16G16B16A16_FLOAT:
                if (_IsWIC2())
                {
                    targetGuid = GUID_WICPixelFormat96bppRGBFloat;
                }
                else
                {
                    targetGuid = GUID_WICPixelFormat24bppBGR;
                }
                break;
            #endif

            case DXGI_FORMAT_R16G16B16A16_UNORM: targetGuid = GUID_WICPixelFormat48bppBGR; break;
            case DXGI_FORMAT_B5G5R5A1_UNORM:     targetGuid = GUID_WICPixelFormat16bppBGR555; break;
            case DXGI_FORMAT_B5G6R5_UNORM:       targetGuid = GUID_WICPixelFormat16bppBGR565; break;

            case DXGI_FORMAT_R32_FLOAT:
            case DXGI_FORMAT_R16_FLOAT:
            case DXGI_FORMAT_R16_UNORM:
            case DXGI_FORMAT_R8_UNORM:
            case DXGI_FORMAT_A8_UNORM:
                targetGuid = GUID_WICPixelFormat8bppGray;
                break;

            default:
                targetGuid = GUID_WICPixelFormat24bppBGR;
                break;
        }
    }

    hr = frame->SetPixelFormat(&targetGuid);
    if (FAILED(hr))
        return hr;

    if (targetFormat && memcmp(targetFormat, &targetGuid, sizeof(WICPixelFormatGUID)) != 0)
    {
        // Requested output pixel format is not supported by the WIC codec
        return E_FAIL;
    }

    // Encode WIC metadata
    ComPtr<IWICMetadataQueryWriter> metawriter;
    if (SUCCEEDED(frame->GetMetadataQueryWriter(metawriter.GetAddressOf())))
    {
        PROPVARIANT value;
        PropVariantInit(&value);

        value.vt = VT_LPSTR;
        value.pszVal = const_cast<char*>("DirectXTK");

        if (memcmp(&guidContainerFormat, &GUID_ContainerFormatPng, sizeof(GUID)) == 0)
        {
            // Set Software name
            (void)metawriter->SetMetadataByName(L"/tEXt/{str=Software}", &value);

            // Set sRGB chunk
            if (sRGB)
            {
                value.vt = VT_UI1;
                value.bVal = 0;
                (void)metawriter->SetMetadataByName(L"/sRGB/RenderingIntent", &value);
            }
            else
            {
                // add gAMA chunk with gamma 1.0
                value.vt = VT_UI4;
                value.uintVal = 100000; // gama value * 100,000 -- i.e. gamma 1.0
                (void)metawriter->SetMetadataByName(L"/gAMA/ImageGamma", &value);

                // remove sRGB chunk which is added by default.
                (void)metawriter->RemoveMetadataByName(L"/sRGB/RenderingIntent");
            }
        }
    #if defined(_XBOX_ONE) && defined(_TITLE)
        else if (memcmp(&guidContainerFormat, &GUID_ContainerFormatJpeg, sizeof(GUID)) == 0)
        {
            // Set Software name
            (void)metawriter->SetMetadataByName(L"/app1/ifd/{ushort=305}", &value);

            if (sRGB)
            {
                // Set EXIF Colorspace of sRGB
                value.vt = VT_UI2;
                value.uiVal = 1;
                (void)metawriter->SetMetadataByName(L"/app1/ifd/exif/{ushort=40961}", &value);
            }
        }
        else if (memcmp(&guidContainerFormat, &GUID_ContainerFormatTiff, sizeof(GUID)) == 0)
        {
            // Set Software name
            (void)metawriter->SetMetadataByName(L"/ifd/{ushort=305}", &value);

            if (sRGB)
            {
                // Set EXIF Colorspace of sRGB
                value.vt = VT_UI2;
                value.uiVal = 1;
                (void)metawriter->SetMetadataByName(L"/ifd/exif/{ushort=40961}", &value);
            }
        }
    #else
        else
        {
            // Set Software name
            (void)metawriter->SetMetadataByName(L"System.ApplicationName", &value);

            if (sRGB)
            {
                // Set EXIF Colorspace of sRGB
                value.vt = VT_UI2;
                value.uiVal = 1;
                (void)metawriter->SetMetadataByName(L"System.Image.ColorSpace", &value);
            }
        }
    #endif
    }

    D3D11_MAPPED_SUBRESOURCE mapped;
    hr = pContext->Map(pStaging.Get(), 0, D3D11_MAP_READ, 0, &mapped);
    if (FAILED(hr))
        return hr;

    if (memcmp(&targetGuid, &pfGuid, sizeof(WICPixelFormatGUID)) != 0)
    {
        // Conversion required to write
        ComPtr<IWICBitmap> source;
        hr = pWIC->CreateBitmapFromMemory(desc.Width, desc.Height, pfGuid,
                                          mapped.RowPitch, mapped.RowPitch * desc.Height,
                                          static_cast<BYTE*>(mapped.pData), source.GetAddressOf());
        if (FAILED(hr))
        {
            pContext->Unmap(pStaging.Get(), 0);
            return hr;
        }

        ComPtr<IWICFormatConverter> FC;
        hr = pWIC->CreateFormatConverter(FC.GetAddressOf());
        if (FAILED(hr))
        {
            pContext->Unmap(pStaging.Get(), 0);
            return hr;
        }

        BOOL canConvert = FALSE;
        hr = FC->CanConvert(pfGuid, targetGuid, &canConvert);
        if (FAILED(hr) || !canConvert)
        {
            return E_UNEXPECTED;
        }

        hr = FC->Initialize(source.Get(), targetGuid, WICBitmapDitherTypeNone, nullptr, 0, WICBitmapPaletteTypeMedianCut);
        if (FAILED(hr))
        {
            pContext->Unmap(pStaging.Get(), 0);
            return hr;
        }

        WICRect rect = { 0, 0, static_cast<INT>(desc.Width), static_cast<INT>(desc.Height) };
        hr = frame->WriteSource(FC.Get(), &rect);
        if (FAILED(hr))
        {
            pContext->Unmap(pStaging.Get(), 0);
            return hr;
        }
    }
    else
    {
        // No conversion required
        hr = frame->WritePixels(desc.Height, mapped.RowPitch, mapped.RowPitch * desc.Height, static_cast<BYTE*>(mapped.pData));
        if (FAILED(hr))
            return hr;
    }

    pContext->Unmap(pStaging.Get(), 0);

    hr = frame->Commit();
    if (FAILED(hr))
        return hr;

    hr = encoder->Commit();
    if (FAILED(hr))
        return hr;

    delonfail.clear();

    return S_OK;
}

#define LOG(format, ...) _log(format L"\n", __VA_ARGS__)
#define ERR(format, ...) LOG(L"Error: " format, __VA_ARGS__)

inline  void _log(const wchar_t * format, ...) {
#if _DEBUG
    wchar_t buffer[256];
    va_list args;
    va_start(args, format);
    vswprintf(buffer, 256, format, args);
    OutputDebugStringW(buffer);
#endif
}

#define RETURN_ON_BAD_HR(expr) \
{ \
    HRESULT _hr_ = (expr); \
    if (FAILED(_hr_)) { \
    {\
        _com_error err(_hr_);\
        ERR(L"RETURN_ON_BAD_HR: %ls", err.ErrorMessage());\
    }\
        return _hr_; \
    } \
}

// Driver types supported
D3D_DRIVER_TYPE gDriverTypes[] =
{
    D3D_DRIVER_TYPE_HARDWARE,
    D3D_DRIVER_TYPE_WARP,
    D3D_DRIVER_TYPE_REFERENCE,
};
UINT m_NumDriverTypes = ARRAYSIZE(gDriverTypes);

// Feature levels supported
D3D_FEATURE_LEVEL m_FeatureLevels[] =
{
    D3D_FEATURE_LEVEL_11_0,
    D3D_FEATURE_LEVEL_10_1,
    D3D_FEATURE_LEVEL_10_0,
    D3D_FEATURE_LEVEL_9_1
};

HRESULT InitializeDesktopDupl(ID3D11Device *pDevice, IDXGIOutputDuplication **ppDesktopDupl, DXGI_OUTDUPL_DESC *pOutputDuplDesc)
{
    *ppDesktopDupl = nullptr;
    *pOutputDuplDesc;

    // Get DXGI device
    CComPtr<IDXGIDevice> pDxgiDevice;
    CComPtr<IDXGIOutputDuplication> pDeskDupl = nullptr;
    DXGI_OUTDUPL_DESC OutputDuplDesc;

    HRESULT hr = pDevice->QueryInterface(IID_PPV_ARGS(&pDxgiDevice));

    if (FAILED(hr)) { return hr; }
    // Get DXGI adapter
    CComPtr<IDXGIAdapter> pDxgiAdapter;
    hr = pDxgiDevice->GetParent(
                __uuidof(IDXGIAdapter),
                reinterpret_cast<void**>(&pDxgiAdapter));
    pDxgiDevice.Release();
    if (FAILED(hr)) { return hr; }

    UINT m_DisplayOutput = 0; //Display output, where 0 is primary display.

    // Get output
    CComPtr<IDXGIOutput> pDxgiOutput;
    hr = pDxgiAdapter->EnumOutputs(
                m_DisplayOutput,
                &pDxgiOutput);
    if (FAILED(hr)) { return hr; }
    pDxgiAdapter.Release();

    CComPtr<IDXGIOutput1> pDxgiOutput1;

    hr = pDxgiOutput->QueryInterface(IID_PPV_ARGS(&pDxgiOutput1));
    if (FAILED(hr)) { return hr; }
    pDxgiOutput.Release();

    // Create desktop duplication
    hr = pDxgiOutput1->DuplicateOutput(
                pDevice,
                &pDeskDupl);
    if (FAILED(hr)) { return hr; }
    pDxgiOutput1.Release();

    // Create GUI drawing texture
    pDeskDupl->GetDesc(&OutputDuplDesc);

    pDxgiOutput1.Release();

    *ppDesktopDupl = pDeskDupl;
    (*ppDesktopDupl)->AddRef();
    *pOutputDuplDesc = OutputDuplDesc;
    return hr;
}

HRESULT InitializeDx(ID3D11DeviceContext **ppContext, ID3D11Device **ppDevice, IDXGIOutputDuplication **ppDesktopDupl, DXGI_OUTDUPL_DESC *pOutputDuplDesc) {
    *ppContext = nullptr;
    *ppDevice = nullptr;
    *ppDesktopDupl = nullptr;
    *pOutputDuplDesc;

    HRESULT hr(S_OK);
    DXGI_OUTDUPL_DESC OutputDuplDesc;
    CComPtr<ID3D11DeviceContext> m_ImmediateContext = nullptr;
    CComPtr<ID3D11Device> pDevice = nullptr;
    CComPtr<IDXGIOutputDuplication> pDeskDupl = nullptr;
    int lresult(-1);
    D3D_FEATURE_LEVEL featureLevel;

    // Create device
    for (UINT DriverTypeIndex = 0; DriverTypeIndex < m_NumDriverTypes; ++DriverTypeIndex)
    {
        hr = D3D11CreateDevice(
                    nullptr,
                    gDriverTypes[DriverTypeIndex],
                    nullptr,
            #if _DEBUG
                    D3D11_CREATE_DEVICE_DEBUG,
            #else
                    0,
            #endif
                    m_FeatureLevels,
                    ARRAYSIZE(m_FeatureLevels),
                    D3D11_SDK_VERSION,
                    &pDevice,
                    &featureLevel,
                    &m_ImmediateContext);

        if (SUCCEEDED(hr))
        {
//#if _DEBUG
//            HRESULT hr = pDevice->QueryInterface(IID_PPV_ARGS(&m_Debug));
//#endif
            // Device creation success, no need to loop anymore
            break;
        }
    }

    RETURN_ON_BAD_HR(hr);
    CComPtr<ID3D10Multithread> pMulti = nullptr;
    hr = m_ImmediateContext->QueryInterface(IID_PPV_ARGS(&pMulti));
    RETURN_ON_BAD_HR(hr);
    hr = pMulti->SetMultithreadProtected(TRUE);
    RETURN_ON_BAD_HR(hr);
    pMulti.Release();
    if (pDevice == nullptr)
        return S_FALSE;
    hr = InitializeDesktopDupl(pDevice, &pDeskDupl, &OutputDuplDesc);

    // Return the pointer to the caller.
    *ppContext = m_ImmediateContext;
    (*ppContext)->AddRef();
    *ppDevice = pDevice;
    (*ppDevice)->AddRef();
    *ppDesktopDupl = pDeskDupl;
    (*ppDesktopDupl)->AddRef();
    *pOutputDuplDesc = OutputDuplDesc;

    return hr;
}

const GUID   IMAGE_ENCODER_FORMAT = GUID_ContainerFormatPng;

HRESULT WriteFrameToImage(ID3D11DeviceContext* m_ImmediateContext, ID3D11Texture2D* pAcquiredDesktopImage, LPCWSTR filePath)
{
    HRESULT hr = SaveWICTextureToFile(m_ImmediateContext, pAcquiredDesktopImage, IMAGE_ENCODER_FORMAT, filePath);
    return hr;
}
