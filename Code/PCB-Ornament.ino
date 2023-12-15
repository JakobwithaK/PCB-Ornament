#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>


#include "Frames.h"

#define F_CPU 8000000
#define BLINK_DELAY_MS 200



void all_off() {
  DDRB = 0b00000000;   //all input
  PORTB = 0b00000000;  //all off
}

void all_on(){
  while (0 == 0) {
    draw_frame();
  }
}

const char set_led_output[20] = {//poor practice. bad if Endian is different
  0b00000011,  //1
  0b00000011,  //2
  0b00000101,  //3
  0b00001001,  //4
  0b00010001,  //5
  0b00000101,  //6
  0b00000110,  //7
  0b00000110,  //8
  0b00001010,  //9
  0b00010010,  //10
  0b00001001,  //11
  0b00001010,  //12
  0b00001100,  //13
  0b00001100,  //14
  0b00010100,  //15
  0b00010001,  //16
  0b00010010,  //17
  0b00010100,  //18
  0b00011000,  //19
  0b00011000   //20
};

const char set_led_direction[20] = {
  0b00000001,  //1
  0b00000010,  //2
  0b00000100,  //3
  0b00001000,  //4
  0b00010000,  //5
  0b00000001,  //6
  0b00000010,  //7
  0b00000100,  //8
  0b00001000,  //9
  0b00010000,  //10
  0b00000001,  //11
  0b00000010,  //12
  0b00000100,  //13
  0b00001000,  //14
  0b00010000,  //15
  0b00000001,  //16
  0b00000010,  //17
  0b00000100,  //18
  0b00001000,  //19
  0b00010000,  //20
};

void led_on(uint8_t led) {  //led willbe 0-19 maps to 1->20
  DDRB = set_led_output[led];
  PORTB = set_led_direction[led];
}

volatile uint8_t current_led = 0;


// ISR(TIMER0_COMPA_vect)  //compare match A interrupt
// {
//   led_on(current_led);
// }
// ISR(TIMER0_COMPB_vect)  //compare match B interrupt
// {
//   all_off();
// }
// void timer_setup() {
//   TCCR0A = 0x00;
//   TCCR0B = 0x00;          //normal mode
//   TCCR0B |= (1 << CS00);  //no prescaling table 11-6
//   sei();
//   TCNT0 = 0;               //11.9.4 - timercounter/register
//   OCR0A = 254;             //OCR0A 11.9.5
//   OCR0B = 255;             //OCR0B 11.9.6
//   TIMSK |= (1 << OCIE0B)|(1 << OCIE0A);  //TOIE0 enable timer0 overflow interrupt, OCIE0B output compare match b interrupt enable, OCIE0A output compare match a interrupt enable 11.9.7

//   //there is some bleed through on LED 0 and on the next LED
// }

char led_grid[20] = {
  100, 100, 100, 100, 100,
  100, 100, 100, 100, 100,
  100, 100, 100, 100, 100,
  100, 100, 100, 100, 100
};

void draw_frame(void) {
  char led, bright_val, b;
  for (led = 0; led <= 19; led++) {
    //software PWM
    bright_val = led_grid[led];
    for (b = 0; b < bright_val; b += 4) { led_on(led); }  //delay while on
    for (b = bright_val; b < 100; b += 4) { all_off(); }  //delay while off
  }
}



void grid_off(){
  for(char i =0;i<20;i++)
    led_grid[i] = 0;
}

void grid_on(){
  for(char i =0;i<20;i++)
    led_grid[i] = 100;
}

//Use the reset as another "input" since we don't have any more I/O pins
//First this will check if ATtiny was reset by the reset button or from powering off.
//If it was just powered off/on, then it will only read the EEprom and set the frame to its last known value

// if it was reset (by button), then the curr_addr is incremented - moving to the next frame. 
// if curr_addr reaches max, then curr_addr changes to the next EEPROM location and base_addr is incremented to "point" to that location.

//This will make the EEPROM last 12(or max # of frames) times longer than just using one   address

unsigned char eeprom_read(bool reset_status){
  cli();
  unsigned char base_addr = 0x00; //first EEPROM address. where we will store address of currently used EEPROM address
  unsigned char curr_addr, curr_frame; //tracks the current frame
  bool increment = false, eeprom_overflow = false;

  if(reset_status == false){
    while(EECR &(1<<EEPE)); //wait until EEPROM writing is done
    EEAR = base_addr; //set address
    EECR |= (1<<EERE); //return data from data register
    curr_addr = EEDR;

    while(EECR &(1<<EEPE)); //wait until EEPROM writing is done
    EEAR = curr_addr; //set address
    EECR |= (1<<EERE);
    return EEDR; //return data from data register
  }

  /*read byte 0 of EEPROM and store in curr_addr. on first execution this will be 0xFF, if greator than 5(for now, this could be 511?) set to 1 and set curr_addr=1*/
  //read
  while(EECR &(1<<EEPE)); //wait until EEPROM writing is done
  EEAR = base_addr; //set address
  EECR |= (1<<EERE); //return data from data register
  curr_addr = EEDR;

  if(curr_addr >= 0x05 || curr_addr < 0x01){ //set to 1
    curr_addr = 0x01;
    eeprom_overflow = true;
  }

  /*go to EEPROM byte curr_addr and read the value*/
  while(EECR &(1<<EEPE)); //wait until EEPROM writing is done
  EEAR = curr_addr; //set address
  EECR |= (1<<EERE);
  curr_frame = EEDR; //return data from data register

  /*if > 12(number of functions), set to 0 and increment EEPROM address 0*/
  
  curr_frame++; //added this to stop frame 0 from repeating twice. 

  if(curr_frame > 13 || curr_frame < 0){
    curr_frame = 0;
    increment = true;
  }
  //increment curr_addr
  while(EECR &(1<<EEPE)); //wait until EEPROM writing is done
  EECR = (0<<EEPM1) | (0<<EEPM0); //erase and write mode
  EEAR = curr_addr;
  EEDR = curr_frame;
  EECR |= (1<<EEMPE); //enable writing
  EECR |= (1<<EEPE); //start writing.


  if (eeprom_overflow == true){ //reset EEPROM to 1
    while(EECR &(1<<EEPE)); //wait until EEPROM writing is done
    EECR = (0<<EEPM1) | (0<<EEPM0); //erase and write mode
    EEAR = base_addr;
    EEDR = 0x01;
    EECR |= (1<<EEMPE); //enable writing
    EECR |= (1<<EEPE); //start writing.
  }

  else if(increment == true){
    curr_addr++;
    while(EECR &(1<<EEPE)); //wait until EEPROM writing is done

    EECR = (0<<EEPM1) | (0<<EEPM0); //erase and write mode

    EEAR = base_addr;
    EEDR = curr_addr;

    EECR |= (1<<EEMPE); //enable writing
    EECR |= (1<<EEPE); //start writing.
  }

  return curr_frame;

}

bool reset_check(){
  //MCUSR |= BIT1 EXTRF
  if( ((MCUSR >> 0) & 0x1) == 1){ //Power on reset
    MCUSR = 0x0;
    return false;
  }
  if( ((MCUSR >> 1) & 0x1) == 1){ //external reset Set by the power switch
    MCUSR = 0x0;
    return true;
  }
}

int main(void) {
  //timer_setup();
  all_off();
  //bug_random();
  //check if reset was button or switch
  //visualizer();
  //christmas();
  
  bool reset = false;
  reset = reset_check();


  unsigned char frame_num = eeprom_read(reset);
  
  //char frame_num = 0;
switch(frame_num){
  case 0:
    amongus();
    break;
  case 1:
    happy();
    break;
  case 2:
    caution_lights();
    break;
  case 3:
    snowflakes();
    break;
  case 4:
    snake_slither0();
    break;
  case 5:
    snake_slither();
    break;
  case 6:
    snake_coil_uncoil();
    break;
  case 7:
    snake_coil_uncoil_fade();
    break;
  case 8:
    christmas();
    break;
  case 9:
    snake_loading();
    break;
  case 10:
    snake_loading_2();
    break;
  case 11:
    wave();
    break;
  case 12:
    wave_continous();
    break;
  case 13:
    bug_random_slow();
    break;
  default:
    amongus();
}
  //alphabet();
  return 0;

}



//Makes port0 input
//DDRB &= ~(1<<0); // PORTB0

// turn LED on
//PORTB |= 0B100000; // PORTB5
//PORTB |= (1<<5); // PORTB5
//DDRB |= (1<<0);
//PORTB |= (1<<0); // PORTB0
// PORTB &= ~ (1<<1); // PORTB1

//_delay_ms(BLINK_DELAY_MS);


//old code to go through each light 1 at a time
//DDRB = 0b00000011; //1
// PORTB = 0b00000001;
// _delay_ms(BLINK_DELAY_MS);
// DDRB = 0b00000011; //2
// PORTB = 0b00000010;
// _delay_ms(BLINK_DELAY_MS);
// DDRB = 0b00000101; //3
// PORTB = 0b00000100;
// _delay_ms(BLINK_DELAY_MS);
// DDRB = 0b00001001; //4
// PORTB = 0b00001000;
// _delay_ms(BLINK_DELAY_MS);
// DDRB = 0b00010001; //5
// PORTB = 0b00010000;
// _delay_ms(BLINK_DELAY_MS);
// DDRB = 0b00000101; //6
// PORTB = 0b00000001;
// _delay_ms(BLINK_DELAY_MS);
// DDRB = 0b00000110; //7
// PORTB = 0b00000010;
// _delay_ms(BLINK_DELAY_MS);
// DDRB = 0b00000110; //8
// PORTB = 0b00000100;
// _delay_ms(BLINK_DELAY_MS);
// DDRB = 0b00001010; //9
// PORTB = 0b00001000;
// _delay_ms(BLINK_DELAY_MS);
// DDRB = 0b00010010; //10
// PORTB = 0b00010000;
// _delay_ms(BLINK_DELAY_MS);
// DDRB = 0b00001001; //11
// PORTB = 0b00000001;
// _delay_ms(BLINK_DELAY_MS);
// DDRB = 0b00001010; //12
// PORTB = 0b00000010;
// _delay_ms(BLINK_DELAY_MS);
// DDRB = 0b00001100; //13
// PORTB = 0b00000100;
// _delay_ms(BLINK_DELAY_MS);
// DDRB = 0b00001100; //14
// PORTB = 0b00001000;
// _delay_ms(BLINK_DELAY_MS);
// DDRB = 0b00010100; //15
// PORTB = 0b00010000;
// _delay_ms(BLINK_DELAY_MS);
// DDRB = 0b00010001; //16
// PORTB = 0b00000001;
// _delay_ms(BLINK_DELAY_MS);
// DDRB = 0b00010010; //17
// PORTB = 0b00000010;
// _delay_ms(BLINK_DELAY_MS);
// DDRB = 0b00010100; //18
// PORTB = 0b00000100;
// _delay_ms(BLINK_DELAY_MS);
// DDRB = 0b00011000; //19
// PORTB = 0b00001000;
// _delay_ms(BLINK_DELAY_MS);
// DDRB = 0b00011000; //20
// PORTB = 0b00010000;
// _delay_ms(BLINK_DELAY_MS);
// all_off();
// _delay_ms(BLINK_DELAY_MS);