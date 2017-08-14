#include "printermodel.h"
#include<QtSql>


PrinterModel::PrinterModel():
    databaseManager(DatabaseManager::instance())
{

}

void PrinterModel::initializeModel(QSqlTableModel *model)
{
    model->setTable("printer");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Printer code"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Printer name"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Printer info"));
}
