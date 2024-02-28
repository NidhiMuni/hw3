#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

#include <iostream>


struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
    bool operator()(const Event* eventOne, const Event* eventTwo){
      //cout << "hi" << endl;
      //cout << eventOne->time << " " << eventTwo->time << " " << (eventOne->time < eventTwo->time) << endl;
      return (eventOne->time < eventTwo->time);
    }
} EventLess;
	
#endif
