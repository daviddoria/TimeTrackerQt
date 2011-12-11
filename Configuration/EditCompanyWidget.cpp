#include "EditCompanyWidget.h"

#include "CompanyModel.h"

#include <iostream>

#include <QSqlDatabase>
#include <QStringList>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QVariant>
#include <QSqlTableModel>
#include <QSqlRecord>
/*
NewCompanyWidget::NewCompanyWidget(QWidget *parent) : QDialog(parent)
{
  setupUi(this);

  //CompanyModel* model = new CompanyModel;
  QSqlTableModel* model = new QSqlTableModel;
  model->setTable("CompanyTable");
  model->setEditStrategy(QSqlTableModel::OnManualSubmit);
  //model->setFilter(QString("id=%1").arg(1));
  //model->select();

  this->tableView->setModel(model);

}
*/

EditCompanyWidget::EditCompanyWidget(QSqlDatabase* database) : QDialog(NULL)
{
  setupUi(this);

  //QSqlTableModel* model = new QSqlTableModel;
  this->Model = new QSqlTableModel(NULL, *database);
  this->Model->setTable("CompanyTable");
  this->Model->setEditStrategy(QSqlTableModel::OnManualSubmit);
  //model->setFilter(QString("id=%1").arg(1));
  this->Model->select();
  
  this->tableView->setModel(this->Model);
}

EditCompanyWidget::~EditCompanyWidget()
{
  if(this->Model)
    {
    std::cout << "destructor Deleting..." << std::endl;
    delete this->Model;
    this->Model = NULL;
    }
}

void EditCompanyWidget::on_btnSave_clicked()
{
  this->Model->submitAll();
  //this->setResult(QDialog::Accepted);
  this->accept();
}

void EditCompanyWidget::on_btnExit_clicked()
{
  this->Model->revertAll();
  if(this->Model)
    {
    std::cout << "btnExit Deleting..." << std::endl;
    delete this->Model;
    this->Model = NULL;
    }
  //this->setResult(QDialog::Rejected);
  this->reject();
}

/*
void MyForm::pushButton_clicked()
{
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("MyDatabase.sqlite");

  if (db.open())
  {
    // Try to locate the contacts database.
    // If it is not available create it.
    if (db.tables().indexOf("people") == -1)
    {
      QSqlQuery query(db);
      bool success = query.exec("create table people "
                  "(id integer primary key, "
                  "name TEXT, "
                  "age integer)");
      if (!success)
        {
        qCritical() << query.lastError();
        }
      else
        {
        std::cout << "Created table" << std::endl;
        }
    }
    else
    {
      std::cout << "Table already exists" << std::endl;
      // NULL = is the keyword for the autoincrement to generate next value

      QSqlQuery insertQuery(db);
      bool success = insertQuery.exec(QString("insert into people values(NULL,'%1','%2')")
      .arg("David").arg(25));
      std::cout << "Successfull insertion? " << success << std::endl;
      if (!success)
        {
        qCritical() << insertQuery.lastError();
        }
      QSqlQuery searchQuery(QString("select * from people where id = %1").arg(1), db);
      if (searchQuery.next())
        {
        std::cout << "id: " << searchQuery.value(0).toInt() << std::endl;
        std::cout << "Name: " << searchQuery.value(1).toString().toStdString() << std::endl;
        std::cout << "age: " << searchQuery.value(2).toInt() << std::endl;
        }

      QSqlTableModel *model = new QSqlTableModel;
      // Set used table
      model->setTable("people");
      model->setEditStrategy(QSqlTableModel::OnManualSubmit);
      // Set where clause
      model->setFilter(QString("id=%1").arg(1));
      model->select();

      // Read result
      QSqlRecord record = model->record();
      std::cout << "count: " << record.count() << std::endl;
      record = model->record(0);
      if (!record.isEmpty())
        {
        std::cout << "id from model: " << record.value(0).toInt() << std::endl;
        std::cout << "Name from model: " << record.value(1).toString().toStdString() << std::endl;
        std::cout << "age from model: " << record.value(2).toInt() << std::endl;
        }

      this->tableView->setModel(model);
    }
  }
  else
  {
    std::cout << "Could not open database" << std::endl;
    qCritical() << db.lastError();
  }


}*/
