#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"printerlistwidget.h"
#include"printerform.h"
#include"componentcheck.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->clickButton,&QPushButton::clicked,this,
            &MainWindow::showPrinterForm);

    ComponentCheck * componentCheck = new ComponentCheck();
    componentCheck->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showPrinterForm()
{
    //PrinterListWidget* list = new PrinterListWidget();
    PrinterForm *printerForm = new PrinterForm();
    printerForm->show();
}

/*
void MainWindow::on_clickButton_clicked()
{
    //PrinterListWidget* list = new PrinterListWidget();
    PrinterForm *printerForm = new PrinterForm();
    printerForm->show();
}
*/
