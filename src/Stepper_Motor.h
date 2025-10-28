//
// Created by wikto on 28/10/2025.
//

#ifndef TRACKER_STEPPER_MOTOR_H
#define TRACKER_STEPPER_MOTOR_H
#include "Arduino.h"
#include "Definitions.h"
#include "ESP_FlexyStepper.h"

class Stepper_Motor {
    int limit_pin;
    void calibrate();
    ESP_FlexyStepper stepper;
public:
    Stepper_Motor(int step_pin, int dir_pin, int limit);
    void move(String position);
};


#endif //TRACKER_STEPPER_MOTOR_H
