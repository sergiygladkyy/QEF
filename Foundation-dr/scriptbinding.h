#ifndef SCRIPTBINDING_H
#define SCRIPTBINDING_H

#include <QtGui>
#include <QtScript>

#include "fdocument.h";
#include "fcatalog.h"

class ScriptBinding
{
public:
    ScriptBinding();
    static QString generateGlobalBindingOfTheRegisters(QStringList registerList);
    static QString generateGlobalBindingOfTheCatalogs(QStringList catalogList);
    static QString generateGlobalBindingOfTheDocuments(QStringList documentList);

    static void registerAllCatalogs(QScriptEngine* eng, QList<FCatalog*> catalogList);
    static void registerAllDocuments(QScriptEngine* eng, QList<FDocument*> documentList);
    static void registerAllRegisters(QScriptEngine* eng, QList<FRegister*> registerList);

    static QString setCurrentValuesToCatalogAttributes(FCatalog *catalog);
    static QString setCurrentValuesToDocumentAttributes(FDocument *document);
//    static QString setCurrentValuesToRegisterAttributes(FRegister *regist);
    static QString setCurrentRegistrator(FRegister* regist, QString currRegist);

    static QString callWriteforCatalog(FCatalog *catalog);
    static QString callWriteforDocument(FDocument *document);
    static QString callWriteforRegister(FRegister *regist);
};

#endif // SCRIPTBINDING_H
