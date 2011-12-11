#include "Associate.h"

#include <sstream>

Associate::Associate() : Name("DefaultName"), Social(123456789), PIN(123)
{
  
}

Associate::Associate(const std::string& name, const int social, const int pin) : Name(name), Social(social), PIN(pin)
{
}

std::string Associate::ToString()
{
  // create a string with all of the associate's information
  std::stringstream ss;

  ss << this->Name << " " << this->Social << " " << this->PIN;
  return ss.str();
}


// Associate name accessor/mutator
std::string Associate::GetName() const
{
  return this->Name;
}
  
void Associate::SetName(const std::string& name)
{
  this->Name = name;
}
  
  // Associate social sectury number accessor/mutator
int Associate::GetSocial() const
{
  return this->Social;
}

void Associate::SetSocial(const int social)
{
  this->Social = social;
}

//Associate pin accessor/mutator
int Associate::GetPin() const
{
  return this->PIN;
}

void Associate::SetPin(const int pin)
{
  this->PIN = pin;
}

QDate Associate::GetStartDate() const
{
  return this->StartDate;
}

void Associate::SetStartDate(const QDate& startDate)
{
  this->StartDate = startDate;
}

  
QTime Associate::GetSickHours() const
{
  return this->SickHours;
}

void Associate::SetSickHours(const QTime& sickHours)
{
  this->SickHours = SickHours;
}


QTime Associate::GetVacationHours() const
{
  return this->VacationHours;
}

void Associate::SetVacationHours(const QTime& vacationHours)
{
  this->VacationHours = vacationHours;
}


/*
    'constructor from database
Public Sub New(ByVal Name As String)
    'get the row of the associate
    Dim daAssociate As New TTDataSetTableAdapters.AssociateTableTableAdapter
    Dim dtAssociate As New TTDataSet.AssociateTableDataTable
    daAssociate.FillByName(dtAssociate, Name)

    If dtAssociate.Rows.Count = 0 Then
        MessageBox.Show("There is no associate named " + Name)
        End
    End If

    Dim AssociateRow As TTDataSet.AssociateTableRow = DirectCast(dtAssociate.Rows(0), TTDataSet.AssociateTableRow)

    'construct the Associate object
    _name = Name
    _social = AssociateRow.SocialSecurityNumber
    _pin = AssociateRow.PIN
    _type = AssociateRow.Type.GetAssociateType

End Sub

Public Function WriteData() As Boolean
    'This function writes the associates information to the database.
    'If the associate already exists in the database, the old entry is deleted, and the new one is added.

    Dim daAssociate As New TTDataSetTableAdapters.AssociateTableTableAdapter
    Dim dtAssociate As New TTDataSet.AssociateTableDataTable
    daAssociate.FillByName(dtAssociate, Name)

    'delete the "old" associate if they already exist
    If dtAssociate.Rows.Count = 1 Then
        dtAssociate.Rows(0).Delete()
    End If

    'create a new row
    Dim AssociateNewRow As TTDataSet.AssociateTableRow = DirectCast(dtAssociate.NewRow, TTDataSet.AssociateTableRow)

    'add all the attributes to the new row
    AssociateNewRow.AssociateName = _name
    AssociateNewRow.SocialSecurityNumber = _social
    AssociateNewRow.Type = _type.GetString
    AssociateNewRow.PIN = _pin

    'add the new row to the table in memory
    dtAssociate.Rows.Add(AssociateNewRow)

    'commit the changes to the database
    daAssociate.Update(dtAssociate)

End Function

Public Sub WriteEvent(ByVal CurrentEvent As PunchEvent)
    'write a punch event for this associate to the database

    Dim daEvent As New TTDataSetTableAdapters.PunchEventTableTableAdapter
    Dim EventTable As New TTDataSet.PunchEventTableDataTable

    'do you need to do this?
    'daEvent.Fill(EventTable)

    'setup new row and add it

    Dim PunchInNewRow As TTDataSet.PunchEventTableRow = EventTable.NewPunchEventTableRow

    'add all the attributes to the new row
    PunchInNewRow.AssociateName = _name
    PunchInNewRow.TimeField = CurrentEvent.PunchTime
    PunchInNewRow.InOut = CurrentEvent.Direction.GetString
    PunchInNewRow.Reason = CurrentEvent.Reason.GetString
    'PunchInNewRow.Reason = ReasonToString(CurrentEvent.Reason)

    EventTable.Rows.Add(PunchInNewRow)

    daEvent.Update(EventTable)

End Sub

Public Sub ShowArea()
    'Display the correct form after login based on the type of associate.

    If Type = AssociateType.MANAGER Then
        frmManager.ShowDialog()
    ElseIf Type = AssociateType.TIMED Then
        frmAssociate.ShowDialog()
    Else
        MsgBox("This associate type cannot login.")
        Exit Sub
    End If
End Sub

Public Function GetLastEvent() As PunchEvent
    'get the most recent event of the associate

    'uses fancy subquery
    'SELECT  Associate, TimeField, InOut, Reason, [Key]
    'FROM(PunchEventTable)
    'WHERE  (TimeField =
    '(SELECT  MAX(TimeField) AS Expr1
    'FROM     PunchEventTable PunchEventTable_1
    'WHERE  (Associate LIKE ?))) AND (Associate LIKE ?)

    Dim daEvent As New TTDataSetTableAdapters.PunchEventTableTableAdapter
    Dim dtEvent As New TTDataSet.PunchEventTableDataTable
    daEvent.FillByLast(dtEvent, Name)

    Dim LastEvent As New PunchEvent

    'if there are no events, this is either an error or a new associate.
    'if there are events, extract the data and create a PunchEvent object to return
    If dtEvent.Rows.Count = 0 Then
        MsgBox("Could not get previous event. If this is not your first day, please see a manager.")
        LastEvent.Valid = False
    Else
        Dim LastEventRow As TTDataSet.PunchEventTableRow = DirectCast(dtEvent.Rows(0), TTDataSet.PunchEventTableRow)
        LastEvent.Reason = LastEventRow.Reason.GetEventReason
        LastEvent.PunchTime = LastEventRow.TimeField
        LastEvent.Direction = LastEventRow.InOut.GetEventDirection
        LastEvent.Valid = True
    End If

    Return LastEvent

End Function

Public Function CalculateDailyHours(ByVal DailyEvents As List(Of PunchEvent)) As DailyHours
    'This function works by finding the total time the associate was at work (OUT DAY - IN DAY),
    'the total time they were on break, and the time they were at lunch. These values are stored in the DailyHours class
    'which computes more useful quantities.

    'Dim DayHours As ValidDouble
    'Dim LunchHours As ValidDouble
    'Dim BreakHours As ValidDouble

    Dim DayEvents As New DayEvent(ExtractEvents(DailyEvents, EventReason.DAY))
    Dim LunchEvents As New LunchEvent(ExtractEvents(DailyEvents, EventReason.LUNCH))
    Dim BreakEvents As New BreakEvent(ExtractEvents(DailyEvents, EventReason.BREAK))

    Dim DayHours As ValidDouble = DayEvents.CalculateTime
    Dim LunchHours As ValidDouble = LunchEvents.CalculateTime
    Dim BreakHours As ValidDouble = BreakEvents.CalculateTime

    If DayHours.Valid = True And LunchHours.Valid = True And BreakHours.Valid = True Then
        Dim Hours As New DailyHours(BreakHours, LunchHours, DayHours)
        Hours.Valid = True
        Return Hours
    Else
        Dim InvalidHours As New DailyHours
        InvalidHours.Valid = False
        Return InvalidHours
    End If
  
End Function

Public Function GetEvents(ByVal DateOfEvents As DateTime, ByVal TypeOfEvent As EventReason) As List(Of PunchEvent)

    Dim daEvent As New TTDataSetTableAdapters.PunchEventTableTableAdapter
    Dim dtEvent As New TTDataSet.PunchEventTableDataTable
    daEvent.FillByAssociateDateReason(dtEvent, Name, TypeOfEvent.GetString, DateOfEvents.ToShortDateString)

    Dim EventList As New List(Of PunchEvent)

    For Each EventRow As TTDataSet.PunchEventTableRow In dtEvent.Rows
        Dim TempEvent As New PunchEvent(EventRow.Reason.GetEventReason, EventRow.InOut.GetEventDirection, EventRow.TimeField)
        EventList.Add(TempEvent)
    Next

    Return EventList

End Function


'Public Function NumLunchEvents(ByVal AllEvents As List(Of PunchEvent)) As Double
'    Dim LunchEvents As List(Of PunchEvent) = ExtractEvents(AllEvents, EventReason.LUNCH)
'    Return LunchEvents.Count
'End Function


Public Function CalculateTimeInWeek(ByVal DaysInWeek As List(Of Date)) As WeeklyHours
    'Inputs: A list of Date's to calculate the times for.
    'Outputs: A WeeklyHours containing the total number of hours worked in the week.

    Dim Weekly As New WeeklyHours
    Dim TotalHours As Double = 0

    For Each CurrentDate As Date In DaysInWeek
        Dim DateEvents As List(Of PunchEvent) = GetEvents(CurrentDate, EventReason.ALL)
        Dim DayHours As DailyHours = CalculateDailyHours(DateEvents)
        If DayHours.Valid = True Then
            TotalHours = TotalHours + DayHours.TotalTime
        Else
            Weekly.Valid = False
            Return Weekly
        End If
    Next

    Weekly.TotalTime = TotalHours
    Weekly.Valid = True
    Return Weekly

End Function
*/
