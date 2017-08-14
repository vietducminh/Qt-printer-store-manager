#ifndef COMPONENTCHECK_H
#define COMPONENTCHECK_H

#include<QSql>
#include<QSqlTableModel>
#include<databasemanager.h>
#include <QWidget>
#include<QXmlStreamReader>
#include<QFile>

namespace Ui {
class ComponentCheck;
}

class ComponentCheck : public QWidget
{
    Q_OBJECT

public:
    explicit ComponentCheck(QWidget *parent = 0);
    ~ComponentCheck();
    QSqlTableModel* model;
public slots:
    void browseFile();
    void checkingAction();
private:
    Ui::ComponentCheck *ui;
    DatabaseManager& databaseManager;
    QXmlStreamReader* xmlReader;
    QFile* xmlFile;

};

#endif // COMPONENTCHECK_H
