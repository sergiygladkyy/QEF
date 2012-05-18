#include "scriptbinding.h"

ScriptBinding::ScriptBinding()
{
}
QString ScriptBinding::generateGlobalBindingOfTheRegisters(QStringList registerList)
{
    QString code ="";

    code += "function movements_Binding()\n{\n";
    for(int i=0; i<registerList.size(); i++)
    {
        code += "this." + registerList[i] + " = new register_" + registerList[i] + "_Binding (" + registerList[i] + ");\n";
    }
    code += "}\n";
    code += "var Movements = new movements_Binding();\n";

    QFile file ("./scripts/bindingMovements.qs");
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream stream (&file);
        stream<<code;
    }
    file.close();

    return code;
}
QString ScriptBinding::generateGlobalBindingOfTheCatalogs(QStringList catalogList)
{
    QString code ="";

    code += "function catalogs_Binding()\n{\n";
    for(int i=0; i<catalogList.size(); i++)
    {
        code += "this." + catalogList[i] + " = new catalog_" + catalogList[i] + "_Binding (" + catalogList[i] + ");\n";
    }
    code += "}\n";
    code += "var Catalogs = new catalogs_Binding();\n";

    QFile file ("./scripts/bindingCatalogs.qs");
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream stream (&file);
        stream<<code;
    }
    file.close();

    return code;
}
QString ScriptBinding::generateGlobalBindingOfTheDocuments(QStringList documentList)
{
    QString code ="";

    code += "function documents_Binding()\n{\n";
    for(int i=0; i<documentList.size(); i++)
    {
        code += "this." + documentList[i] + " = new document_" + documentList[i] + "_Binding (" + documentList[i] + ");\n";
    }
    code += "}\n";
    code += "var Documents = new documents_Binding();\n";

    QFile file ("./scripts/bindingDocuments.qs");
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream stream (&file);
        stream<<code;
    }
    file.close();

    return code;
}
void ScriptBinding::registerAllCatalogs(QScriptEngine *eng, QList<FCatalog *> catalogList)
{
    for(int i=0; i<catalogList.size(); i++)
    {
        eng->globalObject().setProperty(catalogList[i]->attributes().value("name").toString(), eng->newQObject(catalogList[i]));
    }
}
void ScriptBinding::registerAllDocuments(QScriptEngine *eng, QList<FDocument *> documentList)
{
    for(int i=0; i<documentList.size(); i++)
    {
        eng->globalObject().setProperty(documentList[i]->attributes().value("name").toString(), eng->newQObject(documentList[i]));
    }
}
void ScriptBinding::registerAllRegisters(QScriptEngine *eng, QList<FRegister *> registerList)
{
    for(int i=0; i<registerList.size(); i++)
    {
        eng->globalObject().setProperty(registerList[i]->attributes().value("name").toString(), eng->newQObject(registerList[i]));
    }
}
QString ScriptBinding::setCurrentValuesToCatalogAttributes(FCatalog *catalog)
{
    QString code ="";

    QString name = catalog->attributes().value("name").toString();
    QMapIterator<QString, QVariant> iterator(catalog->attributes());
    while(iterator.hasNext())
    {
        iterator.next();
        if(iterator.key() != "name")
        {
            code += "Catalogs." + name + "." + iterator.key() + " = Current_"+iterator.key() + ";\n";
        }
    }

    //code += "Catalogs." + name + ".object.serializeToTheDB();\n";

    qDebug()<<code;
    return code;
}
QString ScriptBinding::setCurrentValuesToDocumentAttributes(FDocument *document)
{
    QString code ="";

    QString name = document->attributes().value("name").toString();
    QMapIterator<QString, QVariant> iterator(document->attributes());
    while(iterator.hasNext())
    {
        iterator.next();
        if(iterator.key() != "name")
        {
            code += "Documents." + name + "." + iterator.key() + " = Current_"+iterator.key() + ";\n";
        }
    }
    qDebug()<<code;
    return code;
}
//QString ScriptBinding::setCurrentValuesToRegisterAttributes(FRegister *regist)
//{
//    QString code ="";

//    QString name = regist->attributes().value("name").toString();
//    QMapIterator<QString, QVariant> iterator(regist->attributes());
//    while(iterator.hasNext())
//    {
//        iterator.next();
//        if(iterator.key() != "name")
//        {
//            code += "Movements." + name + "." + iterator.key() + " = Current_"+iterator.key() + ";\n";
//        }
//    }
//    qDebug()<<code;
//    return code;
//}
QString ScriptBinding::setCurrentRegistrator(FRegister *regist, QString currRegist)
{
    QString code ="";

    QString name = regist->attributes().value("name").toString();

    code += "Movements." + name + ".object.setAttribute(\"registrator\", '" + currRegist + "');\n";
    return code;
}

QString ScriptBinding::callWriteforCatalog(FCatalog *catalog)
{
    QString code ="";

    QString name = catalog->attributes().value("name").toString();

    code += "Catalogs." + name + ".Write();\n";
    return code;
}
QString ScriptBinding::callWriteforDocument(FDocument *document)
{
    QString code ="";

    QString name = document->attributes().value("name").toString();

    code += "Documents." + name + ".Write();\n";
    return code;
}
QString ScriptBinding::callWriteforRegister(FRegister *regist)
{
    QString code ="";

    QString name = regist->attributes().value("name").toString();

    code += "Movements." + name + ".Write();\n";
    return code;
}
