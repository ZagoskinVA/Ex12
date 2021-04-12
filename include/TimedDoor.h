// Copyright 2021 Vlad
#ifndef INCLUDE_TIMEDDOOR_H_
#define INCLUDE_TIMEDDOOR_H_

#include<string>
#include <ctime>

class DoorAdapter;
class Timer;
class TimedDoor;

class DoorAdapter {
 private:
    TimedDoor& timedDoor;
    Timer& timer;
 public:
    explicit DoorAdapter(TimedDoor& _timeDoor, Timer& _timer) :
		timedDoor(_timeDoor), timer(_timer) {};
    void TimeOut();
};


class Timer {
 private:
    void sleep(int _time);
 public:
    void tregister(int time);
};

class TimedDoor {
 private:
    DoorAdapter * adapter;
    int timeout;
    bool isopened;
 public:
    explicit TimedDoor(int timeout) {
        this->timeout = timeout;
        Timer* timer = new Timer();
        adapter = new DoorAdapter(*this, *timer);
        isopened = false;
    }
    void unlock();
    void lock();
    bool isOpened();
    void throwMessage();
    int getTimeout();
    void throwState();
};
#endif  //  INCLUDE_TIMEDDOOR_H_
