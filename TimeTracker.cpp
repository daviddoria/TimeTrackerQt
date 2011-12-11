#include <QApplication>

#include "TimeTrackerWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TimeTrackerWidget form;

    form.show();
    return app.exec();
}
