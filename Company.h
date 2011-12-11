#ifndef Company_H
#define Company_H

// STL
#include <string>

// QT
#include <QDate>

class Company
{
    // This class stores all the information of a company.

public:
  Company(const std::string& name, const Qt::DayOfWeek payDay, const std::string& faxNumber, const std::string& messageOfTheDay,
                 const std::string& payrollContact, const std::string& ownerName, const std::string& phoneNumber);

  Company();

  std::string GetName();
  void SetName(const std::string& name);
  
  Qt::DayOfWeek GetPayDay();
  void SetPayDay(const Qt::DayOfWeek payDay);
  
  std::string GetFaxNumber();
  void SetFaxNumber(const std::string& faxNumber);
  
  std::string GetMessageOfTheDay();
  void SetMessageOfTheDay(const std::string& messageOfTheDay);
  
  std::string GetPayrollContact();
  void SetPayrollContact(const std::string& payrollContact);
  
  std::string GetOwnerName();
  void SetOwnerName(const std::string& ownerName);
  
  std::string GetPhoneNumber();
  void SetPhoneNumber(const std::string& phoneNumber);
  
  unsigned int GetBreakMinutes();
  void SetBreakMinutes(const unsigned int breakMinutes);
  
  std::string GetPayrollClientNumber();
  void SetPayrollClientNumber(const std::string& payrollClientNumber);
  
protected:
    std::string Name; // The name of the company.
    Qt::DayOfWeek PayDay; // Which day of the week payroll is submitted.
    std::string FaxNumber; // The fax number of the company.
    std::string MessageOfTheDay; // The current message of the day.
    std::string PayrollContact; // The name of the contact at the payroll office
    std::string OwnerName; // The companies owners name
    std::string PhoneNumber; // The companies phone number
    unsigned int BreakMinutes; // How many minutes employees are paid for breaks each day.
    std::string PayrollClientNumber; // The company's ID in the Payroll Company's system
    

};

#endif
