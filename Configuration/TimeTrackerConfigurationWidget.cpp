#include "TimeTrackerConfigurationWidget.h"

#include "EditCompanyWidget.h"

#include <iostream>

#include <QSqlDatabase>
#include <QFileDialog>
#include <QSqlError>
#include <QSqlQuery>

TimeTrackerConfigurationWidget::TimeTrackerConfigurationWidget(QWidget *parent) : QMainWindow(parent), CompanyDatabase(NULL)
{
  setupUi(this);
}

TimeTrackerConfigurationWidget::~TimeTrackerConfigurationWidget()
{
  if(this->CompanyDatabase)
    {
    delete this->CompanyDatabase;
    this->CompanyDatabase = NULL;
    }
}

void TimeTrackerConfigurationWidget::on_btnNewCompany_clicked()
{
//   QString fileName = QFileDialog::getSaveFileName(this, "Database File", "", "Image Files (*.sqlite)");
// 
//   if(fileName.toStdString().empty())
//     {
//     std::cout << "Filename was empty." << std::endl;
//     return;
//     }

  QString fileName = "test.sqlite";

  if(QFile::exists(fileName))
    {
    std::cerr << "File already exists - Open the company instead." << std::endl;
    return;
    }

  if(this->CompanyDatabase)
    {
    delete this->CompanyDatabase;
    this->CompanyDatabase = NULL;
    }

  QSqlDatabase::removeDatabase("CompanyDatabase");

  this->CompanyDatabase = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
  this->CompanyDatabase->setDatabaseName(fileName);
  if (this->CompanyDatabase->open())
    {
    std::cout << "Opened." << std::endl;
    }
  else
    {
    std::cerr << "Could not open database" << std::endl;
    std::cerr << this->CompanyDatabase->lastError().text().toStdString() << std::endl;
    }
    
  QSqlQuery createQuery(*(this->CompanyDatabase));
  bool createSuccess = createQuery.exec("create table CompanyTable "
              "(id integer primary key, "
              "CompanyName TEXT, "
              "PayrollClientNumber TEXT, "
              "PayDay TEXT, "
              "PayrollFaxNumber TEXT, "
              "MOTD TEXT, "
              "PayrollContact TEXT, "
              "OwnerName TEXT, "
              "CompanyPhone TEXT, "
              "PayrollSubmission TEXT)");

  if(!createSuccess)
    {
    std::cerr << "Could not create table!" << std::endl;
    std::cerr << createQuery.lastError().text().toStdString() << std::endl;
    return;
    }

  // Populate the table with default values
  QSqlQuery insertQuery(*(this->CompanyDatabase));
  insertQuery.prepare("INSERT INTO CompanyTable (id, CompanyName, PayrollClientNumber, PayDay, PayrollFaxNumber, MOTD, PayrollContact, OwnerName, CompanyPhone, PayrollSubmission) "
                "VALUES (:id, :CompanyName, :PayrollClientNumber, :PayDay, :PayrollFaxNumber, :MOTD, :PayrollContact, :OwnerName, :CompanyPhone, :PayrollSubmission)");
  insertQuery.bindValue(":id", 0);
  insertQuery.bindValue(":CompanyName", "CompanyName");
  insertQuery.bindValue(":PayrollClientNumber", "PayrollClientNumber");
  insertQuery.bindValue(":PayDay", "PayDay");
  insertQuery.bindValue(":PayrollFaxNumber", "PayrollFaxNumber");
  insertQuery.bindValue(":MOTD", "MOTD");
  insertQuery.bindValue(":PayrollContact", "PayrollContact");
  insertQuery.bindValue(":OwnerName", "OwnerName");
  insertQuery.bindValue(":CompanyPhone", "CompanyPhone");
  insertQuery.bindValue(":PayrollSubmission", "PayrollSubmission");
  bool insertSuccess = insertQuery.exec();
  if(!insertSuccess)
    {
    std::cerr << "Could not create table!" << std::endl;
    std::cerr << insertQuery.lastError().text().toStdString() << std::endl;
    return;
    }
  
  EditCompanyWidget* editCompanyWidget = new EditCompanyWidget(this->CompanyDatabase);
  editCompanyWidget->exec();
}

void TimeTrackerConfigurationWidget::on_btnEditCompany_clicked()
{
//   QString fileName = QFileDialog::getOpenFileName(this, "Database File", ".", "Image Files (*.sqlite)");
//
//   if(fileName.toStdString().empty())
//     {
//     std::cout << "Filename was empty." << std::endl;
//     return;
//     }

  QString fileName = "test.sqlite";

  if(!QFile::exists(fileName))
    {
    std::cerr << "File does not exist!" << std::endl;
    return;
    }

  if(this->CompanyDatabase)
    {
    delete this->CompanyDatabase;
    this->CompanyDatabase = NULL;
    }

  QSqlDatabase::removeDatabase("CompanyDatabase");
  // Delete all connections
//   for(unsigned int i = 0; i < QSqlDatabase::connectionNames().size(); ++i)
//     {
//     QSqlDatabase::removeDatabase(QSqlDatabase::connectionNames()[i]);
//     }

  this->CompanyDatabase = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE", "CompanyDatabase"));
  //this->CompanyDatabase = QSqlDatabase::addDatabase("QSQLITE");
  this->CompanyDatabase->setDatabaseName(fileName);
  if (!this->CompanyDatabase->open())
    {
    std::cerr << "Could not open database" << std::endl;
    std::cerr << this->CompanyDatabase->lastError().text().toStdString() << std::endl;
    return;
    }

  EditCompanyWidget* editCompanyWidget = new EditCompanyWidget(this->CompanyDatabase);
  editCompanyWidget->exec();
  delete editCompanyWidget;
}
