//
// Created by wikto on 28/10/2025.
//

#include "active_tracker.h"
//inicjalizacja zmiennych głównie
active_tracker::active_tracker( int west, int south, int east, int north) {
    pins[0] = west; //tablica pinów
    pins[1] = south;
    pins[2] = east;
    pins[3] = north;
    pinMode(west, INPUT);
    pinMode(south, INPUT);
    pinMode(east, INPUT);
    pinMode(north, INPUT);

}
//to czyta wartości i uśrednia. Dodatkowo odejmuje wartości jako kalibracje
void active_tracker::read_values() { //wartości w tablicy values są tgakie same jak w pins
    for (int i = 0; i < 4; i++) {
        values[i] = 0;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            values[j] += analogRead(pins[j]);
        }
    }
    for (int i = 0; i < 4; i++) {
        values[i] /= 10;
    }
    values[0] -= West_calibration;
    values[1] -= South_calibration;
}
//to czyta wartości i poprównuje z akceptowanym limitem i zwaraca jeżeli poza
String active_tracker::estimate_direction_West_East() {
    read_values();
    int west_value = values[0];
    int east_value = values[2];

    if (west_value - east_value > West_East_Threshold) {
        return "WEST";
    } else if (east_value - west_value > West_East_Threshold) {
        return "EAST";}
    else {
        return "CENTER";
    }

}
//to samo cow yjej ale dla drugiej osi
String active_tracker::estimate_direction_North_South() {
    read_values();
    int north_value = values[3];
    int south_value = values[1];

    if (north_value - south_value > North_South_Threshold) {
        return "NORTH";
    } else if (south_value - north_value > North_South_Threshold) {
        return "SOUTH";}
    else {
        return "CENTER";
    }

}
//to był pomysł ale zbyt skomplikowany, żeby go kontynuować
int active_tracker::movement_command() {
    read_values();
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