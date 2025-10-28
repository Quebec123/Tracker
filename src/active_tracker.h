//
// Created by wikto on 28/10/2025.
//

#ifndef TRACKER_ACTIVE_TRACKER_H
#define TRACKER_ACTIVE_TRACKER_H

#include <Arduino.h>
#include "Definitions.h"

class active_tracker {
    int pins[4];
    int values[4];
    void read_values();
    String estimate_direction_West_East();
    String estimate_direction_North_South();
public:
    active_tracker(int west, int south, int east, int north);
    int movement_command();


};


#endif //TRACKER_ACTIVE_TRACKER_H
