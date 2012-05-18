/********************************************************************************
** Form generated from reading UI file 'catalogdialog.ui'
**
** Created: Wed 16. May 12:30:41 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATALOGDIALOG_H
#define UI_CATALOGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_CatalogDialog
{
public:

    void setupUi(QDialog *CatalogDialog)
    {
        if (CatalogDialog->objectName().isEmpty())
            CatalogDialog->setObjectName(QString::fromUtf8("CatalogDialog"));
        CatalogDialog->resize(400, 300);

        retranslateUi(CatalogDialog);

        QMetaObject::connectSlotsByName(CatalogDialog);
    } // setupUi

    void retranslateUi(QDialog *CatalogDialog)
    {
        CatalogDialog->setWindowTitle(QApplication::translate("CatalogDialog", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CatalogDialog: public Ui_CatalogDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATALOGDIALOG_H
