#ifndef FCATALOG_H
#define FCATALOG_H

#include <QObject>
#include <QtGui>
#include <QtScript>
#include <QtSql>

#include "scriptmap.h"

class FCatalog : public QObject
{
    Q_OBJECT
public:
    explicit FCatalog(QObject *parent = 0);
    
signals:
    
public slots:
    void setAttribute(QString type, QVariant value);
    QMap<QString, QVariant> attributes() const;
    bool create(QScriptEngine* eng, QStringList global, QString object);
    bool create(QScriptEngine* eng, QStringList global, QString object, QString binding);
    QString generateBindingOfTheCatalog();

    void serializeToTheDB();
    FCatalog* createCopy();
private:
    ScriptMap m_attributes;
    
};

#endif // FCATALOG_H
