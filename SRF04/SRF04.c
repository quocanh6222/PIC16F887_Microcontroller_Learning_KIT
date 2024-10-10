#include <16F887.h>
#include <def_887.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=20000000)
#use i2c(Master,Fast=100000, sda=PIN_C4, scl=PIN_C3,force_sw)
#include <i2c_Flex_LCD.c>
#define PIN_TRIGGER PIN_A2
int1 echo = 0;
int16 value = 0;
void Trigger()
{
output_high(PIN_TRIGGER);
delay_us(12);
output_low(PIN_TRIGGER);
}
#int_CCP1
void CCP1_isr(void)
{
if(echo == 1)
{
setup_ccp1(CCP_CAPTURE_FE); // falling fulse
set_timer1(0);
echo = 0;
}
else
{
setup_ccp1(CCP_CAPTURE_RE); // rising fulse
value = CCP_1;
echo = 1;
}
}
void main()
{
lcd_init(0x4E,16,2);  //khoi dong lcd dia chi 0x4E
lcd_backlight_led(ON); //bat led nen lcd

setup_adc_ports(NO_ANALOGS);
setup_timer_1(T1_INTERNAL|T1_DIV_BY_4);
setup_ccp1(CCP_CAPTURE_RE); // raising fulse
enable_interrupts(INT_CCP1);
enable_interrupts(GLOBAL);
float distance = 0;
while(TRUE)
{
Trigger();
while(echo == 0)
{}
distance = value * 0.8 / 58;
      lcd_clear();
      lcd_gotoxy(5, 1);
      delay_ms(10);
      printf(lcd_putc,"DISTANCE");
      lcd_gotoxy(6, 2);
      printf(lcd_putc, "%fcm", distance);

delay_ms(400);
}
}




