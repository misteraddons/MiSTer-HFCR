#include "screengrab.h"

void capture()
{
    CComPtr<ID3D11Device> pDevice;
    CComPtr<IDXGIOutputDuplication> pDeskDupl;
    //(...)create devices and duplication interface etc here..

    DXGI_OUTDUPL_DESC OutputDuplDesc;

    CComPtr<ID3D11DeviceContext> m_ImmediateContext = nullptr;

    auto hr = InitializeDx(&m_ImmediateContext, &pDevice, &pDeskDupl, &OutputDuplDesc);

    D3D11_TEXTURE2D_DESC frameDesc;
    frameDesc.Width = OutputDuplDesc.ModeDesc.Width;
    frameDesc.Height = OutputDuplDesc.ModeDesc.Height;
    frameDesc.Format = OutputDuplDesc.ModeDesc.Format;
    frameDesc.ArraySize = 1;
    frameDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_RENDER_TARGET;
    frameDesc.MiscFlags = D3D11_RESOURCE_MISC_GDI_COMPATIBLE;
    frameDesc.SampleDesc.Count = 1;
    frameDesc.SampleDesc.Quality = 0;
    frameDesc.MipLevels = 1;
    frameDesc.CPUAccessFlags = 0;
    frameDesc.Usage = D3D11_USAGE_DEFAULT;

    if (pDeskDupl) pDeskDupl.Release();
    hr = InitializeDesktopDupl(pDevice, &pDeskDupl, &OutputDuplDesc);

    UINT frameTimeout = 1000;
    int frameNumber = 0;

    while(frameNumber++ < 50) //capture loop gist.
    {
        int lTryCount = 4;

        CComPtr<IDXGIResource> lDesktopResource;
        CComPtr<ID3D11Texture2D> lAcquiredDesktopImage;
        DXGI_OUTDUPL_FRAME_INFO lFrameInfo;

        do
        {
            // Get new frame
            hr = pDeskDupl->AcquireNextFrame(
                INFINITE,
                &lFrameInfo,
                &lDesktopResource);

            if (SUCCEEDED(hr))
                break;

            if (hr == DXGI_ERROR_WAIT_TIMEOUT)
            {
                continue;
            }
            else if (FAILED(hr))
                break;

        } while (--lTryCount > 0);

        // QI for ID3D11Texture2D
        hr = lDesktopResource->QueryInterface(IID_PPV_ARGS(&lAcquiredDesktopImage));

        lDesktopResource.Release();

        if (lAcquiredDesktopImage == nullptr) {
            return;
        }

        // Copy image
        CComPtr<ID3D11Texture2D> pFrameCopy;
        hr = pDevice->CreateTexture2D(&frameDesc, nullptr, &pFrameCopy);
        m_ImmediateContext->CopyResource(pFrameCopy, lAcquiredDesktopImage);

        WriteFrameToImage(m_ImmediateContext, pFrameCopy, L"Test.png");

        lAcquiredDesktopImage.Release();

        pDeskDupl->ReleaseFrame();
    }
}