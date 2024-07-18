/*
 * EVM.c
 *
 * Created: 16/07/2023 08:47:49 م
 *  Author: Alaa Mohamed
 */ 


#define  F_CPU 8000000UL
#include <util/delay.h>
#include "BUTTON.h"
#include "LCD.h"

unsigned char counterA = 0;
unsigned char counterB = 0;
unsigned char counterC = 0;
unsigned char counterD = 0;
void Reset_Voting();

int main(void)
{
    LCD_Initialize();
	ButtonInitialize('B',3);
	ButtonInitialize('B',4);
	ButtonInitialize('B',5);
	ButtonInitialize('B',6);
	ButtonInitialize('B',7);
	LCD_SendString("A=0");
	LCD_MoveCursor(1,12);
	LCD_SendString("B=0");
	LCD_MoveCursor(2,1);
	LCD_SendString("C=0");
	LCD_MoveCursor(2,12);
	LCD_SendString("D=0");
	while(1)
    {
         if(ButtonRead('B',3)==1)
		 {
			 counterA++;
			 LCD_MoveCursor(1,3);
			 if (counterA<10)
			 {
				 LCD_SendCharacter(counterA+48);
			 }
			 else if(counterA<100)
			 {
				 LCD_SendCharacter((counterA/10)+48);
				 LCD_SendCharacter((counterA%10)+48);
			 }  
		 }	
		 else if(ButtonRead('B',4)==1)
		 {
			 counterB++;
			 LCD_MoveCursor(1,14);
			 if (counterB<10)
			 {
				 LCD_SendCharacter(counterB+48);
			 }
			 else if(counterB<100)
			 {
				 LCD_SendCharacter((counterB/10)+48);
				 LCD_SendCharacter((counterB%10)+48);
			 }
		 }
		 else if(ButtonRead('B',5)==1)
		 {
			 counterC++;
			 LCD_MoveCursor(2,3);
			 if (counterC<10)
			 {
				 LCD_SendCharacter(counterC+48);
			 }
			 else if(counterC<100)
			 {
				 LCD_SendCharacter((counterC/10)+48);
				 LCD_SendCharacter((counterC%10)+48);
			 }
		 }
		 else if(ButtonRead('B',6)==1)
		 {
			 counterD++;
			 LCD_MoveCursor(2,14);
			 if (counterD<10)
			 {
				 LCD_SendCharacter(counterD+48);
			 }
			 else if(counterD<100)
			 {
				 LCD_SendCharacter((counterD/10)+48);
				 LCD_SendCharacter((counterD%10)+48);
			 }
		 }	
		 else if(ButtonRead('B',7)==1)
		 {
			 Reset_Voting();
		 }
		 if(counterA == 99)
		 {
			 LCD_SendCommand(CLEAR_SCREEN);
			 LCD_MoveCursor(1,1);
			 LCD_SendString("CONGRATULATIONS!");
			 LCD_MoveCursor(2,1);
			 LCD_SendString("A is the winner!");
			 _delay_ms(1000);
			 LCD_SendCommand(CLEAR_SCREEN);
			 LCD_MoveCursor(1,1);
			 LCD_SendString("Resetting again");
			 _delay_ms(1000);
			 LCD_SendCommand(CLEAR_SCREEN);
			 Reset_Voting();
		 }
		 if(counterB == 99)
		 {
			 LCD_SendCommand(CLEAR_SCREEN);
			 LCD_MoveCursor(1,1);
			 LCD_SendString("CONGRATULATIONS!");
			 LCD_MoveCursor(2,1);
			 LCD_SendString("B is the winner!");
			 _delay_ms(1000);
			 LCD_SendCommand(CLEAR_SCREEN);
			 LCD_MoveCursor(1,1);
			 LCD_SendString("Resetting again");
			 _delay_ms(1000);
			 LCD_SendCommand(CLEAR_SCREEN);
			 Reset_Voting();
		 }
		 if(counterC == 99)
		 {
			 LCD_SendCommand(CLEAR_SCREEN);
			 LCD_MoveCursor(1,1);
			 LCD_SendString("CONGRATULATIONS!");
			 LCD_MoveCursor(2,1);
			 LCD_SendString("C is the winner!");
			 _delay_ms(1000);
			 LCD_SendCommand(CLEAR_SCREEN);
			 LCD_MoveCursor(1,1);
			 LCD_SendString("Resetting again");
			 _delay_ms(1000);
			 LCD_SendCommand(CLEAR_SCREEN);
			 Reset_Voting();
		 }
		 if(counterD == 99)
		 {
			 LCD_SendCommand(CLEAR_SCREEN);
			 LCD_MoveCursor(1,1);
			 LCD_SendString("CONGRATULATIONS!");
			 LCD_MoveCursor(2,1);
			 LCD_SendString("D is the winner!");
			 _delay_ms(1000);
			 LCD_SendCommand(CLEAR_SCREEN);
			 LCD_MoveCursor(1,1);
			 LCD_SendString("Resetting again");
			 _delay_ms(1000);
			 LCD_SendCommand(CLEAR_SCREEN);
			 Reset_Voting();
		 }
		 _delay_ms(200);	
    }
}

void Reset_Voting()
{
	counterA = 0;
	counterB = 0;
	counterC = 0;
	counterD = 0;
	LCD_MoveCursor(1,1);
	LCD_SendString("A=0");
	LCD_MoveCursor(1,4);
	LCD_SendCharacter(0x20);
	LCD_MoveCursor(1,12);
	LCD_SendString("B=0");
	LCD_MoveCursor(1,15);
	LCD_SendCharacter(0x20);
	LCD_MoveCursor(2,1);
	LCD_SendString("C=0");
	LCD_MoveCursor(2,4);
	LCD_SendCharacter(0x20);
	LCD_MoveCursor(2,12);
	LCD_SendString("D=0");
	LCD_MoveCursor(2,15);
	LCD_SendCharacter(0x20);
	LCD_MoveCursor(1,1);
}