#include "addprinterform.h"
#include "ui_addprinterform.h"
#include "printerdao.h"
#include"printer.h"

AddPrinterForm::AddPrinterForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddPrinterForm),
    databaseManager(DatabaseManager::instance())

{
    ui->setupUi(this);
    connect(ui->addButton,&QPushButton::clicked,this,
            &AddPrinterForm::addPrinter);
    connect(ui->cancelButton,&QPushButton::clicked,this,
            &AddPrinterForm::cancelAct);
    connect(ui->exitButton,&QPushButton::clicked,this,
            &AddPrinterForm::exitForm);
}

AddPrinterForm::~AddPrinterForm()
{
    delete ui;
}

void AddPrinterForm::addPrinter()
{
    Printer temp;

    temp.setCode(ui->codeEdit->text());
    temp.setName(ui->nameEdit->text());
    temp.setInfo(ui->infoEdit->toPlainText());
    databaseManager.printerDAO.addPrinter(temp);
    clearform();
}
void AddPrinterForm::cancelAct(){
    clearform();
}

void AddPrinterForm::exitForm()
{
    this->close();
}
void AddPrinterForm::clearform()
{
    ui->codeEdit->clear();
    ui->nameEdit->clear();
    ui->infoEdit->clear();
}
