#include "TimeTrackerWidget.h"

#include <iostream>

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QStringList>
#include <QSqlQuery>
#include <QSqlError>
#include <QSettings>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QVariant>
#include <../../../../Test/Header1.h>

TimeTrackerWidget::TimeTrackerWidget(QWidget *parent) : QMainWindow(parent), TableModel(NULL)
{
  setupUi(this);

  // Get the database from the settings. If one has not been opened before, select it.
  QSettings settings("TimeTracker", "TimeTracker");

  QString databaseFile = settings.value("DatabaseFile").toString();

  // If there is no saved database, open one.
  if(databaseFile.isEmpty())
    {
    QMessageBox::warning(this, "Time Tracker",
                               QString(QString("There is no saved company database. (This is probably the first time you are running Time Tracker!) Please select a database file.")),
                               QMessageBox::Ok);
    databaseFile = QFileDialog::getOpenFileName(this, "Open Database", ".", "Database Files (*.sqlite)");
    }

  if(!databaseFile.isEmpty() && !QFile::exists(databaseFile))
    {
    QMessageBox::warning(this, "Time Tracker",
                               QString(QString("The saved company database ") + QString(databaseFile.toStdString().c_str()) + QString(" does not exist. Please choose a different file.")),
                               QMessageBox::Ok);
    databaseFile = QFileDialog::getOpenFileName(this, "Open Database", ".", "Database Files (*.sqlite)");
    }

  // If the database file has still not been selected, quit.
  if(databaseFile.isEmpty())
    {
    QMessageBox::warning(this, "Time Tracker",
                          "You must select a database. Exiting...",
                          QMessageBox::Ok);

    exit(-1);
    }

  std::cout << "Using database file: " << databaseFile.toStdString() << std::endl;
  
  // Save the database
  settings.setValue("DatabaseFile", databaseFile );

  QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
  database.setDatabaseName(databaseFile);
  if(!database.open())
    {
    std::cerr << "Could not open database" << std::endl;
    std::cerr << "Last error: " << database.lastError().text().toStdString() << std::endl;
    }
    
  //QSqlQuery selectQuery;
  //selectQuery.prepare("SELECT AssociateName FROM AssociateTable");

  QSqlQuery selectQuery("SELECT AssociateName FROM AssociateTable");
  
  bool selectSuccess = selectQuery.exec();
  if(!selectSuccess)
    {
    std::cerr << "Error selecting associates!" << std::endl;
    std::cerr << "Last error: " << selectQuery.lastError().text().toStdString() << std::endl;
    return;
    }

  this->TableModel = new QSqlTableModel;
  this->TableModel->setTable("AssociateTable");
  this->TableModel->select();

  this->listView->setModel(this->TableModel);

  this->listView->setModelColumn(1);
}

TimeTrackerWidget::~TimeTrackerWidget()
{
  if(TableModel)
    {
    delete TableModel;
    TableModel = NULL;
    }
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
