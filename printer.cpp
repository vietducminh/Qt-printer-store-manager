#include "printer.h"

Printer::Printer(const QString& name)
    :mId(-1),
      mCode(""),
      mName(name),
      mPrinter_info("")
{

}

int Printer::id()
{
    return mId;
}

void Printer::setId(int id)
{
    mId = id;
}

QString Printer::code()
{
    return mCode;
}

void Printer::setCode(const QString& code)
{
    mCode = code;
}

QString Printer::name()
{
    return mName;
}

void Printer::setName(const QString& name)
{
    mName = name;
}

QString Printer::info()
{
    return mPrinter_info;
}
void Printer::setInfo(const QString& info)
{
    mPrinter_info = info;
}
