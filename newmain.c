#include <xc.h>
#include "configuracio.h"
#include <string.h>
#include <stdio.h>
#define _XTAL_FREQ 8000000

void UART_init(){
    OSCCON= 0b01110100;
    TRISCbits.RC7 = 1;      //RX input
    TRISCbits.RC6 = 0;      //TX output 
    TXSTAbits.SYNC = 0;     //UART 
    TXSTAbits.BRGH = 1;     //alta velocitat 
    TXSTAbits.TXEN = 1;     //TX on
    BAUDCONbits.BRG16 =1; 
    SPBRG = 207;             //9600 a 8MHZ
    RCSTAbits.SPEN = 1;     //UART on   
    RCSTAbits.CREN = 1;     //RX on
}
void numread(){
char a = UART_Read();
       while(!TXSTAbits.TRMT);
       char b = UART_Read();
       while(!TXSTAbits.TRMT);
       char c = UART_Read();
       int num = b - '0';
}
char UART_Read()
{
 
  while(!PIR1bits.RCIF);
  return RCREG;
}
void main(void) {
    TRISAbits.RA0=0;
    PORTA=0x00;
    LATAbits.LATA0=0;
    UART_init();
    while(1)
    numread();
    {
       char a = UART_Read();
       while(!TXSTAbits.TRMT);
       char b = UART_Read();
       while(!TXSTAbits.TRMT);
       char c = UART_Read();
       int num = b - '0';
       if(num >= 2)
       {
           LATAbits.LATA0=1;
           __delay_ms(500);
           LATAbits.LATA0=0;
       }
        if(a=='1' && b =='0' && c =='0')
       {
            LATAbits.LATA0=1;
           __delay_ms(500);
           LATAbits.LATA0=0;
       }    
    }
    return;
}
