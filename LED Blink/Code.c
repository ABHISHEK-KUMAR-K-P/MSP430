#include <msp430.h>

int main(void)
{
    volatile unsigned int i;
    WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
    P1DIR |= 0x03;                            // Set P1.0 and P1.1 as Outputs 

    while(1)
    {
        P1OUT ^= 0x03;                        //Toggle Pins P1.0 and P1.1

        for (i=0; i<5000; i++){
        //delay 
        }
  }
}
