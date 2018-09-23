#include <GenericTypeDefs.h>

#define output_dat_low()  LATAbits.LATA0=LATCbits.LATC3=0
#define output_dat_high() LATAbits.LATA0=LATCbits.LATC3=1

#define output_clk_low()  LATCbits.LATC4=0
#define output_clk_high() LATCbits.LATC4=1

#define output_str_low()  LATAbits.LATA2=LATCbits.LATC5=0
#define output_str_high() LATAbits.LATA2=LATCbits.LATC5=1

#define output_oe_enable()  LATDbits.LATD0=1
#define output_oe_disable() LATDbits.LATD0=0

#define COLUMN_HEIGHT 120
#define N_IC_74HC595 (120/8)
#define SIZE_BMP 1

#include "info_bmp.h"

void load_clear(void);
void hc595_funcion_str(void);
void load_col_bmp(unsigned char *,INFO_BMP);
