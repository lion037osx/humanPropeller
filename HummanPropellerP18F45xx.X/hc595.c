/*
 * File:   hc595.c
 * Author: optimus
 *
 * Created on August 20, 2018, 5:47 PM
 */

#include <p18f4620.h>
#include "hc595.h"
#include "file.h"
#include <delays.h>
#include <GenericTypeDefs.h>
//#include "bmp.h"


#define time_space() Delay1TCYx(1)

//extern unsigned char *bmp;


void hc595_funcion_str(){
    output_str_low();
    //time_space();
    Delay1TCYx(100);
    output_str_high();
    //time_space();
    Delay1TCYx(100);
}

void hc595_x(unsigned char ui8_tmp ) 
{
unsigned int i=0;
unsigned int c=8;
    while(c--)
	{
		output_clk_low();
        if(((ui8_tmp>>c )&0x1)== 1){
            output_dat_low();
        }
        else{                        
            output_dat_high();
        }        
        time_space();
		output_clk_high();
        time_space();
        i++; 
	}	
}


void load_col_bmp(unsigned char *p_bmp,INFO_BMP tmp_info_bmp){        
UINT16 n_bytes=0;
//UINT16 n_ic_tmp=N_IC_74HC595;
UINT16 n_ic_tmp=(tmp_info_bmp.high/8);
UINT16 counter_bytes=0 ;

const UINT16 height_bmp=(tmp_info_bmp.high);//120


n_bytes=tmp_info_bmp.n_headers_bmp;

while(n_bytes--){
*p_bmp++;
}


n_bytes=tmp_info_bmp.n_headers_bmp;
    
 //   while(n_bytes  < SIZE_BMP){           
    while(n_bytes  < tmp_info_bmp.size){   
        while(n_ic_tmp)
            {            
                hc595_x(*p_bmp++);
                counter_bytes++;
                n_ic_tmp--;
            }
        //n_ic_tmp=N_IC_74HC595;
        n_ic_tmp=(tmp_info_bmp.high/8);
        hc595_funcion_str();
        output_oe_enable();
        Delay1TCYx(1000);
        output_oe_disable();
        Delay1TCYx(4);
        
        //Delay1KTCYx(400);
      //  if(counter_bytes >= (SIZE_BMP*N_IC_74HC595))counter_bytes=0;
       // n_bytes=n_bytes+N_IC_74HC595;
          if(counter_bytes >= (tmp_info_bmp.size*(tmp_info_bmp.high/8)))counter_bytes=0;
        n_bytes=n_bytes+(tmp_info_bmp.high/8);
    }    
    LATAbits.LATA1=~LATAbits.LATA1;
    n_bytes=0;
}

void load_clear(void){    
    int dec=COLUMN_HEIGHT;
    output_oe_disable();
    while(dec--)hc595_x(0x00);                          
    hc595_funcion_str();
    output_oe_enable();
}
 