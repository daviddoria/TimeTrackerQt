#ifndef TimeTrackerWidget_H
#define TimeTrackerWidget_H

#include "ui_TimeTrackerWidget.h"

class TimeTrackerWidget : public QMainWindow, private Ui::TimeTrackerWidget
{
        Q_OBJECT
public:
    TimeTrackerWidget(QWidget *parent = 0);

public slots:
    
};

#endif
