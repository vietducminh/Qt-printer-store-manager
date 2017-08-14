#include "printerform.h"
#include "ui_printerform.h"
#include"addprinterform.h"

#include<QDataWidgetMapper>
#include<QDebug>
#include<QMessageBox>

PrinterForm::PrinterForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrinterForm),
    databaseManager(DatabaseManager::instance())
{
    ui->setupUi(this);

    connect(ui->addPrinterButton,&QPushButton::clicked,this,
            &PrinterForm::addPrinter);
    connect(ui->deletePrinterButton,&QPushButton::clicked,this,
            &PrinterForm::deletePrinter);

    connect(ui->addCompButton,&QPushButton::clicked,this,
            &PrinterForm::addComponent);
    connect(ui->deleteCompButton,&QPushButton::clicked,this,
            &PrinterForm::deleteComponent);
    connect(ui->updateCompButton,&QPushButton::clicked,this,
            &PrinterForm::updateComponent);

    connect(ui->reloadButton,&QPushButton::clicked,this,
            &PrinterForm::reloadForm);


    // Create the data model
    model = new QSqlRelationalTableModel(ui->printerTable);

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setTable("printer");

    // Viet: this should be used for componentTable
    /*
    // Remember the indexes of the columns
    //printerIdx = model->fieldIndex("printerId");

    // Set the relations to the other database tables
    model->setRelation(printerIdx, QSqlRelation("authors", "id", "name"));
    model->setRelation(genreIdx, QSqlRelation("genres", "id", "name"));
    */
    // Set the localized header captions

    model->setHeaderData(model->fieldIndex("id"), Qt::Horizontal, tr("PrinterID"));
    model->setHeaderData(model->fieldIndex("code"), Qt::Horizontal, tr("Printer Code"));
    model->setHeaderData(model->fieldIndex("name"), Qt::Horizontal, tr("Name"));
    model->setHeaderData(model->fieldIndex("infor"), Qt::Horizontal, tr("Information"));

    // Populate the model
    if (!model->select()) {
        //showError(model->lastError());
        qDebug() << "Error in printer form";
        return;
    }

    // Set the model and hide the ID column
    ui->printerTable->setModel(model);
    //ui->printerTable->setItemDelegate(new BookDelegate(ui.bookTable));
    ui->printerTable->setColumnHidden(model->fieldIndex("id"), true);
    ui->printerTable->setSelectionMode(QAbstractItemView::SingleSelection);

    QDataWidgetMapper *mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    //mapper->setItemDelegate(new BookDelegate(this));
    mapper->addMapping(ui->printerIdEdit, model->fieldIndex("id"));
    mapper->addMapping(ui->codeEdit, model->fieldIndex("code"));
    mapper->addMapping(ui->nameEdit, model->fieldIndex("name"));
    mapper->addMapping(ui->infoEdit, model->fieldIndex("info"));

    connect(ui->printerTable->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            mapper, SLOT(setCurrentModelIndex(QModelIndex)));

    ui->printerTable->setCurrentIndex(model->index(0, 0));

    connect(ui->printerTable, SIGNAL(clicked(QModelIndex)),
            this, SLOT(componentShow(QModelIndex)));
    connect(ui->printerTable, SIGNAL(activated(QModelIndex)),
           this, SLOT(componentShow(QModelIndex)));

    componentModel = new QSqlRelationalTableModel(ui->componentTable);
    componentModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    componentModel->setTable("component");

    componentModel->setHeaderData(componentModel->fieldIndex("id"), Qt::Horizontal, tr("ComponentID"));
    componentModel->setHeaderData(componentModel->fieldIndex("code"), Qt::Horizontal, tr("Component Code"));
    componentModel->setHeaderData(componentModel->fieldIndex("name"), Qt::Horizontal, tr("Name"));
    componentModel->setHeaderData(componentModel->fieldIndex("infor"), Qt::Horizontal, tr("Information"));

    if (!componentModel->select()) {
        showError(componentModel->lastError());
        qDebug() << "Error in printer form of component";
        return;
    }

    // Set the model and hide the ID column
    ui->componentTable->setModel(componentModel);
    ui->componentTable->setColumnHidden(componentModel->fieldIndex("id"), true);
    ui->componentTable->setSelectionMode(QAbstractItemView::SingleSelection);

}


void PrinterForm::reloadForm()
{

    if (!model->select()) {
        //showError(model->lastError());
        qDebug() << "Error in printer form";
        return;
    }

}

void PrinterForm::updatePrinter()
{
}

void PrinterForm::addPrinter()
{
    AddPrinterForm* addPrinter = new AddPrinterForm();
    addPrinter->show();
}

void PrinterForm::addComponent()
{
    AddComponentForm* addComponent = new AddComponentForm();
    addComponent->show();
}

void PrinterForm::deletePrinter()
{
    QModelIndex index;
    index = ui->printerTable->selectionModel()->currentIndex();

    QSqlRecord record = model->record(index.row());
    int printerId = record.value("id").toInt();

    databaseManager.printerDAO.deletePrinter(printerId);
}

void PrinterForm::deleteComponent()
{
    qDebug() << "before selectionModel";
    // Populate the model

    QModelIndex index;
    index = ui->componentTable->selectionModel()->currentIndex();

   qDebug() << "index: "<< index.row();
    qDebug() << "after selectionModel";

    int componentId;

int i = index.row();
    QSqlRecord record = componentModel->record(i);

    //componentId = componentModel->data(index,0).toInt();
    
    componentId = record.value("id").toInt();

    qDebug() << "id: " << componentId;
    databaseManager.componentDAO.deleteComponent(componentId);
}

void PrinterForm::updateComponent()
{
}
void PrinterForm::componentShow(QModelIndex index)
{

    QSqlRecord record = model->record(index.row());
    QString printerIdString = record.value("id").toString();

    componentModel->setFilter("printerId = "+ printerIdString);

    if (!componentModel->select()) {
        showError(componentModel->lastError());
        qDebug() << "Error in printer form of component";
        return;
   }
}

void PrinterForm::showError(const QSqlError &err)
{
    QMessageBox::critical(this, "Unable to initialize Database",
                "Error initializing database: " + err.text());
}

PrinterForm::~PrinterForm()
{
    delete ui;
}
