using hfcrbuilder;
using System.Text;

string sourcePath = "C:\\repos\\Aznable\\resources\\hfcr";


File.ReadAllLines(sourcePath);

int type_max = 0;
int colour_max = 0;

List<string> types = new List<string>();
List<List<ColourEntry>> colours = new List<List<ColourEntry>>();
foreach (var file in Directory.GetFiles(sourcePath, "*.csv"))
{
    string type = Path.GetFileNameWithoutExtension(file);
    types.Add(type);
    type_max++;
    string[] lines = File.ReadAllLines(file);
    bool isHeader = true;
    foreach (string line in lines)
    {
        if (isHeader) { continue; }
        colour_max++;
    }
}

StringBuilder builder = new StringBuilder();
builder.AppendLine("#ifndef HFCR_DATA_H");
builder.AppendLine("#define HFCR_DATA_H");
builder.AppendLine("#define hfcr_type_max 1");
builder.AppendLine("#define hfcr_colour_max 2");
builder.AppendLine("extern const char* hfcr_type[hfcr_type_max];");
builder.AppendLine("extern const char* hfcr_colour_name[hfcr_type_max][hfcr_colour_max];");
builder.AppendLine("extern unsigned char hfcr_colour_r[hfcr_type_max][hfcr_colour_max];");
builder.AppendLine("extern unsigned char hfcr_colour_g[hfcr_type_max][hfcr_colour_max];");
builder.AppendLine("extern unsigned char hfcr_colour_b[hfcr_type_max][hfcr_colour_max];");
builder.AppendLine("#endif");

builder.AppendLine("#ifndef HFCR_DATA_C");
builder.AppendLine("#define HFCR_DATA_C");
builder.AppendLine("#include \"hfcr_data.h\"");

builder.AppendLine("const char* hfcr_type[hfcr_type_max] = {";
foreach(string type in types)
{
    builder.AppendLine("{ " + type + "},");
}
builder.AppendLine("};");

//const char* hfcr_colour_name[hfcr_type_max][hfcr_colour_max] = {
//    {
//        "gray000",
//		"gray010"

//    }
//};
//unsigned char hfcr_colour_r[hfcr_type_max][hfcr_colour_max] = {
//    {
//        0,
//		26

//    }
//};
//unsigned char hfcr_colour_g[hfcr_type_max][hfcr_colour_max] = {
//    {
//        0,
//		26

//    }
//};
//unsigned char hfcr_colour_b[hfcr_type_max][hfcr_colour_max] = {
//    {
//        0,
//		26

//    }
//};


#endif
