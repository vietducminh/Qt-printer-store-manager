#ifndef EDITPRINTERFORM_H
#define EDITPRINTERFORM_H

#include <QWidget>

namespace Ui {
class EditPrinterForm;
}

class EditPrinterForm : public QWidget
{
    Q_OBJECT

public:
    explicit EditPrinterForm(QWidget *parent = 0);
    ~EditPrinterForm();

private:
    Ui::EditPrinterForm *ui;
};

#endif // EDITPRINTERFORM_H
