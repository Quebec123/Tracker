//
// Created by wikto on 28/10/2025.
//

#include "active_tracker.h"

//inicjalizacja zmiennych głównie
#include "active_tracker.h"

active_tracker::active_tracker(int west, int south, int east, int north)
        : west_pin(west), south_pin(south), east_pin(east), north_pin(north),
          west_value(0), south_value(0), east_value(0), north_value(0) {
    pinMode(west_pin, INPUT);
    pinMode(south_pin, INPUT);
    pinMode(east_pin, INPUT);
    pinMode(north_pin, INPUT);
}

void active_tracker::read_values() {
    west_value = 0;
    south_value = 0;
    east_value = 0;
    north_value = 0;

    for (int i = 0; i < 10; i++) {
        west_value += analogRead(west_pin);
        south_value += analogRead(south_pin);
        east_value += analogRead(east_pin);
        north_value += analogRead(north_pin);
    }

    west_value /= 10;
    south_value /= 10;
    east_value /= 10;
    north_value /= 10;

    west_value -= West_calibration;
    south_value -= South_calibration;
}

String active_tracker::estimate_direction_West_East() {
    read_values();

    if (west_value - east_value > West_East_Threshold) {
        return "WEST";
    } else if (east_value - west_value > West_East_Threshold) {
        return "EAST";
    } else {
        return "CENTER";
    }
}

String active_tracker::estimate_direction_North_South() {
    read_values();

    if (north_value - south_value > North_South_Threshold) {
        return "NORTH";
    } else if (south_value - north_value > North_South_Threshold) {
        return "SOUTH";
    } else {
        return "CENTER";
    }
}
//to był pomysł ale zbyt skomplikowany, żeby go kontynuować
int active_tracker::movement_command() {
    String horizontal_direction = estimate_direction_West_East();
    String vertical_direction = estimate_direction_North_South();

    if (horizontal_direction == "CENTER" && vertical_direction == "CENTER") {
        return 0; // No movement
    } else if (horizontal_direction == "WEST" && vertical_direction == "CENTER") {
        return 1; // Move West
    } else if (horizontal_direction == "EAST" && vertical_direction == "CENTER") {
        return 2; // Move East
    } else if (horizontal_direction == "CENTER" && vertical_direction == "NORTH") {
        return 3; // Move North
    } else if (horizontal_direction == "CENTER" && vertical_direction == "SOUTH") {
        return 4; // Move South
    } else if (horizontal_direction == "WEST" && vertical_direction == "NORTH") {
        return 5; // Move Northwest
    } else if (horizontal_direction == "WEST" && vertical_direction == "SOUTH") {
        return 6; // Move Southwest
    } else if (horizontal_direction == "EAST" && vertical_direction == "NORTH") {
        return 7; // Move Northeast
    } else if (horizontal_direction == "EAST" && vertical_direction == "SOUTH") {
        return 8; // Move Southeast
    }
    return -1; // Error case
}