#include <16F887.h>
#include <def_887.h>
#FUSES PUT,HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=20M)
#use i2c(Master,Fast=100000, sda=PIN_C4, scl=PIN_C3,force_sw)
#include <i2c_Flex_LCD.c>

void main()
{
   lcd_init(0x4E,16,2);  //khoi dong lcd dia chi 0x4E
   lcd_backlight_led(ON); //bat led nen lcd
   set_tris_B(0x00);
   while(TRUE)
   {
      lcd_clear();
      lcd_gotoxy(1, 1);
      printf(lcd_putc, "NGUYEN QUOC ANH");
      lcd_gotoxy(1, 2);
      printf(lcd_putc, "LE VI KHANG");
      delay_ms(100);
   }
}
