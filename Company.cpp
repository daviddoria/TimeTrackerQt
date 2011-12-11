#include "Company.h"


Company::Company(const std::string& name, const Qt::DayOfWeek payDay, const std::string& faxNumber, const std::string& messageOfTheDay,
                 const std::string& payrollContact, const std::string& ownerName, const std::string& phoneNumber) :
                 Name(name), PayDay(payDay), FaxNumber(faxNumber), MessageOfTheDay(messageOfTheDay), PayrollContact(payrollContact), OwnerName(ownerName), PhoneNumber(phoneNumber)
{
}

Company::Company() : Name("DefaultCompany"), PayDay(Qt::Wednesday), FaxNumber("123-4567"), MessageOfTheDay("Message of the day"), PayrollContact("DefaultPerson"), OwnerName("DefaultOwner"), PhoneNumber("123-4567")
{
}


std::string Company::GetName()
{
  return this->Name;
}

void Company::SetName(const std::string& name)
{
  this->Name = name;
}

Qt::DayOfWeek Company::GetPayDay()
{
  return this->PayDay;
}

void Company::SetPayDay(const Qt::DayOfWeek payDay)
{
  this->PayDay = payDay;
}

std::string Company::GetFaxNumber()
{
  return this->FaxNumber;
}

void Company::SetFaxNumber(const std::string& faxNumber)
{
  this->FaxNumber = faxNumber;
}

std::string Company::GetMessageOfTheDay()
{
  return this->MessageOfTheDay;
}

void Company::SetMessageOfTheDay(const std::string& messageOfTheDay)
{
  this->MessageOfTheDay = messageOfTheDay;
}

std::string Company::GetPayrollContact()
{
  return this->PayrollContact;
}

void Company::SetPayrollContact(const std::string& payrollContact)
{
  this->PayrollContact = payrollContact;
}

std::string Company::GetOwnerName()
{
  return this->OwnerName;
}

void Company::SetOwnerName(const std::string& ownerName)
{
  this->OwnerName = ownerName;
}

std::string Company::GetPhoneNumber()
{
  return this->PhoneNumber;
}

void Company::SetPhoneNumber(const std::string& phoneNumber)
{
  this->PhoneNumber = phoneNumber;
}


unsigned int Company::GetBreakMinutes()
{
  return this->BreakMinutes;
}

void Company::SetBreakMinutes(const unsigned int breakMinutes)
{
  this->BreakMinutes = breakMinutes;
}


std::string Company::GetPayrollClientNumber()
{
  return this->PayrollClientNumber;
}

void Company::SetPayrollClientNumber(const std::string& payrollClientNumber)
{
  this->PayrollClientNumber = payrollClientNumber;
}


    /*
    'constructor from database
    Public Sub New(ByVal CompanyName As String)
        'This constructor looks up the company by name in the database and retrieves its information
        Dim daCompany As New TTDataSetTableAdapters.CompanyTableTableAdapter
        Dim dtCompany As New TTDataSet.CompanyTableDataTable
        daCompany.FillByName(dtCompany, CompanyName)

        If dtCompany.Rows.Count = 0 Then
            MsgBox("Company has not been setup!")
            MsgBox("dtCompany.Rows.Count " + dtCompany.Rows.Count.ToString)
            End
        End If

        Dim CompanyRow As TTDataSet.CompanyTableRow = DirectCast(dtCompany.Rows(0), TTDataSet.CompanyTableRow)

        Name_ = CompanyRow.CompanyName
        PayDay_ = CompanyRow.PayDay
        FaxNumber_ = CompanyRow.PayrollFaxNumber
        MOTD_ = CompanyRow.MOTD
        PayrollContact_ = CompanyRow.PayrollContact
        OwnerName_ = CompanyRow.OwnerName
        Phone_ = CompanyRow.CompanyPhone
        PayrollClientNumber_ = CompanyRow.PayrollClientNumber
    End Sub
    
    Public Sub WriteCompany()
        'This function saves the companies information to the database
        Dim daCompany As New TTDataSetTableAdapters.CompanyTableTableAdapter
        Dim dtCompany As New TTDataSet.CompanyTableDataTable
        daCompany.FillByName(dtCompany, Name_)

        Dim CompanyRow As TTDataSet.CompanyTableRow = DirectCast(dtCompany.Rows(0), TTDataSet.CompanyTableRow)

        CompanyRow.CompanyName = Name_
        CompanyRow.PayDay = PayDay_
        CompanyRow.PayrollFaxNumber = FaxNumber_
        CompanyRow.MOTD = MOTD_
        CompanyRow.PayrollContact = PayrollContact_
        CompanyRow.OwnerName = OwnerName_
        CompanyRow.CompanyPhone = Phone_

        daCompany.Update(dtCompany)
    End Sub
    */