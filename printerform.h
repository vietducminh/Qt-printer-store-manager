#ifndef PRINTERFORM_H
#define PRINTERFORM_H

#include <QWidget>
#include <QtSql>
#include"databasemanager.h"
#include"addcomponentform.h"

namespace Ui {
class PrinterForm;
}

class PrinterForm : public QWidget
{
    Q_OBJECT

public:
    explicit PrinterForm(QWidget *parent = 0);
    ~PrinterForm();
    void updatePrinter();
    void showError(const QSqlError &err);

public slots:
    void addPrinter();    
    void deletePrinter();
    void addComponent();
    void deleteComponent();
    void updateComponent();
    void reloadForm();
    void componentShow(QModelIndex);

private:
    Ui::PrinterForm *ui;
    DatabaseManager& databaseManager;
    QSqlRelationalTableModel *model;
    QSqlRelationalTableModel *componentModel;
    int authorIdx, genreIdx;
};

#endif // PRINTERFORM_H
