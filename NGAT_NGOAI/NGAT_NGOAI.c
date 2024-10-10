#include <16F877a.h>
#include <DEF877A.H>
#FUSES NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP,NOCPD, NOWRT
#use delay(clock=20000000)
#use i2c(Master,Fast=100000, sda=PIN_C4, scl=PIN_C3,force_sw)
#include <i2c_Flex_LCD.c>

int16 gt=0;

#int_ext
ext_isr()
{
gt++;
delay_ms(200);
}

void main() {
   lcd_init(0x4E,16,2);  //khoi dong lcd dia chi 0x4E
   lcd_backlight_led(ON); //bat led nen lcd

   trisb = 0xff;
   Port_B_pullups (1 );
   enable_interrupts(int_EXT);
   ext_int_edge(H_TO_L);
   enable_interrupts(GLOBAL);
   
while (1) {
   lcd_gotoxy(1, 1);
   printf(lcd_putc "SO LAN NHAN B0");
   lcd_gotoxy(1, 2);
   printf(lcd_putc "%Lu", gt);
   delay_ms(200);
}
}
