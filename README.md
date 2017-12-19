# Password Based Access Control

<a href="https://ibb.co/dHXRN6"><img src="https://preview.ibb.co/iZuvFR/25189812_2218856314807079_671666085_o.jpg" alt="25189812_2218856314807079_671666085_o" border="0"></a>

## Description

The project works like password based access control system. When the system is booted the LED is flashing that indicates the password is not set and waits for the user to input 4 characters. After the user has set the password, system stops flashing LED and turns it on to indicate the password is set and waits user to input correct password to unlock the system. When the user enters correct password the system unlocks, LED goes off and turns back after 3 seconds. The user can reset the system using the button located on the board. When the button is pushed the system goes into password set mode.

The system also has security feature that protects from entering many incorrect combinations. After few incorrect tries the system triggers alarm and starts to flash LED.


## Materials used:

ATmega328P - The Atmel picoPower ATmega328P, low-power CMOS 8-bit microcontroller based on the AVR enhanced RISC architecture. using I/O:

switch keypad 16 key 0.005a 12v,

## Instructions for user:

When LED is flashing user should input 4 character password.

When LED is on, the system waits user to input correct password.

When LED is off the system is unlocked.

To reset the system user should click a button on the board.

Entering incorrect passwords in a row will cause alarm to trigger.

## Work done:

Time spent on the project: 22 hours.

Tools user: The Atmel picoPower ATmega328P,

Atmel studio, C language

## Video demo:

https://www.youtube.com/watch?v=e2utw0sj7Iw&feature=share
