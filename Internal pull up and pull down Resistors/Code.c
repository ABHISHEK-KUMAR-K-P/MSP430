#include <msp430.h>

 

void main(void) {

    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer


    P1DIR |= BIT0;              // P1.0 as Output
    P1DIR |= BIT1;              // P2.0 as Output
    
    P2DIR &= ~BIT5;             // P2.5 Input
    P2REN |= BIT5;              // P2.5 Pull Up/Down Enable
    P2OUT |= BIT5;              // P2.5 Pull Up Enable
    
    P2DIR &= ~BIT3;             // P2.3 Input
    P2REN |= BIT3;              // P2.3 Pull Up/Down Enable
    P2OUT &= ~BIT3;             // P2.3 Pull Down Enable
    
    while(1)

    {

        if(P2IN & BIT3)         // If PL SW is pressed

            P1OUT &= ~BIT0;     // LED GREEN ON

        else if(!(P2IN & BIT5)) // If NL SW is pressed

            P1OUT |= BIT1;      // LED PINK ON

        else{

            P1OUT |= BIT0;
            P1OUT &= ~BIT1;      // else LEDs OFF
        }

    }

}
