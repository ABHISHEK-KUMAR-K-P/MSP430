#include <msp430.h>

#define SW1     BIT4              
#define SW2     BIT7              

#define LED1    BIT0              
#define LED2    BIT4              

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;     

    // Set LED pins as output
    P1DIR |= (LED1 | LED2);       
    P1OUT &= ~(LED1 | LED2);      

    // Set switch pins as input
    P2DIR &= ~(SW1 | SW2);        

    // Enable internal pull-up resistors
    P2REN |= (SW1 | SW2);         
    P2OUT |= (SW1 | SW2);         

    // Interrupt Edge Select falling edge
    P2IES &= ~(SW1 | SW2);         

    // Enable interrupts on SW1 and SW2
    P2IE |= (SW1 | SW2);          

    __bis_SR_register(GIE);       

    while(1){
    //stay idle
    }
}

// Interrupt Service Routine for Port 2
#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void) {
    volatile unsigned long i;

    if(P2IFG & SW1) {             
        P1OUT ^= LED1;            
        while(!(P2IFG & SW1)); //debounce period till button is released
        P2IFG &= ~SW1;            
    }

    if(P2IFG & SW2) {             
        P1OUT ^= LED2;            
        while(!(P2IFG & SW2));
        P2IFG &= ~SW2;            
    }
}
