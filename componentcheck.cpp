#include "componentcheck.h"
#include "ui_componentcheck.h"
#include<QDebug>
#include<QFileDialog>
#include<QMessageBox>

ComponentCheck::ComponentCheck(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComponentCheck),
    databaseManager(DatabaseManager::instance())
{
    ui->setupUi(this);

    connect(ui->browseFileButton,&QPushButton::clicked,this,
            &ComponentCheck::browseFile);
    connect(ui->checkButton,&QPushButton::clicked,this,
            &ComponentCheck::checkingAction);
    model = new QSqlTableModel();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setTable("printer");

    // Initialize the printerId combo box
    ui->comboBox->setModel(model);
    ui->comboBox->setModelColumn(2);

    if (!model->select()) {
        qDebug() << "Error in component checking form";
        return;
    }

}

void ComponentCheck::browseFile()
{
    QString fileName =
            QFileDialog::getOpenFileName(this, tr("Open XML File"),
                                         QDir::currentPath(),
                                         tr("XML Files (*.xml)"));
    if (fileName.isEmpty())
        return;

    xmlFile = new QFile(fileName);

    if (!xmlFile->open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Component Checking"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(xmlFile->errorString()));
        return;
    }
    xmlReader = new QXmlStreamReader(xmlFile);

    QString xml = "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
                  "<name>\n"
                  " <id>1</id>\n"
                  "</name>\n";

    QXmlStreamReader reader(xml);
    while(!reader.atEnd() && !reader.hasError()) {
        if(reader.readNext() == QXmlStreamReader::StartElement && reader.name() == "id") {
            qDebug() << reader.readElementText();
        }
    }

    //------------------

    while(!xmlReader->atEnd() && !xmlReader->hasError()) {
            // Read next element
            QXmlStreamReader::TokenType token = xmlReader->readNext();
            //If token is just StartDocument - go to next
            if(token == QXmlStreamReader::StartDocument) {
                    continue;
            }
            //If token is StartElement - read it
            if(token == QXmlStreamReader::StartElement) {
                    if(xmlReader->name() == "name") {
                            continue;
                    }
                    if(xmlReader->name() == "id") {
                        qDebug() << xmlReader->readElementText();
                    }
            }
    }

    if(xmlReader->hasError()) {
            QMessageBox::critical(this,
            "xmlFile.xml Parse Error",xmlReader->errorString(),
            QMessageBox::Ok);
            return;
    }

    //close reader and flush file
    xmlReader->clear();
    xmlFile->close();

}

void ComponentCheck::checkingAction()
{

}

ComponentCheck::~ComponentCheck()
{
    delete ui;
}
