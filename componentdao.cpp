#include "componentdao.h"
#include "component.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include<QDebug>
#include<QVector>

ComponentDAO::ComponentDAO(QSqlDatabase& database) :
    mDatabase(database)
{
    qDebug()<< "Inside componentDao constructor";
}

void ComponentDAO::init()
{
      if (!mDatabase.tables().contains("component")) {
        QSqlQuery query(mDatabase);
        query.exec(QString("CREATE TABLE component")
        + " (id INTEGER PRIMARY KEY AUTOINCREMENT, "
        + "code TEXT, "
        + "name TEXT, "
        + "info TEXT, "
        + "printerId INTEGER)");
        query.exec("INSERT INTO component(code,name,info,printerId) "
                   "values('cp1','component1','This is info',2)");
      }

}


void ComponentDAO::addComponent(Component& component)
{
    QSqlQuery query;
    query.prepare("INSERT INTO component(id,code,name,info,printerId) "
                  "values (:id,:code, :name, :info, :printerId)");
    query.bindValue(":code", component.code());
    query.bindValue(":name", component.name());
    query.bindValue(":info", component.info());
    query.bindValue(":printerId", component.printerId());

    query.exec();
}

void ComponentDAO::deleteComponent(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM component where id=(:id)");
    query.bindValue(":id",id);
    query.exec();
}

void ComponentDAO::editComponent(Component& myComponent)
{
    QSqlQuery query;
    query.prepare("UPDATE component SET code = (:code),"
                  "name =(:name),info=(:info),printerId=(:printerId) where id=(:id)");
    query.bindValue(":id",myComponent.id());
    query.bindValue(":code",myComponent.code());
    query.bindValue(":name",myComponent.name());
    query.bindValue(":info",myComponent.info());
    query.bindValue(":printerId",myComponent.printerId());
    query.exec();
}
QVector<Component> ComponentDAO::findComponentsbyPrinterId(int printerId)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM component where printerId=(:id)");
    query.bindValue(":id",printerId);
    query.exec();

    QVector<Component> comVector;
    Component temp;
    while (query.next()) {
            temp.setId(query.value(0).toInt());
            temp.setCode(query.value(1).toString());
            temp.setName(query.value(2).toString());
            temp.setInfo(query.value(3).toString());
            temp.setPrinterId(query.value(4).toInt());
            comVector.append(temp);
    }
    return comVector;
}
