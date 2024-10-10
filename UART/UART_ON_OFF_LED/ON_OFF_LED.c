#include <16f887.h> 
#include <def_887.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=20000000) 
#include <lcd_lib_4bit.c>
#use rs232(baud=115200,xmit=PIN_C6,rcv=PIN_C7) 
char value1;//Bien luu du lieu
#int_RDA //Ngat RDA dung cho RS232
void RDA_interrupt(){ 
value1 = getc();//Doc cac ky tu nhan duoc va gan vao bien valuel
if (value1=='b')//Neu ky tu doc duoc la b thi port e muc 1
   PORTe=0xff; 
if (value1=='t')//Neu ky tu doc duoc la b thi port e muc 0
   PORTe=0x00;
}
void main()
{
trise=0x00; //Port E output
ENABLE_INTERRUPTS(INT_RDA);//Cho phep ngat hoat dong
enable_interrupts(GLOBAL);//bit cho phep ngat toan cuc (1)
while (1){
}
}
