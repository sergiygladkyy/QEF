#include "fregister.h"

FRegister::FRegister(QObject *parent) :
    QObject(parent)
{
    m_attributes.insert("name","");
    m_attributes.insert("registrator", "");
}
void FRegister::setAttribute(QString type, QVariant value)
{
    m_attributes[type] = value;
}
QMap<QString, QVariant> FRegister::attributes() const
{
    return m_attributes;
}
FRegister* FRegister::createCopy()
{
    FRegister* copy = new FRegister;
    QMapIterator<QString, QVariant> iter(this->attributes());
    while(iter.hasNext()){
        iter.next();
        copy->setAttribute(iter.key(), iter.value());
    }
    return copy;
}
QString FRegister::generateBindingOfTheRegister()
{
    QString code = "";

    QStringList keyList;
    QString name = this->attributes().value("name").toString();
    QMapIterator<QString, QVariant> iterator (this->attributes());
    while(iterator.hasNext())
    {
        iterator.next();
        if(iterator.key() != "name" && iterator.key() != "registrator")
        {
            keyList.append(iterator.key());
        }
    }
    code += "function register_" + name + "_Binding(x)\n{\n\nthis.object = x;\nthis.map = x.attributes();\n";
    for(int i=0; i<keyList.size(); i++)
    {
        code += "this." + keyList[i] + ";\n";// + " = Current_" + keyList[i] + ";\n";
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
    //code += "var " + name + " = new register_" + name + "_Binding(" + name + ");\n";

    QFile file ("./scripts/binding" + name + ".qs");
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream stream (&file);
        stream<<code;
    }
    file.close();

    return code;
}
