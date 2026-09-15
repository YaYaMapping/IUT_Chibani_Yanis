#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ChipConfig.h"
#include "IO.h"
#include "timer.h"
#include "Robot.h"
#include "PWM.h"

int main(void) {
    //Initialisation oscillateur
    InitOscillator();

    // Configuration des input et output (IO)
    InitIO();
    InitTimer1();
    InitTimer23();
    InitPWM();
    PWMSetSpeed(0, 1); // PWMH : 10 = 12%, 50 = 52% donc c'est la valeur du PWM + 2% d'écart
                     // PWML : 10 = 2%; 50 = 2%  constant  
                     // MOTEUR 2 : courant augmente quand le moteur est stoppé instantanement car omega = 0, U = E + RI avec E = k * omega.

    LED_BLANCHE_1 = 1;
    LED_BLEUE_1 = 1;
    LED_ORANGE_1 = 1;
    LED_ROUGE_1 = 1;
    LED_VERTE_1 = 1;
    
    LED_BLANCHE_2 = 1;
    LED_BLEUE_2 = 1;
    LED_ORANGE_2 = 1;
    LED_ROUGE_2 = 1;
    LED_VERTE_2 = 1;
    
    // Boucle Principale
    while (1) {
    } // fin main
}