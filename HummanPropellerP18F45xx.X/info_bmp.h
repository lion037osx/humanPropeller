#include <GenericTypeDefs.h>

typedef struct{
    UINT16  n_bits;
    UINT16 width;
    UINT16 high;
    UINT16 size;
    UINT8 n_headers_bmp;
}INFO_BMP;


INFO_BMP read_info_bmp(unsigned char *);


UINT16 r_width(unsigned char *);

UINT16 r_high(unsigned char *);

UINT16 r_n_bits(unsigned char *);

UINT16 r_size(unsigned char *);
