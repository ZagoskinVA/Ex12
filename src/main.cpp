// Copyright 2021 Vlad
#include "TimedDoor.h"
#include <iostream>
#include <string>

int main() {
    TimedDoor timeDoor(5);
    try {
        timeDoor.unlock();
        timeDoor.throwState();
    }
    catch (std::string message) {
        std::cout << message;
    }
}
