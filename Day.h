#ifndef Day_H
#define Day_H

#include "Event.h"

// STL
#include <vector>

// Qt
#include <QTime>

class Day
{
public:
  Day(){}
  Day(std::vector<Event> events);
  
  QTime ComputeBreakTime() const; // The total amount of time between all of the "OUT BREAK" and "IN BREAK" pairs
  QTime ComputeLunchTime() const; // The amount of time between "OUT LUNCH" and "IN LUNCH"
  QTime ComputeTotalTime() const; // The amount of time between "IN DAY" and "OUT DAY"
  bool IsValid() const; // If the events are correct in number and order, this should be true.
  QTime ComputeBreakOverage() const;
  bool EventsAreOrdered() const;
  std::string ToString() const;
  
protected:
  //There should be an "in" event for every "out" event
  std::vector<Event> Events;

};

#endif
