#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_scriptMapper = new QSignalMapper(this);
    m_documentMapper = new QSignalMapper(this);
    m_catalogMapper = new QSignalMapper(this);
    m_registerMapper = new QSignalMapper(this);
    m_createDocumentMapper = new QSignalMapper(this);
    m_createCatalogMapper = new QSignalMapper(this);


    connect(m_scriptMapper, SIGNAL(mapped(QString)), this, SLOT(slotOpenScript(QString)));
    connect(m_documentMapper, SIGNAL(mapped(QObject*)), this, SLOT(slotOpenDocument(QObject*)));
    connect(m_catalogMapper, SIGNAL(mapped(QObject*)), this, SLOT(slotOpenCatalog(QObject*)));
    connect(m_registerMapper, SIGNAL(mapped(QObject*)), this, SLOT(slotOpenRegister(QObject*)));

    connect(m_createDocumentMapper, SIGNAL(mapped(int)), this, SLOT(slotCreateNewDocument(int)));
    connect(ui->buttonCreateDocument, SIGNAL(clicked()), m_createDocumentMapper, SLOT(map()));
    connect(ui->comboBoxDocuments, SIGNAL(activated(int)), this, SLOT(slotComboDocumentActivated(int)));
    m_createDocumentMapper->setMapping(ui->buttonCreateDocument, 0);
    connect(m_createCatalogMapper, SIGNAL(mapped(int)), this, SLOT(slotCreateNewCatalog(int)));
    connect(ui->buttonCreateCatalog, SIGNAL(clicked()), m_createCatalogMapper, SLOT(map()));
    connect(ui->comboBoxCatalogs, SIGNAL(activated(int)), this, SLOT(slotComboCatalogActivated(int)));
    m_createCatalogMapper->setMapping(ui->buttonCreateCatalog, 0);


//------------Place for creating documents/catalogs/registers-------------
    FDocument *doc1 = new FDocument;
    doc1->setAttribute("name", "Currency_exchange");
    doc1->setAttribute("currency","");
    m_documentList.push_back(doc1);
    FDocument *doc2 = new FDocument;
    doc2->setAttribute("name", "Car_order");
    doc2->setAttribute("model","");
    doc2->setAttribute("price","");
    doc2->setAttribute("year","");
    m_documentList.push_back(doc2);
    FDocument *doc3 = new FDocument;
    doc3->setAttribute("name", "Reception");
    doc3->setAttribute("l_name","");
    doc3->setAttribute("s_name","");
    doc3->setAttribute("age","");
    doc3->setAttribute("country","");
    m_documentList.push_back(doc3);

    FRegister *reg1= new FRegister;
    reg1->setAttribute("name", "Records_Currency_exchange");
    reg1->setAttribute("currency_before","");
    reg1->setAttribute("currency_after","");
    m_registerList.push_back(reg1);
    FRegister *reg2 = new FRegister;
    reg2->setAttribute("name", "Records_Car_order");
    reg2->setAttribute("model","");
    reg2->setAttribute("price","");
    reg2->setAttribute("year","");
    m_registerList.push_back(reg2);
    FRegister *reg3 = new FRegister;
    reg3->setAttribute("name", "Records_Reception");
    reg3->setAttribute("l_name","");
    reg3->setAttribute("s_name","");
    reg3->setAttribute("age","");
    reg3->setAttribute("country","");
    m_registerList.push_back(reg3);

    FCatalog *cat1 = new FCatalog;
    cat1->setAttribute("name","Persons");
    cat1->setAttribute("f_name","");
    cat1->setAttribute("l_name","");
    cat1->setAttribute("age","");
    m_catalogList.push_back(cat1);
    FCatalog *cat2 = new FCatalog;
    cat2->setAttribute("name","Colors");
    m_catalogList.push_back(cat2);
    FCatalog *cat3 = new FCatalog;
    cat3->setAttribute("name", "newCars");
    cat3->setAttribute("year_of_production","");
    m_catalogList.push_back(cat3);
//------------------------------------------------------------------------


//-------------Place for creating Global Modules--------------------------

    createGlobalModule("Conversion");

//------------------------------------------------------------------------

    createProjectFiles();

    setupScriptMenu(ui->menuGlobal_modules, m_global);
    setupScriptMenu(ui->menuObject_modules, m_doc_object);
    setupScriptMenu(ui->menuObject_modules, m_cat_object);
    setupScriptMenu(ui->menuForm_modules, m_doc_form);
    setupScriptMenu(ui->menuForm_modules, m_cat_form);
    setupMenu(ui->menuCatalogs, m_catalogMapper, TypeObject::cat);
    setupMenu(ui->menuDocuments, m_documentMapper, TypeObject::doc);
    setupMenu(ui->menuRegisters, m_registerMapper, TypeObject::reg);

    ui->labelConnection->setText(DataBase::createDataBase());
    DataBase::createTablesOfTheDocuments(m_documentList);
    DataBase::createTablesOfTheRegisters(m_registerList);
    DataBase::createTablesOfTheCatalogs(m_catalogList);

    m_tableModel = new QSqlTableModel(this);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    setupTableModel(m_documentList[0], TypeObject::doc);
    ui->tableView->setModel(m_tableModel);
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(1);
    ui->tableView->hideColumn(2);
    ui->tableView->resizeColumnsToContents();
    ui->labelName->setText(m_documentList[0]->attributes().value("name").toString());

    setupComboBox();


//-----Creating global binding code for using in Qt Script---------------------

    m_engine = new QScriptEngine();
    registerScriptMetaTypes(m_engine);
    ScriptBinding::registerAllCatalogs(m_engine, m_catalogList);
    ScriptBinding::registerAllDocuments(m_engine, m_documentList);
    ScriptBinding::registerAllRegisters(m_engine, m_registerList);
    QStringList catNameList;
    QStringList docNameList;
    QStringList regNameList;

    for(int i=0; i <m_catalogList.size(); i++)
    {
        m_bindingCode += m_catalogList[i]->generateBindingOfTheCatalog();
        catNameList.append(m_catalogList[i]->attributes().value("name").toString());
    }
    for(int i=0; i <m_documentList.size(); i++)
    {
        m_bindingCode += m_documentList[i]->generateBindingOfTheDocument();
        docNameList.append(m_documentList[i]->attributes().value("name").toString());
    }
    for(int i=0; i <m_registerList.size(); i++)
    {
        m_bindingCode += m_registerList[i]->generateBindingOfTheRegister();
        regNameList.append(m_registerList[i]->attributes().value("name").toString());
    }


    m_bindingCode += ScriptBinding::generateGlobalBindingOfTheCatalogs(catNameList);
    m_bindingCode += ScriptBinding::generateGlobalBindingOfTheDocuments(docNameList);
    m_bindingCode += ScriptBinding::generateGlobalBindingOfTheRegisters(regNameList);
    QFile file ("./scripts/bindingCode.qs");
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream stream (&file);
        stream<<m_bindingCode;
    }
    file.close();
//    QScriptValue result = m_engine->evaluate(m_bindingCode);
//    if(result.isError()){
//        qDebug()<<result.toString();
//    }
//    else qDebug()<<"Binding code is valid!";

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::createProjectFiles()
{
    for(int i=0; i<m_catalogList.size(); i++){
        m_cat_object.append(Files::createScriptFile(m_catalogList[i]->attributes().value("name").toString(), Type::object));
        m_cat_form.append(Files::createScriptFile(m_catalogList[i]->attributes().value("name").toString(), Type::form));
    }
    for(int i=0; i<m_documentList.size(); i++){
        m_doc_object.append(Files::createScriptFile(m_documentList[i]->attributes().value("name").toString(), Type::object));
        m_doc_form.append(Files::createScriptFile(m_documentList[i]->attributes().value("name").toString(), Type::form));
    }
}
void MainWindow::createGlobalModule(QString scriptName)
{
    m_global.append(Files::createScriptFile(scriptName, Type::global));
}

void MainWindow::setupScriptMenu(QMenu *menu, QStringList &list)
{
    QList<QAction*> openScriptAct;
    for(int i=0;i<list.size();i++)
    {
        openScriptAct.push_back(new QAction(list[i],this));
        m_scriptMapper->setMapping(openScriptAct[i], list[i]);
        connect(openScriptAct[i],SIGNAL(triggered()),m_scriptMapper,SLOT(map()));
        menu->addAction(openScriptAct[i]);
    }
}
void MainWindow::slotOpenScript(QString filename)
{
    ModuleScriptDialog *dialog = new ModuleScriptDialog(filename, this);
    dialog->show();
}

void MainWindow::setupMenu(QMenu *menu, QSignalMapper *mapper, TypeObject::type type)
{
    QList<QAction*> actList;
    switch(type)
    {
    case TypeObject::cat:
        for(int i=0; i<m_catalogList.size(); i++){
            actList.push_back(new QAction(m_catalogList[i]->attributes().value("name").toString(), this));
            mapper->setMapping(actList[i], m_catalogList[i]);
            connect(actList[i], SIGNAL(triggered()), mapper, SLOT(map()));
        }
        menu->addActions(actList);
        break;
    case TypeObject::doc:
        for(int i=0; i<m_documentList.size(); i++){
            actList.push_back(new QAction(m_documentList[i]->attributes().value("name").toString(), this));
            mapper->setMapping(actList[i], m_documentList[i]);
            connect(actList[i], SIGNAL(triggered()), mapper, SLOT(map()));
        }
        menu->addActions(actList);
        break;
    case TypeObject::reg:
        for(int i=0; i<m_registerList.size(); i++){
            actList.push_back(new QAction(m_registerList[i]->attributes().value("name").toString(), this));
            mapper->setMapping(actList[i], m_registerList[i]);
            connect(actList[i], SIGNAL(triggered()), mapper, SLOT(map()));
        }
        menu->addActions(actList);
        break;
    }
}
void MainWindow::slotOpenDocument(QObject *applObject)
{
    setupTableModel(applObject, TypeObject::doc);
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(1);
    ui->tableView->hideColumn(2);
    ui->tableView->resizeColumnsToContents();
}
void MainWindow::slotOpenCatalog(QObject *applObject)
{
    setupTableModel(applObject, TypeObject::cat);
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(1);
    ui->tableView->hideColumn(2);
    ui->tableView->hideColumn(3);
    ui->tableView->hideColumn(4);
    ui->tableView->resizeColumnsToContents();
}
void MainWindow::slotOpenRegister(QObject *applObject)
{
    setupTableModel(applObject, TypeObject::reg);
    ui->tableView->hideColumn(0);
    ui->tableView->resizeColumnsToContents();

}
void MainWindow::setupTableModel(QObject *applObject, TypeObject::type type)
{
    FDocument* document;
    FCatalog* catalog;
    FRegister* regist;
    QMap<QString, QVariant> fictionMap;
    QMapIterator<QString, QVariant> iterator(fictionMap);
    int column;
    switch(type)
    {
    case TypeObject::doc:
        document = dynamic_cast<FDocument*>(applObject);
        m_tableModel->setTable("_Document" + document->attributes().value("name").toString());
        m_tableModel->setHeaderData(0, Qt::Horizontal, (tr("reference")));
        m_tableModel->setHeaderData(1, Qt::Horizontal, (tr("mark_removal")));
        m_tableModel->setHeaderData(2, Qt::Horizontal, (tr("is_post")));
        iterator = document->attributes();
        column = 3;
        while(iterator.hasNext()){
            iterator.next();
            m_tableModel->setHeaderData(column, Qt::Horizontal, iterator.key());
            ++column;
        }
        m_tableModel->select();
        ui->labelName->setText(document->attributes().value("name").toString());
        break;
    case TypeObject::cat:
        catalog = dynamic_cast<FCatalog*>(applObject);
        m_tableModel->setTable("_Reference" + catalog->attributes().value("name").toString());
        m_tableModel->setHeaderData(0, Qt::Horizontal, (tr("reference")));
        m_tableModel->setHeaderData(1, Qt::Horizontal, (tr("parent")));
        m_tableModel->setHeaderData(2, Qt::Horizontal, (tr("master")));
        m_tableModel->setHeaderData(3, Qt::Horizontal, (tr("mark_removal")));
        m_tableModel->setHeaderData(4, Qt::Horizontal, (tr("predefined")));
        iterator = catalog->attributes();
        column = 5;
        while(iterator.hasNext()){
            iterator.next();
            m_tableModel->setHeaderData(column, Qt::Horizontal, iterator.key());
            ++column;
        }
        m_tableModel->select();
        ui->labelName->setText(catalog->attributes().value("name").toString());
        break;
    case TypeObject::reg:
        regist = dynamic_cast<FRegister*>(applObject);
        m_tableModel->setTable("_InfoReg" + regist->attributes().value("name").toString());
        m_tableModel->setHeaderData(0, Qt::Horizontal, (tr("reference")));
        iterator = regist->attributes();
        column = 1;
        while(iterator.hasNext()){
            iterator.next();
            m_tableModel->setHeaderData(column, Qt::Horizontal, iterator.key());
            ++column;
        }
        m_tableModel->select();
        ui->labelName->setText(regist->attributes().value("name").toString());
        break;
    }
}
void MainWindow::setupComboBox()
{
    for(int i=0; i<m_catalogList.size(); i++)
    {
        ui->comboBoxCatalogs->addItem(m_catalogList[i]->attributes().value("name").toString());
    }
    for(int i=0; i <m_documentList.size(); i++)
    {
        ui->comboBoxDocuments->addItem(m_documentList[i]->attributes().value("name").toString());
    }
}
void MainWindow::slotCreateNewDocument(int index)
{
    DocumentDialog *dialog = new DocumentDialog(m_documentList[index], m_registerList[index], m_global, m_doc_object[index],m_engine, m_bindingCode, this);
    dialog->exec();
    slotOpenDocument(m_documentList[index]);
}
void MainWindow::slotComboDocumentActivated(int index)
{
    m_createDocumentMapper->setMapping(ui->buttonCreateDocument, index);
}
void MainWindow::slotCreateNewCatalog(int index)
{
    CatalogDialog *dialog = new CatalogDialog(m_catalogList[index], m_global, m_cat_object[index], m_bindingCode, m_engine, this);
    dialog->exec();
    slotOpenCatalog(m_catalogList[index]);
}
void MainWindow::slotComboCatalogActivated(int index)
{
    m_createCatalogMapper->setMapping(ui->buttonCreateCatalog, index);
}
