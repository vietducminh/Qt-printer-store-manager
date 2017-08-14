#ifndef COMPONENT_H
#define COMPONENT_H

#include <QString>
class Component
{
public:
    explicit Component(const QString& name="");
    int id();
    void setId(int id);
    QString code();
    void setCode(const QString& code);
    QString name();
    void setName(const QString& name);
    QString info();
    void setInfo(const QString& info);

    int printerId();
    void setPrinterId(int printerId);

private:
    int mId;
    QString mCode;
    QString mName;
    QString mComponent_info;

    int mPrinterId;
};

#endif // COMPONENT_H
