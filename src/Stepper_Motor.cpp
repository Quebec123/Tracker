//
// Created by wikto on 28/10/2025.
//

#include "Stepper_Motor.h"

Stepper_Motor::Stepper_Motor(int step_pin, int dir_pin, int limit) {
    pinMode(step_pin, OUTPUT);
    pinMode(dir_pin, OUTPUT);
    pinMode(limit, INPUT);
    limit_pin = limit;
    stepper.connectToPins(step_pin, dir_pin);
    stepper.setSpeedInStepsPerSecond(100);
    stepper.setAccelerationInStepsPerSecondPerSecond(100);
    calibrate();
}

void Stepper_Motor::calibrate() {
    while(digitalRead(limit_pin) == LOW) {
        stepper.moveRelativeInSteps(10);
    }
}
void Stepper_Motor::move(String position) {
    if (position == "WEST"){
        stepper.moveRelativeInSteps(10);
    }
    if (position == "EAST"){
        stepper.moveRelativeInSteps(-10);
    }

}
