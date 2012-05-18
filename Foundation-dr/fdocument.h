#ifndef FDOCUMENT_H
#define FDOCUMENT_H

#include "scriptmap.h"
#include "fregister.h"
//#include "scriptbinding.h"

#include <QtGui>
#include <QObject>
#include <QtScript>



class DataBase;

class FDocument : public QObject
{
    Q_OBJECT
public:
    explicit FDocument(QObject *parent = 0);

signals:
    
public slots:
    void setAttribute(QString type, QVariant value);
    QMap<QString, QVariant> attributes() const;
    virtual bool post(QScriptEngine *eng, QStringList global, QString object, QString binding);
    virtual bool post(QScriptEngine* eng, QStringList global, QString object);

    FDocument* createCopy();
    QString generateBindingOfTheDocument();
private:
    ScriptMap m_attributes;
};

#endif // FDOCUMENT_H
