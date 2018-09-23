#include "bmp.h"
#include "info_bmp.h"
#include "uart_output.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <GenericTypeDefs.h>
#define N_BYTES_HEADER 10


INFO_BMP read_info_bmp(unsigned char *p_bmp){
    
    INFO_BMP my_bmp;
    UINT16 tmp;
    char my_string_tmp[16];
    my_bmp.n_headers_bmp=N_BYTES_HEADER;
        my_bmp.n_bits=*p_bmp<<8;
        p_bmp++;
        my_bmp.n_bits|=*p_bmp;                  
        p_bmp++;
        my_bmp.width=*p_bmp;
        p_bmp++;
        my_bmp.width|=*p_bmp<<8;
        p_bmp++;
        my_bmp.high=*p_bmp;
        p_bmp++;
        my_bmp.high|=*p_bmp<<8;                
        //my_bmp.size=(UINT16 )((int)(strlen(p_bmp)))+1;
        
        my_bmp.size=((my_bmp.high/8)*my_bmp.width) + N_BYTES_HEADER;
        
        p_bmp=0x00;
        sprintf(my_string_tmp,"n bits %u\r\n",my_bmp.n_bits);        
        UART_String(my_string_tmp);    
        sprintf(my_string_tmp,"width %u\r\n",my_bmp.width);        
        UART_String(my_string_tmp);  
        sprintf(my_string_tmp,"high %u\r\n",my_bmp.high);        
        UART_String(my_string_tmp);  
        sprintf(my_string_tmp,"size %u\r\n",my_bmp.size);        
        UART_String(my_string_tmp);  
        return my_bmp;
}


UINT16 r_width(unsigned char *p_bmp){
    INFO_BMP my_bmp;
    UINT16 tmp;
    char my_string_tmp[16];
    my_bmp.n_bits=((*p_bmp)<<7| (*p_bmp++));
    my_bmp.width=(*p_bmp++) << 7| (*p_bmp++);    
    my_bmp.high=(*p_bmp++ )<<7|( *p_bmp++);
    my_bmp.size=((int)(strlen(p_bmp)))+1;
    sprintf(my_string_tmp,"width %d\r\n",my_bmp.width);        
    UART_String(my_string_tmp); 
    return my_bmp.width;
} 

UINT16 r_high(unsigned char *p_bmp){
    INFO_BMP my_bmp;
    UINT16 tmp;
    char my_string_tmp[16];
    my_bmp.n_bits=((*p_bmp)<<7| (*p_bmp++));
    my_bmp.width=(*p_bmp++) << 7| (*p_bmp++);    
    my_bmp.high=(*p_bmp++ )<<7|( *p_bmp++);
    my_bmp.size=((int)(strlen(p_bmp)))+1;        
    sprintf(my_string_tmp,"width %d\r\n",my_bmp.width);        
    UART_String(my_string_tmp); 
    return my_bmp.high;
} 


UINT16 r_n_bits(unsigned char *p_bmp){
    INFO_BMP my_bmp;
    UINT16 tmp;
    char my_string_tmp[16];
    my_bmp.n_bits=((*p_bmp)<<7| (*p_bmp++));      
    sprintf(my_string_tmp,"n_bits %d\r\n",my_bmp.n_bits);        
    UART_String(my_string_tmp); 
    return my_bmp.n_bits;
} 

UINT16 r_size(unsigned char *p_bmp){
    INFO_BMP my_bmp;
    UINT16 tmp;
    char my_string_tmp[16];
    my_bmp.n_bits=((*p_bmp)<<7| (*p_bmp++));
    my_bmp.width=(*p_bmp++) << 7| (*p_bmp++);    
    my_bmp.high=(*p_bmp++ )<<7|( *p_bmp++);
    my_bmp.size=((int)(strlen(p_bmp)))+1;        
    sprintf(my_string_tmp,"size:%d\r\n",my_bmp.size);        
    UART_String(my_string_tmp); 
    return my_bmp.size;
} 