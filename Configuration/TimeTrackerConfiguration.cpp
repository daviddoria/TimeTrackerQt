#include <QApplication>

#include "TimeTrackerConfigurationWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TimeTrackerConfigurationWidget form;

    form.show();
    return app.exec();
}
