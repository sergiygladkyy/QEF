#include "database.h"
QSqlDatabase DataBase::m_database = QSqlDatabase::addDatabase("QSQLITE");
DataBase::DataBase(QObject *parent) :
    QObject(parent)
{
}
QString DataBase::createDataBase()
{
    m_database.setDatabaseName("ConfigurationDB.sqlite");
    if (!m_database.open()) {
          qDebug() << m_database.lastError().text();
          return m_database.lastError().text();
    }
    else qDebug()<<"Connection to ConfigurationDB.sqlite is ok";
    return "Connection to ConfigurationDB.sqlite is ok";
}
void DataBase::closeConnection()
{
    if(m_database.isOpen()){
        m_database.close();
    }
}
void DataBase::createTablesOfTheDocuments(QList<FDocument *>& documents)
{
    QSqlQuery query;
    QString queryString = "";
    for(int i=0; i<documents.size(); i++){
        queryString = "create table _Document" + documents[i]->attributes().value("name").toString() + " (reference text, mark_removal text, is_post text, ";
        QMapIterator<QString, QVariant> iter(documents[i]->attributes());
        while(iter.hasNext()){
            iter.next();
            queryString += iter.key() +" text, ";
        }
        queryString.remove(queryString.size() - 2, 2);
        queryString += ")";
        query.exec(queryString);
        qDebug()<<queryString;
        if(!query.isActive()){
            qDebug()<<query.lastError();
        }
        queryString = "";
    }
}
void DataBase::createTablesOfTheRegisters(QList<FRegister *> &registers)
{
    QSqlQuery query;
    QString queryString = "";
    for(int i=0; i<registers.size(); i++){
        queryString = "create table _InfoReg" + registers[i]->attributes().value("name").toString() + " (reference text, ";
        QMapIterator<QString, QVariant> iter(registers[i]->attributes());
        while(iter.hasNext()){
            iter.next();
            queryString += iter.key() +" text, ";
        }
        queryString.remove(queryString.size() - 2, 2);
        queryString += ")";
        query.exec(queryString);
        qDebug()<<queryString;
        if(!query.isActive()){
            qDebug()<<query.lastError();
        }
        queryString = "";
    }
}
void DataBase::createTablesOfTheCatalogs(QList<FCatalog *> &catalogs)
{
    QSqlQuery query;
    QString queryString = "";
    for(int i=0; i<catalogs.size(); i++){
        queryString = "create table _Reference" + catalogs[i]->attributes().value("name").toString() + " (reference text, parent text, master text, mark_removal text, predefined text, ";
        QMapIterator<QString, QVariant> iter(catalogs[i]->attributes());
        while(iter.hasNext()){
            iter.next();
            queryString += iter.key() +" text, ";
        }
        queryString.remove(queryString.size() - 2, 2);
        queryString += ")";
        query.exec(queryString);
        qDebug()<<queryString;
        if(!query.isActive()){
            qDebug()<<query.lastError();
        }
        queryString = "";
    }
}
void DataBase::writeDocumentToTheDB(FDocument *document)
{
    QSqlQuery query;
    QString queryString = "insert into _Document" + document->attributes().value("name").toString() + " (reference , mark_removal, is_post, ";
    QMapIterator<QString, QVariant> iter(document->attributes());
    while(iter.hasNext()){
        iter.next();
        queryString += iter.key()+", ";
    }
    queryString.remove(queryString.size() - 2, 2);
    queryString += ") values ('null', 'false', 'true', ";
    iter.toFront();
    while(iter.hasNext()){
        iter.next();
        queryString += "'" + iter.value().toString() + "', ";
    }
    queryString.remove(queryString.size() - 2, 2);
    queryString += ")";
    qDebug()<<queryString;
    query.exec(queryString);
    if(!query.isActive()){
        qDebug()<<query.lastError();
    }
}
void DataBase::writeRegisterToTheDB(FRegister *regist)
{
    QSqlQuery query;
    QString queryString = "insert into _InfoReg" + regist->attributes().value("name").toString() + " (reference , ";
    QMapIterator<QString, QVariant> iter(regist->attributes());
    while(iter.hasNext()){
        iter.next();
        queryString += iter.key()+", ";
    }
    queryString.remove(queryString.size() - 2, 2);
    queryString += ") values ('null', ";
    iter.toFront();
    while(iter.hasNext()){
        iter.next();
        queryString += "'" + iter.value().toString() + "', ";
    }
    queryString.remove(queryString.size() - 2, 2);
    queryString += ")";
    qDebug()<<queryString;
    query.exec(queryString);
    if(!query.isActive()){
        qDebug()<<query.lastError();
    }
}
void DataBase::writeCatalogToTheDB(FCatalog *catalog)
{
    QSqlQuery query;
    QString queryString = "insert into _Reference" + catalog->attributes().value("name").toString() + " (reference, parent, master, mark_removal, predefined, ";
    QMapIterator<QString, QVariant> iter(catalog->attributes());
    while(iter.hasNext()){
        iter.next();
        queryString += iter.key()+", ";
    }
    queryString.remove(queryString.size() - 2, 2);
    queryString += ") values ('null', 'null', 'null', 'false', 'false', ";
    iter.toFront();
    while(iter.hasNext()){
        iter.next();
        queryString += "'" + iter.value().toString() + "', ";
    }
    queryString.remove(queryString.size() - 2, 2);
    queryString += ")";
    qDebug()<<queryString;
    query.exec(queryString);
    if(!query.isActive()){
        qDebug()<<query.lastError();
    }
}
