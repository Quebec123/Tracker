//
// Created by wikto on 28/10/2025.
//

#include "Stepper_Motor.h"
//przede wszyutkim inicjalizacja
Stepper_Motor::Stepper_Motor(AccelStepper motor, int limit_pin) : stepper(motor), limit_pin(limit_pin) {
    stepper.setMaxSpeed(4000);
    stepper.setAcceleration(1000);
    pinMode(limit_pin, INPUT_PULLDOWN);


}
//powoli się rusza do momentu aż nie złapie krańcówki
void Stepper_Motor::calibrate() {
    while(digitalRead(limit_pin) == LOW) {
        stepper.move(200);
        stepper.run();
    }
}
//rusza sie w odpowiednią stronę w zależnośći co tracker wyopluje
void Stepper_Motor::move(String position) {
    if (position == "WEST" || position == "SOUTH"){
        stepper.move(1000);
        stepper.run();
    }
    if (position == "EAST" || position == "NORTH"){
        stepper.move(-1000);
        stepper.run();
    }

}
