//
// Created by wikto on 28/10/2025.
//

#include "Stepper_Motor.h"
//przede wszyutkim inicjalizacja
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
//powoli się rusza do momentu aż nie złapie krańcówki
void Stepper_Motor::calibrate() {
    while(digitalRead(limit_pin) == LOW) {
        stepper.moveRelativeInSteps(5);
    }
}
//rusza sie w odpowiednią stronę w zależnośći co tracker wyopluje
void Stepper_Motor::move(String position) {
    if (position == "WEST" || position == "SOUTH"){
        stepper.moveRelativeInSteps(10);
    }
    if (position == "EAST" || position == "NORTH"){
        stepper.moveRelativeInSteps(-10);
    }

}
