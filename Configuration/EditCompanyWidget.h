#ifndef EditCompanyWidget_H
#define EditCompanyWidget_H

#include "ui_EditCompanyWidget.h"

#include <QDialog>
#include <QSqlDatabase>

class QSqlTableModel;

//class EditCompanyWidget : public QWidget, private Ui::NewCompanyWidget
class EditCompanyWidget : public QDialog, private Ui::EditCompanyWidget
{
Q_OBJECT
public:
  //NewCompanyWidget(QWidget *parent = 0);
  EditCompanyWidget(QSqlDatabase*);
  ~EditCompanyWidget();
  
public slots:
  void on_btnSave_clicked();
  void on_btnExit_clicked();

protected:
  QSqlTableModel* Model;
};

#endif
