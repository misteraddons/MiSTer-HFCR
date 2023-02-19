#ifndef hcfr_DATA_H
#define hcfr_DATA_H

#define hcfr_type_max 8
#define hcfr_colour_max 83
extern const char *hcfr_type[hcfr_type_max];
extern const char *hcfr_wp[hcfr_type_max];
extern const char *hcfr_colour_name[hcfr_type_max][hcfr_colour_max];
extern unsigned char hcfr_colour_r[hcfr_type_max][hcfr_colour_max];
extern unsigned char hcfr_colour_g[hcfr_type_max][hcfr_colour_max];
extern unsigned char hcfr_colour_b[hcfr_type_max][hcfr_colour_max];

#endif
