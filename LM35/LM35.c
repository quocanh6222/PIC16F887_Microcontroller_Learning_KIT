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
Set_ADC_channel (0); //Chon chan A3 doc gia tri
Delay_us(10); //Delay 10us thi moi su dung duoc ham read_ADC

while(true)
{
adc = read_adc(); //Doc gia tri ADC v� gan vao bien ADC
float vol = adc*5.0/1024.0;
float temp = vol*100.0;
lcd_gotoxy(1, 1);
delay_ms(100);
printf(lcd_putc,"DO NHIET DO LM35");
lcd_gotoxy(6, 2);
printf(lcd_putc,"%.2f", temp);
delay_ms(1000);
} }
