//
// Created by wikto on 28/10/2025.
//

#ifndef TRACKER_ACTIVE_TRACKER_H
#define TRACKER_ACTIVE_TRACKER_H

#include <Arduino.h>
#include "Definitions.h"

class active_tracker {
public:
    active_tracker(int west, int south, int east, int north);
    void read_values();
    String estimate_direction_West_East();
    String estimate_direction_North_South();
    int movement_command();
private:
    int west_pin, south_pin, east_pin, north_pin;
    int west_value, south_value, east_value, north_value;
};

#endif //TRACKER_ACTIVE_TRACKER_H