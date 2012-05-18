#include "fdocument.h"

FDocument::FDocument(QObject *parent) :
    QObject(parent)
{
    m_attributes.insert("name","");
    m_attributes.insert("number","");
    m_attributes.insert("datetime","");
}
void FDocument::setAttribute(QString type, QVariant value)
{
    m_attributes[type] = value;
}
bool FDocument::post(QScriptEngine *eng, QStringList global, QString object, QString binding)
{
//    QScriptValue scrDoc = eng->newQObject(this);
//    qDebug()<<this->attributes().value("name").toString();
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
    qDebug()<<code;
    QScriptValue result = eng->evaluate(code);
    if(result.isError()){
        QMessageBox::critical(0,"Error",result.toString(),QMessageBox::Yes);
        qDebug()<<result.toString();
        return false;
    }
    qDebug()<<"All Right Document was post!!!";
    return true;
}
bool FDocument::post(QScriptEngine *eng, QStringList global, QString object)
{
//    QScriptValue scrDoc = eng->newQObject(this);
//    eng->globalObject().setProperty(this->attributes().value("name").toString(),scrDoc);
//    QScriptValue scrReg = eng->newQObject(regist);
//    eng->globalObject().setProperty(regist->attributes().value("name").toString(), scrReg);
    QString code = "";

//    code += this->generateBindingOfTheDocument();
//    code += regist->generateBindingOfTheRegister();
//    QStringList tmpList;
//    tmpList.append(regist->attributes().value("name").toString());
    //code += ScriptBinding::generateGlobalBindingOfTheRegisters(tmpList);

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
    qDebug()<<"All Right!!!";
    //DataBase::writeDocumentToTheDB(this);
    return true;
}

QMap<QString, QVariant> FDocument::attributes() const
{
    return m_attributes;
}
FDocument* FDocument::createCopy()
{
    FDocument* copy = new FDocument;
    copy->setAttribute("name", this->attributes().value("name").toString());
    QMapIterator<QString, QVariant> iter(this->attributes());
    while(iter.hasNext()){
        iter.next();
        copy->setAttribute(iter.key(), iter.value());
    }
    return copy;
}
QString FDocument::generateBindingOfTheDocument()
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
    code += "function document_" + name + "_Binding(x)\n{\n\nthis.object = x;\n";//this.map = x.attributes();\n";
    for(int i=0; i<keyList.size(); i++)
    {
        code += "this." + keyList[i] + ";\n"; // + " = Current_" + keyList[i] + ";\n";
    }

    code += "this.Write = function()\n{\n";
    for(int i=0; i<keyList.size(); i++)
    {
        code += "this.object.setAttribute(\"" + keyList[i] + "\", this." + keyList[i] + ");\n";
    }
    code += "}\n";

    code += "this.Add = function()\n{\n";
    for(int i=0; i<keyList.size(); i++)
    {
        code += "this.object.setAttribute(\"" + keyList[i] + "\", \"\");\n";
    }
    code += "return this;\n";
    code += "}\n";


    code += "}\n";
    //code += "var " + name + " = new document_" + name + "_Binding(" + name + ");\n";

    QFile file ("./scripts/binding" + name + ".qs");
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream stream (&file);
        stream<<code;
    }
    file.close();

    return code;
}
