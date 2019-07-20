#include"port.h"
#include"dio.h"
#include"lcd.h"

 void SystemInit(){}
 int  main(){
	 uint32_t count =0;
	 uint8_t flag_dec = 0,x=0;
	 uint8_t flag_reset = 0;
	 Port_Init(0);
	 	LCD_init();
	 Port_SetPinDirection(0,0x1C,PORT_PIN_OUT);
	 GPIO_PORTA_DATA_R = 0x1C;
	 Port_SetPinDirection(0,0x1C,PORT_PIN_IN);
	 Port_SetPinPullUp(0,0x1C,1);
   LCD_displayStringRowColumn(0 ,0 , "Count is ");
   while(1)
	 {
		 x=0;
		 if(DIO_ReadPort(0,0x04)==0)
		 {
			 _delay_ms(200);
			 if(DIO_ReadPort(0,0x04)==0)
			 {
				 if(count<999)
				 {
					 count++;
				 x=1;
				 }
			 }
		 }
		 else if(DIO_ReadPort(0,0x08)==0)
		 {
			 if(flag_dec==0)
			 {
				if(count > 0){
					count--;
					x=1;
					if(count == 9)
							  LCD_displayStringRowColumn(0,10 ," ");
					else if(count==99)
							  LCD_displayStringRowColumn(0,11, " ");

				}
				flag_dec=1;
			 }
			 _delay_ms(200);
		 }
		 else if(DIO_ReadPort(0,0x08)!=0&&flag_dec==1){
			 flag_dec = 0;
		 }
		 else if(DIO_ReadPort(0,0x10)==0)
		 {
			 flag_reset =1;
		 }
		 else if(DIO_ReadPort(0,0x10)!=0 && flag_reset ==1)
		 {
			 count=0;			 
			 x=1;
			 flag_reset = 0;
			 LCD_displayStringRowColumn(0 , 9 ,"   ");
		 }    
		 if(x==1){
	 		 	 		 LCD_intgerToString(count);
		 }			 

	 }	
 }