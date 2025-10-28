#include <Arduino.h>
#include "Definitions.h"
#include "Stepper_Motor.h"
#include "active_tracker.h"
Stepper_Motor Motor_West_East(West_East_Step, West_East_Dir, West_East_limit);
active_tracker tracker(WEST_PIN, SOUTH_PIN, EAST_PIN, NORTH_PIN);

void setup() {
Serial.begin(9600);
}

void loop() {
    String buffor;
    buffor = tracker.estimate_direction_West_East();
    while(buffor != "CENTER"){
        Serial.println(buffor);
        Motor_West_East.move(buffor);
        buffor = tracker.estimate_direction_West_East();
    }
}