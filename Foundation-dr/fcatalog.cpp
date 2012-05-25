#include "fcatalog.h"

FCatalog::FCatalog(QObject *parent) :
    QObject(parent)
{
    m_attributes.insert("code", "");
    m_attributes.insert("description", "");
}
void FCatalog::setAttribute(QString type, QVariant value)
{
    m_attributes[type] = value;
}
QMap<QString, QVariant> FCatalog::attributes() const
{
    return m_attributes;
}
bool FCatalog::create(QScriptEngine *eng, QStringList global, QString object)
{
    QScriptValue scrDoc = eng->newQObject(this);
    eng->globalObject().setProperty(this->attributes().value("name").toString(),scrDoc);
    QString code = "";
    for(int i=0;i<global.size();i++){
        QFile file("./scripts/"+global[i]);
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug()<<"Cannot open file for reading";
        }
        else
        {
            QTextStream in(&file);
            qDebug()<<"File was reading";
            code += in.readAll();
        }
    }
    QFile file("./scripts/"+object);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Cannot open file for reading";
    }
    else
    {
        QTextStream in(&file);
        qDebug()<<"File was reading";
        code += in.readAll();
    }
    QScriptValue result = eng->evaluate(code);
    if(result.isError()){
        QMessageBox::critical(0,"Error",result.toString(),QMessageBox::Yes);
        qDebug()<<result.toString();
        return false;
    }
    qDebug()<<code;
    qDebug()<<"All Right Catalog!!!";
    return true;
}
bool FCatalog::create(QScriptEngine *eng, QStringList global, QString object, QString binding)
{
//    QScriptValue scrDoc = eng->newQObject(this);
//    eng->globalObject().setProperty(this->attributes().value("name").toString(),scrDoc);
    QString code = "";

    code += binding;

    for(int i=0;i<global.size();i++){
        QFile file("./scripts/"+global[i]);
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug()<<"Cannot open file for reading";
        }
        else
        {
            QTextStream in(&file);
            qDebug()<<"File was reading";
            code += in.readAll();
        }
    }
    QFile file("./scripts/"+object);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Cannot open file for reading";
    }
    else
    {
        QTextStream in(&file);
        qDebug()<<"File was reading";
        code += in.readAll();
    }
    QScriptValue result = eng->evaluate(code);
    if(result.isError()){
        QMessageBox::critical(0,"Error",result.toString(),QMessageBox::Yes);
        qDebug()<<code;
        qDebug()<<result.toString();
        return false;
    }
    qDebug()<<code;
    qDebug()<<"All Right Catalog was post!!!";
    return true;
}
QString FCatalog::generateBindingOfTheCatalog()
{
    QString code = "";

    QStringList keyList;
    QString name = this->attributes().value("name").toString();
    QMapIterator<QString, QVariant> iterator (this->attributes());
    while(iterator.hasNext())
    {
        iterator.next();
        if(iterator.key() != "name")
        {
            keyList.append(iterator.key());
        }
    }
    code += "function catalog_" + name + "_Binding(x)\n{\n\nthis.object = x;\nthis.map = x.attributes();\n";
    for(int i=0; i<keyList.size(); i++)
    {
        code += "this." + keyList[i] + ";\n";// = Current_" + keyList[i] + ";\n";
    }

    code += "this.Write = function()\n{\n";
    for(int i=0; i<keyList.size(); i++)
    {
        code += "this.object.setAttribute(\"" + keyList[i] + "\", this." + keyList[i] + ");\n";
    }
//    code += "this.object.serializeToTheDB();\n";
    code += "}\n";

    code += "this.GetRef = function()\n{\n";
    code += "return this;\n";
    code += "}\n";

    code += "this.Safe = function()\n{\n";
    for(int i=0; i<keyList.size(); i++)
    {
        code += "this.object.setAttribute(\"" + keyList[i] + "\", this." + keyList[i] + ");\n";
    }
    code += "this.object.serializeToTheDB();\n";
    code += "}\n";


    code += "}\n";
    //code += "var " + name + " = new catalog_" + name + "_Binding(" + name + ");\n";

    QFile file ("./scripts/binding" + name + ".qs");
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream stream (&file);
        stream<<code;
    }
    file.close();

    return code;
}
void FCatalog::serializeToTheDB()
{
    QSqlQuery query;
    QString str = "";
    QString nameTable = this->attributes().value("name").toString();

    str += "insert into _Reference" + nameTable + " (reference, parent, master, mark_removal, predefined, ";

    QMapIterator<QString, QVariant> iterator(this->attributes());
    while(iterator.hasNext()){
        iterator.next();
        str += iterator.key()+", ";
    }
    str.remove(str.size() - 2, 2);
    str += ") values ('null', 'null', 'null', 'false', 'false', ";
    iterator.toFront();
    while(iterator.hasNext()){
        iterator.next();
        str += "'" + iterator.value().toString() + "', ";
    }
    str.remove(str.size() - 2, 2);
    str += ")";
    qDebug()<<str;
    query.exec(str);
    if(!query.isActive()){
        qDebug()<<query.lastError();
    }
<<<<<<< HEAD
    qDebug()<<"Serialization complete!";
=======
    qDebug()<<"Record in ConfigurationDB complete!!!";
>>>>>>> d444a25b28411c8360d892c1ea746de4cba509bf
}
FCatalog* FCatalog::createCopy()
{
    FCatalog* copy = new FCatalog;
    copy->setAttribute("name", this->attributes().value("name").toString());
    QMapIterator<QString, QVariant> iter(this->attributes());
    while(iter.hasNext()){
        iter.next();
        copy->setAttribute(iter.key(), iter.value());
    }
    return copy;
}
