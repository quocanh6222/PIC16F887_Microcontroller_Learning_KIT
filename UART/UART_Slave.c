#include <16f877A.h>
#include <def_877a.h>
#FUSES NOWDT, HS, PUT, NOPROTECT,
#use DELAY(clock=20000000)
#use i2c(Master,Fast=100000, sda=PIN_C4, scl=PIN_C3,force_sw)
#use rs232(baud=9600,xmit=pin_c6,rcv=pin_c7) 
#include <i2c_Flex_LCD.c>

int16 RDATA;

void main()
{
 lcd_init(0x4E,16,2);  //khoi dong lcd dia chi 0x4E
   lcd_backlight_led(ON); //bat led nen lcd
   
while(true)
{ 
   if(kbhit()) 
      { 
      RDATA = getch();   
      lcd_gotoxy(1, 1);
      delay_ms(100);
      printf(lcd_putc, "ADC");
      lcd_gotoxy(1, 2);
      printf(lcd_putc,"%04Lu " , RDATA );
      delay_ms(100);

      }
}
}
