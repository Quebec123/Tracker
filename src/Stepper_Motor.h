//
// Created by wikto on 28/10/2025.
//

#ifndef TRACKER_STEPPER_MOTOR_H
#define TRACKER_STEPPER_MOTOR_H
#include "Arduino.h"
#include "Definitions.h"
#include <AccelStepper.h>

class Stepper_Motor {
    int limit_pin;
    void calibrate();
    AccelStepper stepper;
public:
    Stepper_Motor(AccelStepper motor, int limit_pin);
    void move(String position);
};


#endif //TRACKER_STEPPER_MOTOR_H
