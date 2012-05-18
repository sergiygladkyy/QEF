#ifndef DOCUMENTDIALOG_H
#define DOCUMENTDIALOG_H

#include <QtGui>
#include <QDialog>

#include "fdocument.h"
#include "database.h"
#include "scriptbinding.h"

class DocumentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DocumentDialog(FDocument* document, FRegister* regist, QStringList global, QString object, QWidget *parent = 0);
    explicit DocumentDialog(FDocument* document, FRegister* regist, QStringList global, QString object, QScriptEngine *engine, QString binding, QWidget *parent = 0);
    ~DocumentDialog();

private:
    FDocument* m_document;
    FRegister* m_regist;
    QStringList m_global;
    QString m_object;
    QString setCurrrentDatetime();
    QString setUniqueNumber();
    QString m_datetime;
    QString m_number;

    QString m_bindingCode;
    QScriptEngine *m_engine;

    QPushButton *buttonPost;
    QGridLayout *layout;
    QList<QLineEdit*> editList;

public slots:
    void slotPost();
};

#endif // DOCUMENTDIALOG_H
