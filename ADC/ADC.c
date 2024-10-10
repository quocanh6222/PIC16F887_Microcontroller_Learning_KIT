#include <16F887.h>
#include <def_887.h>
#device *=16 ADC=10 //Khai bao dung bo ADC 10bit
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=20000000)
#use i2c(Master,Fast=100000, sda=PIN_C4, scl=PIN_C3,force_sw)
#include <i2c_Flex_LCD.c>
Int16 adc; //Bien luu gia tri ADC doc duoc
void main()
{

lcd_init(0x4E,16,2);  //khoi dong lcd dia chi 0x4E
lcd_backlight_led(ON); //bat led nen lcd
setup_adc(adc_clock_internal); //Thoi gian lay mau bang xung clock IC
Set_ADC_channel (3); //Chon chan A3 doc gia tri
Delay_us(10); //Delay 10us thi moi su dung duoc ham read_ADC

while(true)
{
adc = read_adc(); //Doc gia tri ADC và gan vao bien ADC
lcd_gotoxy(1, 1);
delay_ms(100);
printf(lcd_putc,"VALUE ADC:");
lcd_gotoxy(1, 2);
printf(lcd_putc,"%04Lu " , adc );
delay_ms(100);
} }
