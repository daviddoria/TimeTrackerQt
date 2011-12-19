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
