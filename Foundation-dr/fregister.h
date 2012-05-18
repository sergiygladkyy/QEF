#ifndef FREGISTER_H
#define FREGISTER_H
#include <QtGui>
#include <QObject>
#include <QtScript>
#include "scriptmap.h"
class FRegister : public QObject
{
    Q_OBJECT
public:
    explicit FRegister(QObject *parent = 0);
    
signals:
    
public slots:
    void setAttribute(QString type, QVariant value);
    QMap<QString, QVariant> attributes() const;
    FRegister* createCopy();
    QString generateBindingOfTheRegister();
private:
    ScriptMap m_attributes;
    
};

#endif // FREGISTER_H
