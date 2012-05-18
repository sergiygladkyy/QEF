#include "files.h"

Files::Files(QObject *parent) :
    QObject(parent)
{
}
QString Files::createScriptFile(QString name,Type::m_type type)
{
    QString filename;
    switch(type)
    {
    case Type::global:
        filename = "Global."+name+".qs";
        break;
    case Type::object:
        filename = name+".Module.qs";
        break;
    case Type::form:
        filename = name+".ItemForm.Module.qs";
        break;
    case Type::log:
        filename = name+".log";
    }
    QFile file("./scripts/"+filename);
    if(!file.open(QIODevice::Append))
    {
        qDebug()<<filename + " is not created";
    }
    else
    {
        qDebug()<<filename + " was created/opened";
    }
    file.close();
    return filename;
}
