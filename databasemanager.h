#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <memory>

#include <QString>

#include "printerdao.h"
#include "componentdao.h"

class QSqlQuery;
class QSqlDatabase;

const QString DATABASE_FILENAME = "/home/viet/printer/printer.db";

class DatabaseManager
{
public:
    static DatabaseManager& instance();
    ~DatabaseManager();

protected:
    DatabaseManager(const QString& path = DATABASE_FILENAME);
     DatabaseManager& operator=(const DatabaseManager& rhs);

private:
    std::unique_ptr<QSqlDatabase> mDatabase;

public:
    PrinterDAO printerDAO;
    ComponentDAO componentDAO;
};

#endif // DATABASEMANAGER_H
