#include "printerlistwidget.h"
#include "ui_printerlistwidget.h"
#include<QVector>
#include<QDebug>
#include "printer.h"

PrinterListWidget::PrinterListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrinterListWidget),
    mPrinterModel(nullptr),    
    databaseManager(DatabaseManager::instance())
{

    ui->setupUi(this);
    QVector<Printer> pVector;
    Printer temp;    
    /*
    temp.setCode("ms2");
    temp.setName("printer2");
    temp.setInfo("This is infor2");
    databaseManager.printerDAO.addPrinter(temp);
    temp.setCode("ms3");
    temp.setName("printer3");
    temp.setInfo("This is infor3");
    databaseManager.printerDAO.addPrinter(temp);
    */

    /*
    pVector = databaseManager.printerDAO.printersList();

    for (int i = 0; i < pVector.size(); ++i) {
        temp = pVector.at(i);
        QListWidgetItem *newItem = new QListWidgetItem;
        newItem->setText(temp.name());
        ui->listWidget->insertItem(i, newItem);
     }
     */
    QSqlTableModel *model = new QSqlTableModel;
    mPrinterModel->initializeModel(model);

    ui->listView->setModel(model);
    ui->listView->setModelColumn(2);
    ui->listView->show();

    //ui->listView->setSelectionModel(mPrinterSelectionModel);
}

PrinterListWidget::~PrinterListWidget()
{
    delete ui;
}

void PrinterListWidget::on_createPrinterButton_clicked()
{
    AddPrinterForm* addForm = new AddPrinterForm();
    addForm->show();
}

void PrinterListWidget::on_pushButton_clicked()
{

}

void PrinterListWidget::on_editButton_clicked()
{

}
void PrinterListWidget::on_editPrinterButton_clicked()
{

}


