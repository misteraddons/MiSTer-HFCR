#ifndef HFCR_DATA_H
#define HFCR_DATA_H

#define hfcr_type_max 1
#define hfcr_colour_max 2
extern const char *hfcr_type[hfcr_type_max];
extern const char *hfcr_colour_name[hfcr_type_max][hfcr_colour_max];
extern unsigned char hfcr_colour_r[hfcr_type_max][hfcr_colour_max];
extern unsigned char hfcr_colour_g[hfcr_type_max][hfcr_colour_max];
extern unsigned char hfcr_colour_b[hfcr_type_max][hfcr_colour_max];

#endif
