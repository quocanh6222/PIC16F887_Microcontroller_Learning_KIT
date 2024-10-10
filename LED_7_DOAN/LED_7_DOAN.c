#include <16F887.h>
#include <def_887.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=20000000)
unsigned int8 ma7doan[]= {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
signed int32 i, j;

void main(){
trisc = 0x00;
trisd = 0x00;
while(1)
{
for(i = 0; i<=99; i++){

   for(j = 0; j<25; j++){
      output_high(PIN_C0);
      output_d(ma7doan[i/10]);
      delay_ms(10);
      output_low(PIN_C0); 
      
      output_high(PIN_C1); 
      output_d(ma7doan[i%10]);
      delay_ms(10);  
      output_low(PIN_C1);
   }
}}}
