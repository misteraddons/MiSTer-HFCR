#ifndef HFCR_DATA_C
#define HFCR_DATA_C
#include "hfcr_data.h"

const char *hfcr_type[hfcr_type_max] = {
	"rec601___d65"
};
const char *hfcr_colour_name[hfcr_type_max][hfcr_colour_max] = {
	{
		"gray000",
		"gray010"
	}
};
unsigned char hfcr_colour_r[hfcr_type_max][hfcr_colour_max] = {
	{
		0,
		26
	}
};
unsigned char hfcr_colour_g[hfcr_type_max][hfcr_colour_max] = {
	{
		0,
		26
	}
};
unsigned char hfcr_colour_b[hfcr_type_max][hfcr_colour_max] = {
	{
		0,
		26
	}
};
#endif
