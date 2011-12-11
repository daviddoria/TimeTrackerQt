#ifndef Associate_H
#define Associate_H

// STL
#include <string>

// QT
#include <QDate>
#include <QTime>

class Associate
{
public:

  Associate();
  Associate(const std::string& name, const int social, const int pin);

  std::string ToString();

  std::string GetName() const;
  void SetName(const std::string& name);

  int GetSocial() const;
  void SetSocial(const int social);

  int GetPin() const;
  void SetPin(const int pin);
  
  QDate GetStartDate() const;
  void SetStartDate(const QDate& startDate);
  
  QTime GetSickHours() const;
  void SetSickHours(const QTime& sickHours);
  
  QTime GetVacationHours() const;
  void SetVacationHours(const QTime& vacationHours);

  virtual std::string GetTypeString() = 0;

protected:

  std::string Name; // The associate's name
  int Social; // The associate's social security number
  int PIN; // The associates PIN for Time Tracker
  QDate StartDate;
  QTime SickHours;
  QTime VacationHours;
};

#endif
