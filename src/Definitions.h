//
// Created by wikto on 28/10/2025.
//

#ifndef TRACKER_DEFINITIONS_H
#define TRACKER_DEFINITIONS_H

const int WEST_PIN = 36; //piny ADC
const int SOUTH_PIN = 39;
const int EAST_PIN = 34;
const int NORTH_PIN = 35;

const int West_calibration = 120; //wartoąści kalibracyjne od Adamiak
const int South_calibration = 1640;

const int West_East_Threshold = 100; //jaki próg żeby się ruszył
const int North_South_Threshold = 100;

const int West_East_Step = 10; //piny na jeden stepujący silnik
const int West_East_Dir = 1;
const int West_East_limit = 2;

const int North_South_Step = 3; //piny na jeden stepujący silnik
const int North_South_Dir = 4;
const int North_South_limit = 5;

const int PWM = 6;
#endif //TRACKER_DEFINITIONS_H
