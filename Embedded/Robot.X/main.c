#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ChipConfig.h"
#include "IO.h"
#include "timer.h"
#include "Robot.h"
#include "PWM.h"
#include "Toolbox.h"
#include "ADC.h"
#include "main.h"

int ADCValue0;
int ADCValue1;
int ADCValue2;

unsigned char stateRobot;
unsigned char nextStateRobot = 0;

//void SetNextRobotStateInAutomaticMode() {
//    unsigned char positionObstacle1 = PAS_D_OBSTACLE;
//    unsigned char positionObstacle2 = PAS_D_OBSTACLE;
//    unsigned char positionObstacle3 = PAS_D_OBSTACLE;
//    int flag = 0; 
//
//    //éDtermination de la position des obstacles en fonction des ééètlmtres
//    if (robotState.distanceTelemetreDroit < 20 &&
//            robotState.distanceTelemetreGauche2 > 15 &&
//            robotState.distanceTelemetreCentre > 20 &&
//            robotState.distanceTelemetreDroite2 > 15 &&
//            robotState.distanceTelemetreGauche > 20){ //Obstacle àdroite
//
//        if (positionObstacle1 == 0) {
//            positionObstacle1 = OBSTACLE_A_DROITE;
//        } else if (positionObstacle2 == 0) {
//            positionObstacle2 = OBSTACLE_A_DROITE;
//        } else if (positionObstacle3 == 0) {
//            positionObstacle3 = OBSTACLE_A_DROITE;
//        }
//}
//           if (robotState.distanceTelemetreDroit > 20 &&
//                robotState.distanceTelemetreGauche2 > 15 &&
//                robotState.distanceTelemetreCentre > 20 &&
//                robotState.distanceTelemetreDroite2 > 15 &&
//                robotState.distanceTelemetreGauche < 20){ //Obstacle àgauche
//
//
//            if (positionObstacle1 == 0) {
//                positionObstacle1 = OBSTACLE_A_GAUCHE;
//            } else if (positionObstacle2 == 0) {
//                positionObstacle2 = OBSTACLE_A_GAUCHE;
//            } else if (positionObstacle3 == 0) {
//                positionObstacle3 = OBSTACLE_A_GAUCHE;
//            }
//}
//            
//                if (robotState.distanceTelemetreDroit > 20 &&
//                    robotState.distanceTelemetreGauche2 > 15 &&
//                    robotState.distanceTelemetreCentre < 20 &&
//                    robotState.distanceTelemetreDroite2 > 15 &&
//                    robotState.distanceTelemetreGauche > 20) { //Obstacle en face
//
//
//                if (positionObstacle1 == 0) {
//                    positionObstacle1 = OBSTACLE_EN_FACE;
//                } else if (positionObstacle2 == 0) {
//                    positionObstacle2 = OBSTACLE_EN_FACE;
//                } else if (positionObstacle3 == 0) {
//                    positionObstacle3 = OBSTACLE_EN_FACE;
//                }
//                }
//                
////                    if (robotState.distanceTelemetreDroit > 20 &&
////                        robotState.distanceTelemetreGauche2 > 15 &&
////                        robotState.distanceTelemetreCentre > 20 &&
////                        robotState.distanceTelemetreDroite2 > 15 &&
////                        robotState.distanceTelemetreGauche > 20) //pas d?obstacle
////                    positionObstacle = PAS_D_OBSTACLE;
//
//
//
//                 if (robotState.distanceTelemetreDroit > 20 &&
//                        robotState.distanceTelemetreGauche2 < 15 &&
//                        robotState.distanceTelemetreCentre > 20 &&
//                        robotState.distanceTelemetreDroite2 > 15 &&
//                        robotState.distanceTelemetreGauche > 20) {
//
//                    if (positionObstacle1 == 0) {
//                        positionObstacle1 = OBSTACLE_FULL_GAUCHE;
//                    } else if (positionObstacle2 == 0) {
//                        positionObstacle2 = OBSTACLE_FULL_GAUCHE;
//                    } else if (positionObstacle3 == 0) {
//                        positionObstacle3 = OBSTACLE_FULL_GAUCHE;}
//                 }
//                   
//                        if (robotState.distanceTelemetreDroit > 20 &&
//                            robotState.distanceTelemetreGauche2 > 15 &&
//                            robotState.distanceTelemetreCentre > 20 &&
//                            robotState.distanceTelemetreDroite2 < 15 &&
//                            robotState.distanceTelemetreGauche > 20) {//Obstacle àdroiterobotState.distanceTelemetreGauche2 < 15 &&
//
//                        if (positionObstacle1 == 0) {
//                            positionObstacle1 = OBSTACLE_A_DROITE;
//                        } else if (positionObstacle2 == 0) {
//                            positionObstacle2 = OBSTACLE_A_DROITE;
//                        } else if (positionObstacle3 == 0) {
//                            positionObstacle3 = OBSTACLE_A_DROITE;
//                        }
//        }
//
//                    
//                    if(positionObstacle1 == OBSTACLE_EN_FACE && positionObstacle2 == PAS_D_OBSTACLE && positionObstacle3 == PAS_D_OBSTACLE){
//                        PWMSetSpeedConsigne(25, MOTEUR_DROIT);
//                        PWMSetSpeedConsigne(25, MOTEUR_GAUCHE);
//                        flag = 1; 
//                        SetNextRobotStateInAutomaticMode();
//                    } else
//                    if(positionObstacle1 == OBSTACLE_EN_FACE  && positionObstacle2 == (OBSTACLE_A_GAUCHE || OBSTACLE_FULL_GAUCHE) && positionObstacle3 == (OBSTACLE_A_DROITE || OBSTACLE_FULL_DROIT )){
//                        PWMSetSpeedConsigne(25, MOTEUR_DROIT);
//                        PWMSetSpeedConsigne(25, MOTEUR_GAUCHE);
//                        flag = 1; 
//                        SetNextRobotStateInAutomaticMode();
//                    } else
//                    if(positionObstacle1 == OBSTACLE_FULL_GAUCHE && positionObstacle2 == OBSTACLE_FULL_DROIT && positionObstacle3 == PAS_D_OBSTACLE){
//                        PWMSetSpeedConsigne(-15, MOTEUR_DROIT);
//                        PWMSetSpeedConsigne(15, MOTEUR_GAUCHE);
//                        flag = 1; 
//                        SetNextRobotStateInAutomaticMode();
//                    } else   
//                    if(positionObstacle1 == PAS_D_OBSTACLE && positionObstacle2 == PAS_D_OBSTACLE && positionObstacle3 == PAS_D_OBSTACLE){
//                        PWMSetSpeedConsigne(-25, MOTEUR_DROIT);
//                        PWMSetSpeedConsigne(25, MOTEUR_GAUCHE);
//                        flag = 1; 
//                        SetNextRobotStateInAutomaticMode();
//                    }else 
//                    if(positionObstacle1 == OBSTACLE_A_GAUCHE && positionObstacle2 == PAS_D_OBSTACLE && positionObstacle3 == PAS_D_OBSTACLE){
//                        PWMSetSpeedConsigne(15, MOTEUR_DROIT);
//                        PWMSetSpeedConsigne(0, MOTEUR_GAUCHE);
//                        flag = 1; 
//                        SetNextRobotStateInAutomaticMode();
//                    }else 
//                    if(positionObstacle1 == OBSTACLE_FULL_GAUCHE && positionObstacle2 == PAS_D_OBSTACLE && positionObstacle3 == PAS_D_OBSTACLE){
//                        PWMSetSpeedConsigne(5, MOTEUR_DROIT);
//                        PWMSetSpeedConsigne(0, MOTEUR_GAUCHE);
//                        flag = 1; 
//                        SetNextRobotStateInAutomaticMode();
//                    }else
//                    if(positionObstacle1 == OBSTACLE_A_DROITE && positionObstacle2 == PAS_D_OBSTACLE && positionObstacle3 == PAS_D_OBSTACLE){
//                        PWMSetSpeedConsigne(0, MOTEUR_DROIT);
//                        PWMSetSpeedConsigne(15, MOTEUR_GAUCHE);
//                        flag = 1; 
//                        SetNextRobotStateInAutomaticMode();
//                    }
//                    
//                    if(flag == 0){
//                        PWMSetSpeedConsigne(25, MOTEUR_DROIT);
//                        PWMSetSpeedConsigne(25, MOTEUR_GAUCHE);
//                        SetNextRobotStateInAutomaticMode();
//                    }
//                    
//                    }
////    positionObstacle = OBSTACLE_FULL_DROIT;
////    //éDtermination de lé?tat àvenir du robot
////    if (positionObstacle == PAS_D_OBSTACLE)
////        nextStateRobot = STATE_AVANCE;
////    else if (positionObstacle == OBSTACLE_A_DROITE)
////        nextStateRobot = STATE_TOURNE_GAUCHE;
////    else if (positionObstacle == OBSTACLE_A_GAUCHE)
////        nextStateRobot = STATE_TOURNE_DROITE;
////    else if (positionObstacle == OBSTACLE_EN_FACE)
////        nextStateRobot = STATE_TOURNE_SUR_PLACE_GAUCHE;
////    else if (positionObstacle == OBSTACLE_FULL_GAUCHE)
////        nextStateRobot = STATE_TOURNE_SLIGHTLY_DROITE;
////    else if (positionObstacle == OBSTACLE_FULL_DROIT)
////        nextStateRobot = STATE_TOURNE_SLIGHTLY_GAUCHE;
//
////    //Si l?on n?est pas dans la transition de lé?tape en cours
////    if (nextStateRobot != stateRobot - 1)
////        stateRobot = nextStateRobot;
////}
//
//void OperatingSystemLoop(void) {
//
//    switch (stateRobot) {
//
//        case STATE_ATTENTE:
//            timestamp = 0;
//            PWMSetSpeedConsigne(0, MOTEUR_DROIT);
//            PWMSetSpeedConsigne(0, MOTEUR_GAUCHE);
//            stateRobot = STATE_ATTENTE_EN_COURS;
//
//        case STATE_ATTENTE_EN_COURS:
//            if (timestamp > 1000)
//                stateRobot = STATE_AVANCE;
//            break;
//
//        case STATE_AVANCE:
//            PWMSetSpeedConsigne(25, MOTEUR_DROIT);
//            PWMSetSpeedConsigne(0, MOTEUR_GAUCHE);
//            stateRobot = STATE_AVANCE_EN_COURS;
//            break;
//
//        case STATE_AVANCE_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//
//        case STATE_TOURNE_GAUCHE:
//            PWMSetSpeedConsigne(-10, MOTEUR_DROIT);
//            PWMSetSpeedConsigne(0, MOTEUR_GAUCHE);
//            stateRobot = STATE_TOURNE_GAUCHE_EN_COURS;
//            break;
//
//        case STATE_TOURNE_GAUCHE_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//
//        case STATE_TOURNE_DROITE:
//            PWMSetSpeedConsigne(0, MOTEUR_DROIT);
//            PWMSetSpeedConsigne(-10, MOTEUR_GAUCHE);
//            stateRobot = STATE_TOURNE_DROITE_EN_COURS;
//            break;
//
//        case STATE_TOURNE_DROITE_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//        case STATE_TOURNE_SUR_PLACE_GAUCHE:
//            PWMSetSpeedConsigne(15, MOTEUR_DROIT);
//            PWMSetSpeedConsigne(15, MOTEUR_GAUCHE);
//            stateRobot = STATE_TOURNE_SUR_PLACE_GAUCHE_EN_COURS;
//            break;
//
//        case STATE_TOURNE_SUR_PLACE_GAUCHE_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//
//        case STATE_TOURNE_SUR_PLACE_DROITE:
//            PWMSetSpeedConsigne(-15, MOTEUR_DROIT);
//            PWMSetSpeedConsigne(-15, MOTEUR_GAUCHE);
//            LED_BLANCHE_1 = !LED_BLANCHE_1;
//            stateRobot = STATE_TOURNE_SUR_PLACE_DROITE_EN_COURS;
//            break;
//
//        case STATE_TOURNE_SUR_PLACE_DROITE_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//
//        case STATE_TOURNE_SLIGHTLY_DROITE:
//            PWMSetSpeedConsigne(0, MOTEUR_DROIT);
//            PWMSetSpeedConsigne(5, MOTEUR_GAUCHE);
//            stateRobot = STATE_TOURNE_SLIGHTLY_DROITE_EN_COURS;
//            break;
//
//        case STATE_TOURNE_SLIGHTLY_DROITE_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//
//        case STATE_TOURNE_SLIGHTLY_GAUCHE:
//            PWMSetSpeedConsigne(-5, MOTEUR_DROIT);
//            PWMSetSpeedConsigne(0, MOTEUR_GAUCHE);
//            stateRobot = STATE_TOURNE_SLIGHTLY_GAUCHE_EN_COURS;
//            break;
//
//        case STATE_TOURNE_SLIGHTLY_GAUCHE_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//
//        default:
//            stateRobot = STATE_ATTENTE;
//            break;
//    }
//}

void smartvitesse() {

    if (robotState.distanceTelemetreDroit > 30 &&
            robotState.distanceTelemetreGauche2 > 30 &&
            robotState.distanceTelemetreCentre > 30 &&            
            robotState.distanceTelemetreDroite2 > 30 &&
            robotState.distanceTelemetreGauche > 30) {

        PWMSetSpeedConsigne(-25, MOTEUR_DROIT);
        PWMSetSpeedConsigne(25, MOTEUR_GAUCHE);
    } else if(robotState.distanceTelemetreCentre < 20) {
             PWMSetSpeedConsigne(15, MOTEUR_GAUCHE);
             PWMSetSpeedConsigne(15, MOTEUR_DROIT);
    }else{

        
        float coef_G2 = robotState.distanceTelemetreGauche2 / 30;
        float coef_G1 = robotState.distanceTelemetreGauche / 30;

        //    robotState.distanceTelemetreCentre

        float coef_D1 = robotState.distanceTelemetreDroit / 30;
        float coef_D2 = robotState.distanceTelemetreDroite2 / 30;

        float coef_D = coef_D2 * coef_D1;
        float coef_G = coef_G1 * coef_G2;

        int VD = 25 * coef_G;
        int VG = 25 * coef_D;

        if (coef_D > 1 && coef_G > 1) {
            PWMSetSpeedConsigne(0, MOTEUR_DROIT);
            PWMSetSpeedConsigne(0, MOTEUR_GAUCHE);

            return;
        } else if (coef_D < 1 && coef_G > 1) {
            
             PWMSetSpeedConsigne(VG, MOTEUR_GAUCHE);
             PWMSetSpeedConsigne(-15, MOTEUR_DROIT); 
            
        }else if (coef_D > 1 && coef_G < 1){
            PWMSetSpeedConsigne(15, MOTEUR_GAUCHE);
             PWMSetSpeedConsigne(-VD, MOTEUR_DROIT); 
        }else if (coef_D < 1 && coef_G < 1){
            PWMSetSpeedConsigne(-VD, MOTEUR_DROIT);
            PWMSetSpeedConsigne(VG, MOTEUR_GAUCHE);
        }
    }
}

int main(void) {
    //Initialisation oscillateur
    InitOscillator();

    // Configuration des input et output (IO)
    InitIO();
    InitADC1();
    InitTimer1();
    InitTimer23();
    InitTimer4();
    InitPWM();

    //PWMSetSpeedConsigne(0, 0);
    //PWMSetSpeed(0, 1); // PWMH : 10 = 12%, 50 = 52% donc c'est la valeur du PWM + 2% d'écart
    // PWML : 10 = 2%; 50 = 2%  constant  
    // MOTEUR 2 : courant augmente quand le moteur est stoppé instantanement car omega = 0, U = E + RI avec E = k * omega.


    // Boucle Principale
    while (1) {
        //        if (ADCIsConversionFinished()) {
        //            ADCClearConversionFinishedFlag();
        //            unsigned int * result = ADCGetResult();
        //            ADCValue0 = result[0]; // capteur milieur droite 
        //            ADCValue1 = result[1]; // capteur milieu 
        //            ADCValue2 = result[2]; // capteur milieu gauche 
        //        }
        if (ADCIsConversionFinished() == 1) {
            ADCClearConversionFinishedFlag(); // sur la courbe fournie par la documentation les distance >= 5 cm varie énormement et sont égale a des valeur surpérieur 
            unsigned int * result = ADCGetResult();
            float volts = ((float) result [1])* 3.3 / 4096;
            robotState.distanceTelemetreGauche = 34 / volts - 5; // gauche 2 1
            volts = ((float) result [2])* 3.3 / 4096;
            robotState.distanceTelemetreCentre = 34 / volts - 5; // gauche 2 
            volts = ((float) result [3])* 3.3 / 4096;
            robotState.distanceTelemetreDroit = 34 / volts - 5; //centre 3
            volts = ((float) result [4])* 3.3 / 4096;
            robotState.distanceTelemetreDroite2 = 34 / volts - 5; // droit 4 
            volts = ((float) result [0])* 3.3 / 4096;
            robotState.distanceTelemetreGauche2 = 34 / volts - 5; // droit 2 0
        }




    } // fin main
}