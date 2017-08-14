#include "component.h"


Component::Component(const QString& name)
    :mId(-1),
      mCode(""),
      mName(name),
      mComponent_info(""),
       mPrinterId(-1)
{

}

int Component::id()
{
    return mId;
}

void Component::setId(int id)
{
    mId = id;
}

QString Component::code()
{
    return mCode;
}

void Component::setCode(const QString& code)
{
    mCode = code;
}

QString Component::name()
{
    return mName;
}

void Component::setName(const QString& name)
{
    mName = name;
}

QString Component::info()
{
    return mComponent_info;
}
void Component::setInfo(const QString& info)
{
    mComponent_info = info;
}

int Component::printerId()
{
    return mPrinterId;
}
void Component::setPrinterId(int printerId)
{
    mPrinterId = printerId;
}
