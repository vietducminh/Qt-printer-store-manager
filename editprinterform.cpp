#include "editprinterform.h"
#include "ui_editprinterform.h"

EditPrinterForm::EditPrinterForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditPrinterForm)
{
    ui->setupUi(this);
}

EditPrinterForm::~EditPrinterForm()
{
    delete ui;
}
