#include "catalogdialog.h"
#include "ui_catalogdialog.h"

CatalogDialog::CatalogDialog(FCatalog *catalog, QStringList global, QString object, QWidget *parent) :
    QDialog(parent)
{
    this->m_catalog = catalog;
    this->m_global = global;
    this->m_object = object;
    this->m_code = generateUniqueCode();
    CatalogDialog::setWindowTitle(m_catalog->attributes().value("name").toString());
    buttonCreate = new QPushButton(tr("Create"),this);
    connect(buttonCreate, SIGNAL(clicked()), this, SLOT(slotCreate()));
    layout = new QGridLayout(this);
    layout->addWidget(buttonCreate);
    QLabel *codeLabel = new QLabel(tr("code: "));
    layout->addWidget(codeLabel, 1, 0);
    QLabel *codeValueLabel = new QLabel(m_code);
    layout->addWidget(codeValueLabel, 1, 1);
    QLabel *descriptionLabel = new QLabel(tr("description: "));
    layout->addWidget(descriptionLabel, 2, 0);
    editList.append(new QLineEdit());
    layout->addWidget(editList[0], 2, 1);
    int row = 3;
    int column = 0;
    int i = 1;
    QMapIterator<QString, QVariant> iterator(m_catalog->attributes());
    while(iterator.hasNext())
    {
        iterator.next();
        if(iterator.key() != "name" && iterator.key() != "code" && iterator.key() != "description")
        {
            column = 0;
            QLabel *tmp = new QLabel(iterator.key() + ": ");
            layout->addWidget(tmp, row, column);
            editList.append(new QLineEdit());
            column = 1;
            layout->addWidget(editList[i], row, column);
            ++i;
            ++row;
        }
    }
    this->setLayout(layout);
}
CatalogDialog::CatalogDialog(FCatalog *catalog, QStringList global, QString object, QString binding, QScriptEngine *engine, QWidget *parent)
{
    this->m_catalog = catalog;
    this->m_global = global;
    this->m_object = object;
    this->m_code = generateUniqueCode();
    this->m_bindingCode = binding;
    this->m_engine = engine;
    CatalogDialog::setWindowTitle(m_catalog->attributes().value("name").toString());
    buttonCreate = new QPushButton(tr("Create"),this);
    connect(buttonCreate, SIGNAL(clicked()), this, SLOT(slotCreate()));
    layout = new QGridLayout(this);
    layout->addWidget(buttonCreate);
    QLabel *codeLabel = new QLabel(tr("code: "));
    layout->addWidget(codeLabel, 1, 0);
    QLabel *codeValueLabel = new QLabel(m_code);
    layout->addWidget(codeValueLabel, 1, 1);
    QLabel *descriptionLabel = new QLabel(tr("description: "));
    layout->addWidget(descriptionLabel, 2, 0);
    editList.append(new QLineEdit());
    layout->addWidget(editList[0], 2, 1);
    int row = 3;
    int column = 0;
    int i = 1;
    QMapIterator<QString, QVariant> iterator(m_catalog->attributes());
    while(iterator.hasNext())
    {
        iterator.next();
        if(iterator.key() != "name" && iterator.key() != "code" && iterator.key() != "description")
        {
            column = 0;
            QLabel *tmp = new QLabel(iterator.key() + ": ");
            layout->addWidget(tmp, row, column);
            editList.append(new QLineEdit());
            column = 1;
            layout->addWidget(editList[i], row, column);
            ++i;
            ++row;
        }
    }
    this->setLayout(layout);
}

CatalogDialog::~CatalogDialog()
{
}
QString CatalogDialog::generateUniqueCode()
{
    int code = 0;
    QSqlQuery query;
    QString nameTable = m_catalog->attributes().value("name").toString();
    QList<int> codeList;
    query.exec("select code from _Reference" + nameTable);
    if(!query.isActive()){
        qDebug()<<query.lastError();
    }
    while(query.next())
    {
        codeList.append(query.value(0).toInt());
    }
    qSort(codeList);
    if(codeList.size() != 0)
    {
        code = ++codeList[codeList.size() - 1];
    }
    return QString::number(code);
}

void CatalogDialog::slotCreate()
{
//    m_catalog->setAttribute("description", editList[0]->text());
//    m_catalog->setAttribute("code", m_code);
//    QScriptEngine *eng = new QScriptEngine();
    QScriptValue scrCode = m_engine->newVariant(m_code);
    m_engine->globalObject().setProperty("Current_code",scrCode);
    QString descrition = editList[0]->text();
    m_engine->globalObject().setProperty("Current_description", m_engine->newVariant(descrition));
    QMapIterator<QString, QVariant> iterator(m_catalog->attributes());
    int i = 1;
    while(iterator.hasNext())
    {
        iterator.next();
        if(iterator.key() != "name" && iterator.key() != "code"  && iterator.key() != "description")
        {
            QString tmp = editList[i]->text();
            m_engine->globalObject().setProperty("Current_" + iterator.key(), m_engine->newVariant(tmp));
//            m_catalog->setAttribute(iterator.key(), tmp);
            ++i;
        }
    }

    m_bindingCode += ScriptBinding::setCurrentValuesToCatalogAttributes(m_catalog);
    m_bindingCode += ScriptBinding::callWriteforCatalog(m_catalog);

    if(m_catalog->create(m_engine, m_global, m_object, m_bindingCode)){
        DataBase::writeCatalogToTheDB(m_catalog);
        this->close();
    }
    else QMessageBox::critical(0,"Error","Wrong script syntax",QMessageBox::Yes);
    this->close();
}
