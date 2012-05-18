#ifndef CATALOGDIALOG_H
#define CATALOGDIALOG_H

#include <QDialog>
#include <QtSql>

#include "fcatalog.h"
#include "database.h"
#include "scriptbinding.h"

class CatalogDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit CatalogDialog(FCatalog* catalog, QStringList global, QString object, QWidget *parent = 0);
    explicit CatalogDialog(FCatalog* catalog, QStringList global, QString object, QString binding, QScriptEngine *engine, QWidget *parent = 0);
    ~CatalogDialog();
    
private:
    FCatalog* m_catalog;
    QStringList m_global;
    QString m_object;
    QString generateUniqueCode();
    QString m_code;
    QString m_description;
    QString m_bindingCode;
    QScriptEngine *m_engine;

    QPushButton *buttonCreate;
    QGridLayout *layout;
    QList<QLineEdit*> editList;

public slots:
    void slotCreate();
};

#endif // CATALOGDIALOG_H
