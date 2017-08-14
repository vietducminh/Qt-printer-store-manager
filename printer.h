#ifndef PRINTER_H
#define PRINTER_H
#include <QString>

class Printer
{
public:
    explicit Printer(const QString& name="");
    int id();
    void setId(int id);
    QString code();
    void setCode(const QString& code);
    QString name();
    void setName(const QString& name);
    QString info();
    void setInfo(const QString& info);

private:
    int mId;
    QString mCode;
    QString mName;
    QString mPrinter_info;
};

#endif // PRINTER_H
