#include <16F877a.h>
#include <DEF877A.H>  
#fuses hs, nowdt, noprotect, nolvp, put, brownout
#use delay(clock=20000000)//Dung thach anh 20Mhz
#use i2c(Master,Fast=100000, sda=PIN_C4, scl=PIN_C3,force_sw)
#use rs232(baud=9600,parity=N,xmit=PIN_C6, rcv=PIN_C7,bits=8)
#include <i2c_Flex_LCD.c>
char chuoi; 
int i;
#int_rda
void serial_isr()
{
   chuoi=getc();
   putc(chuoi);
   i=1;   
}
void main() {
   lcd_init(0x4E,16,2);  //khoi dong lcd dia chi 0x4E
   lcd_backlight_led(ON); //bat led nen lcd
   enable_interrupts(global);
   enable_interrupts(int_rda);
while(1) 
  {
   if(i==1)
      { 
        i=0; 
        printf(lcd_putc,"%c",chuoi); 
      }  
  }
}
