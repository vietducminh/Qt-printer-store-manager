#ifndef PRINTERMODEL_H
#define PRINTERMODEL_H
#include"databasemanager.h"
#include<QSqlTableModel>

class PrinterModel
{
public:
    PrinterModel();
    void initializeModel(QSqlTableModel *model);
private:
    DatabaseManager& databaseManager;
};

#endif // PRINTERMODEL_H
