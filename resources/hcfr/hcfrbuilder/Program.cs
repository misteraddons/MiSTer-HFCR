using hcfrbuilder;
using System.Drawing;
using System.Text;

string sourcePath = "C:\\repos\\Aznable\\resources\\hcfr";

int type_max = 0;
int colour_max = 0;

List<string> types = new List<string>();
List<string> whitepoints = new List<string>();
List<List<ColourEntry>> colours = new List<List<ColourEntry>>();
foreach (var file in Directory.GetFiles(sourcePath, "*.csv"))
{
    colour_max = 0;
    string[] name = Path.GetFileNameWithoutExtension(file).Split("_", StringSplitOptions.RemoveEmptyEntries);

    types.Add(name[name.Length-2].ToUpper());
    whitepoints.Add(name[name.Length-1].ToUpper());
    type_max++;
    string[] lines = File.ReadAllLines(file);
    bool isHeader = true;
    colours.Add(new List<ColourEntry>());
    foreach (string line in lines)
    {
        if (isHeader) { isHeader = false; continue; }
        
        ColourEntry colour = new ColourEntry();
        string[] cells = line.Split(',');
        colour.Name = cells[0];
        colour.R = int.Parse(cells[1]);
        colour.G = int.Parse(cells[2]);
        colour.B = int.Parse(cells[3]);
        colours[type_max-1].Add(colour);
        colour_max++;
    }
}

StringBuilder builder = new StringBuilder();
builder.AppendLine("#ifndef hcfr_DATA_H");
builder.AppendLine("#define hcfr_DATA_H");
builder.AppendLine();
builder.AppendLine("#define hcfr_type_max " + type_max);
builder.AppendLine("#define hcfr_colour_max " + colour_max);
builder.AppendLine("extern const char *hcfr_type[hcfr_type_max];");
builder.AppendLine("extern const char *hcfr_wp[hcfr_type_max];");
builder.AppendLine("extern const char *hcfr_colour_name[hcfr_type_max][hcfr_colour_max];");
builder.AppendLine("extern unsigned char hcfr_colour_r[hcfr_type_max][hcfr_colour_max];");
builder.AppendLine("extern unsigned char hcfr_colour_g[hcfr_type_max][hcfr_colour_max];");
builder.AppendLine("extern unsigned char hcfr_colour_b[hcfr_type_max][hcfr_colour_max];");
builder.AppendLine();
builder.AppendLine("#endif");

File.WriteAllText("C:\\repos\\Aznable\\src\\hcfr\\hcfr_data.h", builder.ToString());

builder.Clear();
builder.AppendLine("#ifndef hcfr_DATA_C");
builder.AppendLine("#define hcfr_DATA_C");
builder.AppendLine("#include \"hcfr_data.h\"");
builder.AppendLine();

builder.AppendLine("const char *hcfr_type[hcfr_type_max] = {");
for (int t = 0; t < types.Count; t++)
{
    builder.Append("\t\"" + types[t] + "\"");
    if (t < types.Count - 1) { builder.Append(","); }
    builder.AppendLine();
}
builder.AppendLine("};");
builder.AppendLine("const char *hcfr_wp[hcfr_type_max] = {");
for (int t = 0; t < types.Count; t++)
{
    builder.Append("\t\"" + whitepoints[t] + "\"");
    if (t < types.Count - 1) { builder.Append(","); }
    builder.AppendLine();
}
builder.AppendLine("};");
StringBuilder name_builder = new StringBuilder();
StringBuilder r_builder = new StringBuilder();
StringBuilder g_builder = new StringBuilder();
StringBuilder b_builder = new StringBuilder();
List<StringBuilder> all = new List<StringBuilder>()
{
    name_builder, r_builder,g_builder,b_builder
};
name_builder.AppendLine("const char *hcfr_colour_name[hcfr_type_max][hcfr_colour_max] = {");
r_builder.AppendLine("unsigned char hcfr_colour_r[hcfr_type_max][hcfr_colour_max] = {");
g_builder.AppendLine("unsigned char hcfr_colour_g[hcfr_type_max][hcfr_colour_max] = {");
b_builder.AppendLine("unsigned char hcfr_colour_b[hcfr_type_max][hcfr_colour_max] = {");
for (int t = 0; t < types.Count; t++)
{
    foreach (var sb in all) { sb.Append("\t{ "); }
    for (int c = 0; c < colour_max; c++)
    {
        name_builder.Append("\"" + colours[t][c].Name + "\"");
        r_builder.Append(colours[t][c].R + "");
        g_builder.Append(colours[t][c].G + "");
        b_builder.Append(colours[t][c].B + "");
        if (c < colour_max - 1)
        {
            foreach (var sb in all) { sb.Append(","); }
        }
    }
    foreach (var sb in all) { sb.Append("\t}"); }
    if (t < types.Count - 1)
    {
        foreach (var sb in all) { sb.Append(","); }
    }
    foreach (var sb in all) { sb.AppendLine(); }
}
foreach (var sb in all) { sb.AppendLine("};"); builder.Append(sb.ToString()); }

builder.AppendLine();
builder.AppendLine("#endif");


File.WriteAllText("C:\\repos\\Aznable\\src\\hcfr\\hcfr_data.c", builder.ToString());

