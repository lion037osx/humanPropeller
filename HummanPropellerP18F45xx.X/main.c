/*
 * File:   main.c
 *
 * Created on August 20, 2018, 16:00 PM
 */

#include "p18cxxx.h"
#include <p18f4520.h>
#include <timers.h>
#include <delays.h>
#include <GenericTypeDefs.h>
#include "read_bmp.h"
#include "uart_output.h"

#pragma config OSC = HS, FCMEN = OFF, IESO = OFF                       // CONFIG1H
#pragma config PWRT = OFF, BOREN = OFF, BORV = 0                        // CONFIG2L
#pragma config WDT = OFF, WDTPS = 32768                                    // CONFIG2H
#pragma config MCLRE = ON, LPT1OSC = OFF, PBADEN = OFF, CCP2MX = PORTC       // CONFIG3H
#pragma config STVREN = ON, LVP = OFF, XINST = OFF							      // CONFIG4L
#pragma config CP0 = OFF, CP1 = OFF, CP2 = OFF, CP3 = OFF                   // CONFIG5L
#pragma config CPB = OFF, CPD = OFF                                         // CONFIG5H
#pragma config WRT0 = OFF, WRT1 = OFF, WRT2 = OFF, WRT3 = OFF                // CONFIG6L
#pragma config WRTB = OFF, WRTC = OFF, WRTD = OFF                            // CONFIG6H
#pragma config EBTR0 = OFF, EBTR1 = OFF, EBTR2 = OFF, EBTR3 = OFF           // CONFIG7L
#pragma config EBTRB = OFF                                                   // CONFIG7H

void ConfigPorts(void);

 
void main(void) {
ConfigPorts();
UARTInit();
Delay1KTCYx(10000);
//UART_String("my source code\r\n");
UART_String(".");




if(PORTBbits.RB5==0)
    {
        UART_String("Start \r\n");  
        UART_String("LATBbits.LATB5\r\n");    
        read_bmp_start();
    }

//    if(PORTBbits.RB4==0)
else{
        UART_String("City Night\r\n");  
        UART_String("LATBbits.LATB4\r\n");  
        read_bmp();
    }

return;
}


void ConfigPorts(void){
TRISA = 0;
TRISB = 0b00110000;
//TRISB = 0;
TRISC = 0;
TRISD = 0;
TRISE = 0;
PORTA=PORTB=PORTC=PORTD=PORTE= 0x00;
//PORTB=0b00110000;
}


 
 /*
    BYTE *bmp ;
   
    bmp=(void *)&table;
  
  */