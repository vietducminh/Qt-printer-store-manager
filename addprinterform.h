#ifndef ADDPRINTERFORM_H
#define ADDPRINTERFORM_H

#include <QWidget>
#include"databasemanager.h"

namespace Ui {
class AddPrinterForm;
}

class AddPrinterForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddPrinterForm(QWidget *parent = 0);
    ~AddPrinterForm();
    void clearform();

private slots:
    //void on_addButton_clicked();
    void cancelAct();
    void addPrinter();
    void exitForm();


private:
    Ui::AddPrinterForm *ui;
    DatabaseManager& databaseManager;
};

#endif // ADDPRINTERFORM_H
