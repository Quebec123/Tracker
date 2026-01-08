//
// Created by wikto on 28/10/2025.
//

#ifndef TRACKER_DEFINITIONS_H
#define TRACKER_DEFINITIONS_H

const int SOUTH_PIN = 35; //1
const int EAST_PIN = 39; //2
const int WEST_PIN = 34; //4
const int NORTH_PIN = 36; //3 120
//piny ADC




const int West_calibration = 0; //wartoąści kalibracyjne od Adamiak
const int South_calibration =  0;
const int East_calibration = -100; //wartoąści kalibracyjne od Adamiak
const int North_calibration =  120;


const int West_East_Threshold = 300; //jaki próg żeby się ruszył
const int North_South_Threshold = 300;

const int West_East_Step = 26; //piny na jeden stepujący silnik
const int West_East_Dir = 25;
const int West_East_limit = 15; // to ma pulldown

const int North_South_Step = 5; //piny na jeden stepujący silnik
const int North_South_Dir = 2;
const int North_South_limit = 15; // to ma pulldown

const int PWM = 6;
#endif //TRACKER_DEFINITIONS_H
