#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>

#include "fdocument.h"
#include "fregister.h"
#include "fcatalog.h"
#include "files.h"
#include "modulescriptdialog.h"
#include "database.h"
#include "documentdialog.h"
#include "catalogdialog.h"
#include "scriptbinding.h"

namespace Ui {
class MainWindow;
}
class TypeObject
{
public:
    enum type {cat, doc, reg};
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

    //Dictionary
    QList<FDocument*> m_documentList;
    QList<FRegister*> m_registerList;
    QList<FCatalog*> m_catalogList;

    //Modules (Script files)
    QStringList m_global;
    QStringList m_doc_object;
    QStringList m_doc_form;
    QStringList m_cat_object;
    QStringList m_cat_form;

    //Mappers for dynamic creating menu, view
    QSignalMapper* m_scriptMapper;
    QSignalMapper* m_documentMapper;
    QSignalMapper* m_catalogMapper;
    QSignalMapper* m_registerMapper;
    QSignalMapper* m_createDocumentMapper;
    QSignalMapper* m_createCatalogMapper;

    QSqlTableModel* m_tableModel;

    QString m_bindingCode;
    QScriptEngine *m_engine;

    void createProjectFiles();
    void createGlobalModule(QString scriptName);

    //Dynamic setup of the mainwindow widgets
    void setupScriptMenu(QMenu* menu, QStringList& list);
    void setupMenu(QMenu* menu, QSignalMapper* mapper, TypeObject::type type);
    void setupTableModel(QObject* applObject, TypeObject::type type);
    void setupComboBox();

    void setupConnections();

public slots:
    void slotOpenScript(QString filename);
    void slotOpenDocument(QObject* applObject);
    void slotOpenCatalog(QObject* applObject);
    void slotOpenRegister(QObject* applObject);

    //Opening dialog window for creating new document/catalog
    void slotCreateNewDocument(int index);
    void slotComboDocumentActivated(int index);
    void slotCreateNewCatalog(int index);
    void slotComboCatalogActivated(int index);

    //test git with qtcreator
    void function1();
};

#endif // MAINWINDOW_H
