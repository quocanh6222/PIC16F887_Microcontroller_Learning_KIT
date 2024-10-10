#include <16f877.h>
#include <def_877a.h>
#fuses NOWDT, HS, NOPUT, NOPROTECT, NODEBUG
#use delay(clock=20000000)

void main(){
   trisE = 0x00;
   portE = 0xff;
   trisA = 0x00;
   portA = 0xff;
   while(1){
   output_high(PIN_A4); 
   output_high(PIN_A5);
   output_high(PIN_E0); 
   output_high(PIN_E1);
   output_high(PIN_E2);
   delay_ms(200);
   output_LOW(PIN_A4); 
   output_LOW(PIN_A5);
   output_LOW(PIN_E0); 
   output_LOW(PIN_E1);
   output_LOW(PIN_E2);
   delay_ms(200); 
   }
}


