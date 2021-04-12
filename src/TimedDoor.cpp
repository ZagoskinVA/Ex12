// Copyright 2021 Vlad
#include "TimedDoor.h"
#include<string>

void TimedDoor::unlock() {
    isopened = true;
    adapter->TimeOut();
}

void TimedDoor::lock() {
    isopened = false;
    
}

bool TimedDoor::isOpened() {
    return isopened;
}

void TimedDoor::throwMessage() {
    throw std::string("Close the door");
}

int TimedDoor::getTimeout() {
    return timeout;
}

void TimedDoor::throwState() {
    if (isopened)
        throw std::string("the door is opened!");
    throw std::string("the door is closed!");
}

void Timer::sleep(int _time) {
    time_t start = time(nullptr);
    while (time(nullptr) - start < _time) {}
}

void Timer::tregister(int time) {
    sleep(time);
}

void DoorAdapter::TimeOut() {
    timer.tregister(timedDoor.getTimeout());
    if(timedDoor.isOpened())
        timedDoor.throwMessage();
}
