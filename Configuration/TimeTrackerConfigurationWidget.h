#ifndef TimeTrackerConfigurationWidget_H
#define TimeTrackerConfigurationWidget_H

#include "ui_TimeTrackerConfigurationWidget.h"

#include <QMainWindow>
class QSqlDatabase;

class TimeTrackerConfigurationWidget : public QMainWindow, private Ui::TimeTrackerConfigurationWidget
{
Q_OBJECT
public:
  TimeTrackerConfigurationWidget(QWidget *parent = 0);
  ~TimeTrackerConfigurationWidget();

public slots:
  void on_btnNewCompany_clicked();
  void on_btnEditCompany_clicked();

protected:
  QSqlDatabase* CompanyDatabase;
};

#endif
