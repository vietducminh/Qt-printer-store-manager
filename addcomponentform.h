#ifndef ADDCOMPONENTFORM_H
#define ADDCOMPONENTFORM_H
#include"component.h"
#include <QWidget>
#include"databasemanager.h"
#include<QSql>
#include<QSqlRelationalTableModel>

namespace Ui {
class AddComponentForm;
}

class AddComponentForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddComponentForm(QWidget *parent = 0);
    ~AddComponentForm();
    void clearform();
private slots:
    void addComponent();
    void cancelAct();
    void exitForm();


private:
    Ui::AddComponentForm *ui;
    DatabaseManager& databaseManager;
};

#endif // ADDCOMPONENTFORM_H
