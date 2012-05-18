#ifndef DATABASE_H
#define DATABASE_H

#include <QtGui>
#include <QObject>
#include <QtSql>

#include "fdocument.h"
#include "fregister.h"
#include "fcatalog.h"

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);
    static QString createDataBase();
    static void closeConnection();
    static void createTablesOfTheDocuments(QList<FDocument*>& documents);
    static void createTablesOfTheRegisters(QList<FRegister*>& registers);
    static void createTablesOfTheCatalogs(QList<FCatalog*>& catalogs);
    static void writeDocumentToTheDB(FDocument* document);
    static void writeRegisterToTheDB(FRegister* regist);
    static void writeCatalogToTheDB(FCatalog* catalog);
signals:
    
public slots:
private:
    static QSqlDatabase m_database;
    
};

#endif // DATABASE_H
