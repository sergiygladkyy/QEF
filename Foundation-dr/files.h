#ifndef FILES_H
#define FILES_H

#include <QObject>
#include <QtGui>

class Type
{
public:
    enum m_type {global, object, form, log};
};

class Files : public QObject
{
    Q_OBJECT
public:
    explicit Files(QObject *parent = 0);

signals:

public slots:
    static QString createScriptFile(QString name, Type::m_type type);
};

#endif // FILES_H
