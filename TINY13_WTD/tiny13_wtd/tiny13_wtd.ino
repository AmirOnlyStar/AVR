#include <avr/io.h>
#include <avr/wdt.h>
//#include <avr/interrupt.h>
//#include <avr/sleep.h>
#define LED_PIN PB4
//#define LED_PIN 4
ISR(WDT_vect)
{

//        PORTB ^= _BV(LED_PIN); // toggle LED pin
}
void setup() {
  // put your setup code here, to run once:

//  pinMode(LED_PIN,OUTPUT);
//  digitalWrite(LED_PIN,HIGH);delay(100);digitalWrite(LED_PIN,LOW);delay(100);
//  digitalWrite(LED_PIN,HIGH);delay(100);digitalWrite(LED_PIN,LOW);delay(100);
//  digitalWrite(LED_PIN,HIGH);delay(100);digitalWrite(LED_PIN,LOW);delay(100);
  
//  wdt_reset();


        DDRB = 0b00010000; // set LED pin as OUTPUT
        PORTB = 0b00000000; // set all pins to LOW
//        wdt_enable(WDTO_500MS); // set prescaler to 0.5s and enable Watchdog Timer
    
        wdt_enable(WDTO_8S);
//        WDTCR |= (1<<WDP2)|(1<<WDP1);
//        WDTCR &=~ ((1<<WDP3)|(1<<WDP0));
    
        MCUSR &= ~(1<<WDRF); //clear interupt flag by set 0 in it 
        WDTCR |= (1<<WDE);   //Watchdog System Reset Enable 
        MCUSR &=~ (1<<WDTIE); //desable interupt

        PORTB ^= _BV(LED_PIN); // toggle LED pin
        _delay_ms(50);
        PORTB ^= _BV(LED_PIN); // toggle LED pin
        _delay_ms(50);
        PORTB ^= _BV(LED_PIN); // toggle LED pin
        _delay_ms(50);
        PORTB ^= _BV(LED_PIN); // toggle LED pin
        _delay_ms(50);
//        sei(); // enable global interrupts
}

void loop() {
  PORTB ^= _BV(LED_PIN); // toggle LED pin
  _delay_ms(1000);
//  WDTCR |= (1<<WDCE);
  wdt_reset();
//  digitalWrite(LED_PIN,HIGH);
//  delay(1000);
//  digitalWrite(LED_PIN,LOW);
//  delay(1000);
//  // put your main code here, to run repeatedly:

}
