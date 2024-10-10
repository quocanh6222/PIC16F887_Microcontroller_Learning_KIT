#include <16F877a.h>
#include <DEF877A.H>
#FUSES NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP,NOCPD, NOWRT
#use delay(clock=20000000)
#use i2c(Master,Fast=100000, sda=PIN_C4, scl=PIN_C3,force_sw)
#include <i2c_Flex_LCD.c>

int16 gtB3=0;

void main() {
   lcd_init(0x4E,16,2);  //khoi dong lcd dia chi 0x4E
   lcd_backlight_led(ON); //bat led nen lcd
   trisa = 0x00000011; //port A la input

while (1){
   if(Input(PIN_A1)==1){
   gtB3++;
   delay_ms(200);
   }
   lcd_gotoxy(1, 1);
   printf(lcd_putc "A3");
   lcd_gotoxy(1, 2);  
   printf(lcd_putc "%Lu", gtB3);
   delay_ms(100);

}
}
