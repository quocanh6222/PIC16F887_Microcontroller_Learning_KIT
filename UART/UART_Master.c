#include <16F887.h>
#include <def_887.h>
#FUSES NOWDT, HS, PUT, NOPROTECT,
#use i2c(Master, sda = PIN_C4, scl=PIN_C3) //Khai bao dung I2C
#use DELAY(clock=20000000)
#use rs232(baud=9600,xmit=pin_c6,rcv=pin_c7) 
int16 temp; //Bien temp luu gia tri nhiet do
//int16 a = 230;
void main()
{
while(true){
delay_ms(100);
i2c_start(); //Bat dau qua trinh giao tiep
i2c_write(0x90); //Dia chi cua TC74
i2c_write(0x00); //Bat dau doc
i2c_start();
i2c_write(0x91); //Truy xuat gia tri nhiet do
temp = i2c_read(0); //Bat dau qua trinh doc va gan bao bien temp
i2c_stop(); //Ket thuc qua trinh doc

putc(temp);   
DELAY_MS(100);
}
}


/*
#include <16F887.h>
#include <def_887.h>
#device *=16 ADC=10 //Khai bao dung bo ADC 10bit
#FUSES NOWDT, HS, PUT, NOPROTECT,
#use DELAY(clock=20000000)
#use rs232(baud=9600,xmit=pin_c6,rcv=pin_c7) 
int16 adc; //Bien luu gia tri ADC doc duoc
int16 a = 230;
void main()
{
setup_adc(adc_clock_internal); //Thoi gian lay mau = xung clock IC
//setup_adc_ports(AN3);
Set_ADC_channel (3); //Chon chan A3 doc gia tri
Delay_us(10); //Delay 10us thi moi su dung duoc ham read_ADC

while(true){
adc = read_adc(); //Doc gia tri ADC và gan vao bien ADC
printf("%lu", adc);   
DELAY_MS(100);
}
}
*/
