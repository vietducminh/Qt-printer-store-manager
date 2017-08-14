#ifndef PRINTERLISTWIDGET_H
#define PRINTERLISTWIDGET_H

#include <QWidget>
#include "databasemanager.h"
#include"addprinterform.h"
#include"editprinterform.h"
#include"printermodel.h"
#include <QSql>
#include <QtWidgets>
#include <QSqlTableModel>
#include <QItemSelectionModel>

namespace Ui {
class PrinterListWidget;
}

class PrinterListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PrinterListWidget(QWidget *parent = 0);
    ~PrinterListWidget();
    void setSelectionModel(QItemSelectionModel* selectionModel);

private slots:
    void on_createPrinterButton_clicked();

    void on_pushButton_clicked();

    void on_editButton_clicked();

    void on_editPrinterButton_clicked();

private:
    Ui::PrinterListWidget *ui;
    DatabaseManager& databaseManager;
    PrinterModel *mPrinterModel;    
};

#endif // PRINTERLISTWIDGET_H
