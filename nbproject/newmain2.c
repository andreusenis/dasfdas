#include <xc.h>
#include "configuracio.h"
#include <string.h>
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
void UART_Write(char data)
{
  while(!TXSTAbits.TRMT);
  TXREG = data;
}
void UART_Write_Text(char *text)
{
  int i;
  for(i=0;text[i]!='\0';i++)
	  UART_Write(text[i]);
}

char UART_Read()
{
 
  while(!PIR1bits.RCIF);
  return RCREG;
}
void UART_Read_Text(char *Output, unsigned int length)
{
	unsigned int i;
	for(int i=0;i<length;i++)
		Output[i] = UART_Read();
}
char palabra;
void main(void) 
{
    TRISAbits.RA0=0;
    PORTA=0x00;
    UART_init();
    
    return;
}