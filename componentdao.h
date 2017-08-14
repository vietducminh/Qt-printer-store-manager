#ifndef COMPONENTDAO_H
#define COMPONENTDAO_H

#include<QtSql/QSqlDatabase>
class Component;

class ComponentDAO
{
public:
    ComponentDAO(QSqlDatabase& database);
    void addComponent(Component& component);
    void editComponent(Component& component);
    void deleteComponent(int id);
    void init();
    QVector<Component> findComponentsbyPrinterId(int printerId);

private:
    QSqlDatabase& mDatabase;
};

#endif // COMPONENTDAO_H
