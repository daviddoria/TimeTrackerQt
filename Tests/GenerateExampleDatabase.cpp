#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>

#include <iostream>

int main(int argc, char *argv[])
{
  QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
  database.setDatabaseName("test.sqlite");
  if(!database.open())
    {
    std::cerr << "Could not open database" << std::endl;
    std::cerr << "Last error: " << database.lastError().text().toStdString() << std::endl;
    }

  QSqlQuery createAssociateTableQuery;
  bool createAssociateTableSuccess = createAssociateTableQuery.exec("create table AssociateTable "
              "(id integer primary key, "
              "AssociateName TEXT, "
              "SocialSecurityNumber TEXT, "
              "StartingDate TEXT, "
              "AssociateType TEXT, "
              "PIN TEXT)");

  if(createAssociateTableSuccess)
    {
    std::cout << "Associate table created successfully!" << std::endl;
    }
  else
    {
    std::cerr << "Could not create Associate table." << std::endl;
    std::cerr << "Last database error: " << database.lastError().text().toStdString() << std::endl;
    std::cerr << "Last query error: " << createAssociateTableQuery.lastError().text().toStdString() << std::endl;
    }


  // Populate the table with default values
  QSqlQuery insertQuery;
  insertQuery.prepare("INSERT INTO AssociateTable (id, AssociateName, SocialSecurityNumber, StartingDate, AssociateType, PIN) "
                "VALUES (:id, :AssociateName, :SocialSecurityNumber, :StartingDate, :AssociateType, :PIN)");
  insertQuery.bindValue(":id", 0);
  insertQuery.bindValue(":AssociateName", "AssociateName");
  insertQuery.bindValue(":SocialSecurityNumber", "SocialSecurityNumber");
  insertQuery.bindValue(":StartingDate", "StartingDate");
  insertQuery.bindValue(":AssociateType", "AssociateType");
  insertQuery.bindValue(":PIN", "PIN");

  bool insertSuccess = insertQuery.exec();
  if(!insertSuccess)
    {
    std::cerr << "Could not insert values!" << std::endl;
    std::cerr << "insertQuery last error: " << insertQuery.lastError().text().toStdString() << std::endl;
    return -1;
    }
    
  QSqlQuery createCompanyTableQuery;
  bool createCompanyTableSuccess = createCompanyTableQuery.exec("create table CompanyTable "
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

  if(createCompanyTableSuccess)
    {
    std::cout << "Company table created successfully!" << std::endl;
    }
  else
    {
    std::cerr << "Could not create Company table." << std::endl;
    std::cerr << "Last database error: " << database.lastError().text().toStdString() << std::endl;
    std::cerr << "Last query error: " << createCompanyTableQuery.lastError().text().toStdString() << std::endl;
    }
  return 0;
}
