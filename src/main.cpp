#include <Arduino.h>
#include "Definitions.h"
#include "Stepper_Motor.h"
#include "active_tracker.h"
AccelStepper West_East_Stepper(AccelStepper::DRIVER, West_East_Step, West_East_Dir);
AccelStepper North_South_Stepper(AccelStepper::DRIVER, North_South_Step, North_South_Dir);

Stepper_Motor Motor_West_East(West_East_Stepper, West_East_limit);
active_tracker tracker(WEST_PIN, SOUTH_PIN, EAST_PIN, NORTH_PIN);
Stepper_Motor Motor_North_South(North_South_Stepper, North_South_limit);
void setup() {
    Serial.begin(9600);
}

void loop() {
    String buffor; //buffor do przechowywania kierunku
    buffor = tracker.estimate_direction_West_East(); //zczytaj kierunek
    while(buffor != "CENTER"){ //do momentu aż nie wyśrodkujemy
        Serial.println(buffor); //debug
        Motor_West_East.move(buffor); //przekazujemy do krokowca
        buffor = tracker.estimate_direction_West_East(); //zczytujemy ponownie żeby wejśc do pętli z aktualną wartością
        delay(10); //debug
    }
    Serial.println("correct place in Weast-East axis!");

    buffor = tracker.estimate_direction_North_South(); //to samo dla drugiej osi
    while(buffor != "CENTER"){
        Serial.println(buffor);
        Motor_North_South.move(buffor);
        buffor = tracker.estimate_direction_North_South();
        delay(10);
    }
    delay(1000);//sun doesnt move that fast
}