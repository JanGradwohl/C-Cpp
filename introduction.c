#include "mbed.h"

DigitalOut myled(LED1);
DigitalOut myLedUp(LED4);
DigitalIn  up(p15);          // Joystick "up"
DigitalIn  down(p12);          // Joystick "up"

AnalogIn  poti1(p19);
AnalogIn  poti2(p20);


PwmOut r(p23);
PwmOut g(p24);
PwmOut b(p25);

// Ton t1;
// int a;
int main() 
{
    r = 0.5;
    g = 1;     // 1 = dunkel
    b = 1;
    
    while(1) {
        myled = 1;
        wait( poti1.read() );
        myled = 0;
        wait( poti1 );
        
        if ( up == 1 ) {  // "busy wait"
           myLedUp = 1;   // Weisst den output direkt den wert des joystick-ups zu
           r = 1;
           g = 0;
           b = 1;
        }

        if ( down == 1) {
            myLedUp = 0;
            r = 1;
            g = 1;
            b = 0.5;
        }
    }
}
