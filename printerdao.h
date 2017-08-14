#ifndef PRINTERDAO_H
#define PRINTERDAO_H
#include<QtSql/QSqlDatabase>
class Printer;

class PrinterDAO
{
public:
    PrinterDAO(QSqlDatabase& database);
    void addPrinter(Printer& printer);
    void editPrinter(Printer& printer);
    void deletePrinter(int id);
    int getPrinterIdByName(QString printerName);
    void init();
    QVector<Printer> printersList();


private:
    QSqlDatabase& mDatabase;
};

#endif // PRINTERDAO_H
