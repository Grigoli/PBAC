/*
 * This project can be used as Password based access control system 
 * AVR Atmega328P board used. LED on the board demonstrates states of the program, for alarm it has attached speaker and with PWM generates alarm beep.
 * When LED blinking the system waits user to set a password
 * After the password is set, LED stays ON and waits for the correct password input
 * If the password is correct, LED turns OFF for 3 sec and then back to ON
 * Entering incorrect password several times makes alarm trigger.
 * Created: 12/7/2017 2:15:22 PM
 * Author : Grigoli Vashakidze
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include <avr/interrupt.h>


// Variables to store password and count for incorrect entered password
char password [4] = "E";
int count = 0;

// Port initialize
void PORT_Init (void)
{

	// 2-5 Output
	DDRD  |= (1<<PORTB0) | (1<<PORTB1) |(1<<PORTB2) |(1<<PORTB3) ;
	// D ports 6-7 Input
	DDRD  &= ~((1<<PORTD4) | (1<<PORTD5) | (1<<PORTD6) | (1<<PORTD7)); 
	
}

// Returns character pressed
char IsPressed(void)
{
	char Outputs[4] = {PORTD3,PORTD2,PORTD1,PORTD0}; // out
	char keys[4][4] = {"123A", "456B", "789C", "*0#D"};
	
	volatile int c,r;
	for( c = 0; c < 4; c++){
		PORTD = 0xFF; //set D ports to 1
		PORTD &= ~(1<<Outputs[c]); // set ports from Output to 0 one by one
		_delay_ms(10); // delay 10 ms
		if((PIND & (1 << PIND7)) == 0) return keys[0][c]; // check if D7 is low
		if((PIND & (1 << PIND6)) == 0) return keys[1][c]; // check if D6 is low
		if((PIND & (1 << PIND5)) == 0) return keys[2][c]; // check if D5 is low
		if((PIND & (1 << PIND4)) == 0) return keys[3][c]; // check if D4 is low
	}
	
	return '\0';

}



// Checks if user input characters match password, it there is a match turns off LED
void checkPassword(){
 count=count+1;
	if(IsPressed()==password[0]){
	while (IsPressed()){}
	while (IsPressed()=='\0'){}
		if(IsPressed()==password[1]){
		while (IsPressed()){}
		while (IsPressed()=='\0'){}
			if(IsPressed()==password[2]){
			while (IsPressed()){}
			while (IsPressed()=='\0'){}
				if(IsPressed()==password[3]){
				//Turns of LED if the password input is correct
				PORTB &=  ~(1<<PORTB5);
				count = 0;
				_delay_ms(3000); // Wait for 3000ms and put back LED on
				PORTB |=  (1<<PORTB5);

				}else{
	}
			}else{
	}
		}else{
	}
	}else{
	
	}

}

//Sets user input password
void setPassword(){
if(IsPressed()){
	password[0]=IsPressed();
	while (IsPressed()){}
	while (IsPressed()=='\0'){}
		if(IsPressed()){
		password[1]=IsPressed();
		while (IsPressed()){}
		while (IsPressed()=='\0'){}
			if(IsPressed()){
			password[2]=IsPressed();
			while (IsPressed()){}
			while (IsPressed()=='\0'){}
				if(IsPressed()){
				password[3]=IsPressed();
				// Turns on LED to indicate the password is set and the system is ready 
				PORTB |=  (1<<PORTB5);
				_delay_ms(100);
				}
			}
		}
	}
}

//resets password to Empty
void resetPassword(){
		password[0] = 'E';
		password[1] = ' ';
		password[2] = ' ';
		password[3] = ' ';
		_delay_ms(100);
}


// alarm Beep sound
void alarm(){
	// set PWM to beep alarm
	for(int x =0; x<7;x++)
	{
   OCR1A = 500;
   _delay_ms(500);
   OCR1A = 0;
    _delay_ms(500);
   
	  
	}
}


int main(void)
{

	// Timer/Counter to alarm sound
	DDRB |= (1 << DDB1);// Set pin B1 as output
	TCCR1A |= (1 << COM1A1);// non-inverting
	TCCR1A |= (1 << WGM11) | (1 << WGM10); //10-bit phase corrected PWM 
	TCCR1B |= (1 << CS11);//  Prescaler to 8 

	
	while(1){

		PORT_Init();

		//By clicking button on AVR resets the password
		if(!(PINB & (1<<PINB7))){
		resetPassword();
		}
		
		//Checks if password is not set allows user to set a password, if password is already set continually checks for correct password
		if (password[0]=='E')
		{
		// Flashes LED to indicate ready to set password
		PORTB |=  (1<<PORTB5);
		_delay_ms(500);
		PORTB &=  ~(1<<PORTB5);
		setPassword();
		}else{
		if (IsPressed())
		{
		checkPassword();
		if (count==100)
		{
		alarm();
		count=0;
		}
		}
		}

		
	}
	
}
