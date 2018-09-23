#include "bmp.h"
#include "read_bmp.h"
#include "info_bmp.h"
#include "hc595.h"
#include "p18cxxx.h"
#include <p18f4520.h>




void read_bmp(void){
output_oe_disable();

INFO_BMP my_info_bmp;

my_info_bmp=read_info_bmp((void *)&bmp);
load_clear();
while(1)load_col_bmp((void *)&bmp,my_info_bmp);
}


void read_bmp_start(void){
output_oe_disable();

INFO_BMP my_info_bmp;

my_info_bmp=read_info_bmp((void *)&start);
load_clear();
while(1)load_col_bmp((void *)&start,my_info_bmp);
}