#include "addcomponentform.h"
#include "ui_addcomponentform.h"
#include<QDebug>

AddComponentForm::AddComponentForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddComponentForm),
    databaseManager(DatabaseManager::instance())
{
    ui->setupUi(this);
    connect(ui->addButton,&QPushButton::clicked,this,
            &AddComponentForm::addComponent);
    connect(ui->cancelButton,&QPushButton::clicked,this,
            &AddComponentForm::cancelAct);
    connect(ui->exitButton,&QPushButton::clicked,this,
            &AddComponentForm::exitForm);

    QSqlRelationalTableModel* componentModel = new QSqlRelationalTableModel();
    componentModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    componentModel->setTable("component");

    int printerIdx = componentModel->fieldIndex("printerId");
    // Set the relations to the other database tables
    componentModel->setRelation(printerIdx, QSqlRelation("printer", "id", "name"));

    // Initialize the printerId combo box
    ui->comboBox->setModel(componentModel->relationModel(printerIdx));
    ui->comboBox->setModelColumn(componentModel->relationModel(printerIdx)->fieldIndex("name"));

    //ui->comboBox->setModel(componentModel->relationModel(4));
    //ui->comboBox->setModelColumn(2);

    if (!componentModel->select()) {
        qDebug() << "Error in printer form of add component";
        return;
    }

}

AddComponentForm::~AddComponentForm()
{
    delete ui;
}

void AddComponentForm::addComponent()
{
    Component temp;

    temp.setCode(ui->codeEdit->text());
    temp.setName(ui->nameEdit->text());
    temp.setInfo(ui->infoEdit->toPlainText());

    int index = ui->comboBox->currentIndex();
    qDebug() << "combo index: " << index;
    //QString printerName = ui->comboBox->itemData(index).toString();
    QString printerName = ui->comboBox->itemText(index);

    qDebug() << "printerName: " << printerName;

    int printerId = databaseManager.printerDAO.getPrinterIdByName(printerName);

    qDebug() << "printerId: " << printerId;
    temp.setPrinterId(printerId);

    /*
    temp.setPrinterId(ui->comboBox->itemData
                      // index of combobox is started from 0
                      (ui->comboBox->currentIndex()).toInt() + 1);
                      */
    databaseManager.componentDAO.addComponent(temp);
    clearform();
}

void AddComponentForm::cancelAct(){
    clearform();
}

void AddComponentForm::exitForm()
{
    this->close();
}

void AddComponentForm::clearform()
{
    ui->codeEdit->clear();
    ui->nameEdit->clear();
    ui->infoEdit->clear();
}
