#include "Day.h"

#include <sstream>

Day::Day(std::vector<Event> events)
{
  this->Events = events;
}

//Compute the amount of time the associate spend on breaks
QTime Day::ComputeBreakTime() const
{
//   'declare some variables
//   Dim BreakInTime As DateTime
//   Dim BreakOutTime As DateTime
//   Dim TotalBreakTime 

  // Compute the amount of time between the punch out to break and back in from break
//   For BreakNumber As Integer = 0 To InEvents.Count - 1
// 
//       InTime = InEvents(BreakNumber).PunchTime
//       OutTime = OutEvents(BreakNumber).PunchTime
//       Dim CurrentBreakTime As System.TimeSpan = InTime.Subtract(OutTime)
//       If CurrentBreakTime < System.TimeSpan.FromSeconds(0) Then
//           MessageBox.Show("Breaks cannot have negative time! The times are: out: " + OutTime.ToString + " in: " + InTime.ToString + " time: " + CurrentBreakTime.TotalHours.ToString + " hours")
//           End
//       End If
// 
//       TotalBreakTime = TotalBreakTime + CurrentBreakTime
//   Next

}

bool Day::EventsAreOrdered() const
{
  for(unsigned int i = 0; i < this->Events.size(); ++i)
    {
//     If BreakEvents.Item(i).Direction = EventDirection.DirectionOut And BreakEvents.Item(i + 1).Direction = EventDirection.DirectionIn Then
//         OutEvents.Add(BreakEvents.Item(i))
//         InEvents.Add(BreakEvents.Item(i + 1))
//     Else
//         Valid = False
//         Exit Sub
//     End If
    }
}


std::string Day::ToString() const
{
  // Return a string of all of the times
  std::stringstream ss;
  //ss << "Break: " << ComputeBreakTime() << " Lunch: " << ComputeLunchTime() << " Day: " << ComputeTotalTime();

  return ss.str();
}


// Compute the number of hours the associate should be paid for the day
QTime Day::ComputeTotalTime() const
{
//   QTime breakOverage = ComputeBreakOverage();
// 
//   // Subtract the break time (over allowance) and lunch time from the day time and return the result as the amount of time they should be paid for for the day
//   return ComputeTotalTime() - (breakOverage + ComputeLunchTime());
}

// Compute how much time over the allowance an associate spent on break
QTime Day::ComputeBreakOverage() const
{
//   QTime breakOverage = ComputeBreakTime().minsTo(Company.AllowedBreakTime);
//   if(breakOverage < 0)
//     {
//     breakOverage = 0;
//     }
// 
//   return breakOverage;
}
