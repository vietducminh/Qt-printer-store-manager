#include "printerdao.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "printer.h"
#include <QDebug>
#include <QVector>


PrinterDAO::PrinterDAO(QSqlDatabase& database) :
    mDatabase(database)
{
}

QVector<Printer> PrinterDAO::printersList()
{
    QSqlQuery query;
    QVector<Printer> printersVector;
    query.exec("SELECT id, code, name, info FROM printer");
    while (query.next()) {
        Printer temp;
        temp.setId(query.value(0).toInt());
        temp.setCode(query.value(1).toString());
        temp.setName(query.value(2).toString());
        temp.setInfo(query.value(3).toString());

        printersVector.append(temp);
     }
    return printersVector;
}

void PrinterDAO::init()
{
    if (!mDatabase.tables().contains("printer")) {
      QSqlQuery query(mDatabase);
      query.exec(QString("CREATE TABLE printer")
      + " (id INTEGER PRIMARY KEY AUTOINCREMENT, "
      + "code TEXT, "
      + "name TEXT, "
      + "info TEXT)");
      query.exec("INSERT INTO printer(code,name,info) "
                 "values('ms1','printer1','This is info')");      
    }



}
void PrinterDAO::addPrinter(Printer& printer)
{
    QSqlQuery query;
    query.prepare("INSERT INTO printer(id,code,name,info) "
                  "values (:id,:code, :name, :info)");
    query.bindValue(":code", printer.code());
    query.bindValue(":name", printer.name());
    query.bindValue(":info", printer.info());

    query.exec();
}

void PrinterDAO::deletePrinter(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM printer where id=(:id)");
    query.bindValue(":id",id);
    query.exec();
}

void PrinterDAO::editPrinter(Printer& myPrinter)
{
    QSqlQuery query;
    query.prepare("UPDATE printer SET code = (:code),"
                  "name =(:name),info=(:info) where id=(:id)");
    query.bindValue(":id",myPrinter.id());
    query.bindValue(":code",myPrinter.code());
    query.bindValue(":name",myPrinter.name());
    query.bindValue(":info",myPrinter.info());
    query.exec();
}

int PrinterDAO::getPrinterIdByName(QString printerName)
{
    QSqlQuery query;
    query.prepare("SELECT id FROM printer where name=(:name)");
    query.bindValue(":name",printerName);
    query.exec();

    while (query.next()) {
        return query.value(0).toInt();
     }

}
