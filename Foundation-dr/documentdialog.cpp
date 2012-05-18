#include "documentdialog.h"
#include "ui_documentdialog.h"

DocumentDialog::DocumentDialog(FDocument *document, FRegister *regist, QStringList global, QString object, QWidget *parent) :
    QDialog(parent)
{
    this->m_document = document;
    this->m_regist = regist;
    this->m_global = global;
    this->m_object = object;
    m_datetime = setCurrrentDatetime();
    m_number = setUniqueNumber();
    DocumentDialog::setWindowTitle(m_document->attributes().value("name").toString());
    buttonPost = new QPushButton(tr("Post"),this);
    connect(buttonPost, SIGNAL(clicked()), this, SLOT(slotPost()));
    layout = new QGridLayout(this);
    layout->addWidget(buttonPost);
    QLabel *numberLabel = new QLabel(tr("number: "));
    QLabel *datetimeLabel = new QLabel(tr("datetime: "));
    QLabel *numberValueLabel = new QLabel(m_number);
    QLabel *datetimeValueLabel = new QLabel(m_datetime);
    layout->addWidget(numberLabel, 1, 0);
    layout->addWidget(datetimeLabel, 2, 0);
    layout->addWidget(numberValueLabel, 1, 1);
    layout->addWidget(datetimeValueLabel, 2, 1);
    int row = 3;
    int column = 0;
    int i = 0;
    QMapIterator<QString, QVariant> iterator(m_document->attributes());
    while(iterator.hasNext())
    {
        iterator.next();
        if(iterator.key() != "name" && iterator.key() != "number"  && iterator.key() != "datetime")
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
DocumentDialog::DocumentDialog(FDocument *document, FRegister *regist, QStringList global, QString object, QScriptEngine *engine, QString binding, QWidget *parent) :
    QDialog(parent)
{
    this->m_document = document;
    this->m_regist = regist;
    this->m_global = global;
    this->m_object = object;
    this->m_engine = engine;
    this->m_bindingCode = binding;
    m_datetime = setCurrrentDatetime();
    m_number = setUniqueNumber();
    DocumentDialog::setWindowTitle(m_document->attributes().value("name").toString());
    buttonPost = new QPushButton(tr("Post"),this);
    connect(buttonPost, SIGNAL(clicked()), this, SLOT(slotPost()));
    layout = new QGridLayout(this);
    layout->addWidget(buttonPost);
    QLabel *numberLabel = new QLabel(tr("number: "));
    QLabel *datetimeLabel = new QLabel(tr("datetime: "));
    QLabel *numberValueLabel = new QLabel(m_number);
    QLabel *datetimeValueLabel = new QLabel(m_datetime);
    layout->addWidget(numberLabel, 1, 0);
    layout->addWidget(datetimeLabel, 2, 0);
    layout->addWidget(numberValueLabel, 1, 1);
    layout->addWidget(datetimeValueLabel, 2, 1);
    int row = 3;
    int column = 0;
    int i = 0;
    QMapIterator<QString, QVariant> iterator(m_document->attributes());
    while(iterator.hasNext())
    {
        iterator.next();
        if(iterator.key() != "name" && iterator.key() != "number"  && iterator.key() != "datetime")
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

DocumentDialog::~DocumentDialog()
{
    //delete ui;
}
QString DocumentDialog::setCurrrentDatetime()
{
    QDateTime currDateTime = QDateTime::currentDateTime();
    QString format = "dd.MM.yyyy    hh.mm.ss";
    return currDateTime.toString(format);
}
QString DocumentDialog::setUniqueNumber()
{
    int number = 0;
    QSqlQuery query;
    QString nameTable = m_document->attributes().value("name").toString();
    QList<int> codeList;
    query.exec("select number from _Document" + nameTable);
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
        number = ++codeList[codeList.size() - 1];
    }
    return QString::number(number);

}
void DocumentDialog::slotPost()
{
//    QScriptEngine *eng = new QScriptEngine();
    QScriptValue scrDatetime = m_engine->newVariant(m_datetime);
    QScriptValue scrNumber = m_engine->newVariant(m_number.toInt());
    m_engine->globalObject().setProperty("Current_datetime",scrDatetime);
    m_engine->globalObject().setProperty("Current_number",scrNumber);
//    m_document->setAttribute("number", m_number);
//    m_document->setAttribute("datetime", m_datetime);
    QMapIterator<QString, QVariant> iterator(m_document->attributes());
    int i = 0;
    while(iterator.hasNext())
    {
        iterator.next();
        if(iterator.key() != "name" && iterator.key() != "number"  && iterator.key() != "datetime")
        {
            QString tmp = editList[i]->text();
            m_engine->globalObject().setProperty("Current_" + iterator.key(), m_engine->newVariant(tmp));
//            m_document->setAttribute(iterator.key(), tmp);
            ++i;
        }
    }
//    m_regist->setAttribute("registrator", m_document->attributes().value("name").toString()+" "+m_number+" from "+m_datetime);

    m_bindingCode += ScriptBinding::setCurrentValuesToDocumentAttributes(m_document);
    //ScriptBinding::setCurrentValuesToRegisterAttributes(m_regist);
     m_bindingCode += ScriptBinding::setCurrentRegistrator(m_regist, m_document->attributes().value("name").toString()+" "+m_number+" from "+m_datetime);
     m_bindingCode += ScriptBinding::callWriteforDocument(m_document);
    //m_bindingCode += ScriptBinding::callWriteforRegister(m_regist);

    if(m_document->post(m_engine, m_global, m_object, m_bindingCode)){
        DataBase::writeDocumentToTheDB(m_document);
        DataBase::writeRegisterToTheDB(m_regist);
        this->close();
    }
    else QMessageBox::critical(0,"Error","Wrong script syntax",QMessageBox::Yes);
    this->close();
}
