#ifndef PWM_H
#define PWM_H

void InitPWM(void);
void PWMSetSpeed(float vitesseEnPourcents, int moteur);
void PWMSetSpeedConsigne(float vitesseEnPourcents, char moteur);
void PWMUpdateSpeed();

#define MOTEUR_DROIT 0
#define MOTEUR_GAUCHE 1

#endif