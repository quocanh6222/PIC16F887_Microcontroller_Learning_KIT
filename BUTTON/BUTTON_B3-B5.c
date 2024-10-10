#include <16F887.h>
#include <def_887.h>
#FUSES NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP,NOCPD, NOWRT
#use delay(clock=20000000)
#use i2c(Master,Fast=100000, sda=PIN_C4, scl=PIN_C3,force_sw)
#include <i2c_Flex_LCD.c>

int16 gtB1=0, gtB2=0, gtB3=0, gtB4=0, gtB5=0;

void main() {
   lcd_init(0x4E,16,2);  //khoi dong lcd dia chi 0x4E
   lcd_backlight_led(ON); //bat led nen lcd
   trise = 0x00;
   trisb = 0xff; //port B la input
   portb = 0x00;
   porte = 0x00;
   OPTION_REG = 0b00000000;//clear thanh ghi option_reg

while (1) {
   if(Input(PIN_B1)==0){
   gtB1++;
   }
   if(Input(PIN_B2)==0){
   gtB2++;
   }
   if(Input(PIN_B3)==0){
   gtB3++;
   }
   if(Input(PIN_B4)==0){
   gtB4++;
   }
   if(Input(PIN_B5)==0){
   gtB5++;
   }
   lcd_clear();
   lcd_gotoxy(1, 1);
   printf(lcd_putc "B1 B2 B3 B4 B5");
   lcd_gotoxy(1, 2);  
   printf(lcd_putc "%Lu", gtB1);
   lcd_gotoxy(4, 2);  
   printf(lcd_putc "%Lu", gtB2);
   lcd_gotoxy(7, 2);  
   printf(lcd_putc "%Lu", gtB3);
   lcd_gotoxy(10, 2);  
   printf(lcd_putc "%Lu", gtB4);
   lcd_gotoxy(13, 2);  
   printf(lcd_putc "%Lu", gtB5);
   delay_ms(150);
}
}
