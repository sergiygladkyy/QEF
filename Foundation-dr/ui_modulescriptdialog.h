/********************************************************************************
** Form generated from reading UI file 'modulescriptdialog.ui'
**
** Created: Mon 14. May 15:55:49 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODULESCRIPTDIALOG_H
#define UI_MODULESCRIPTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ModuleScriptDialog
{
public:
    QTextEdit *textEdit;

    void setupUi(QDialog *ModuleScriptDialog)
    {
        if (ModuleScriptDialog->objectName().isEmpty())
            ModuleScriptDialog->setObjectName(QString::fromUtf8("ModuleScriptDialog"));
        ModuleScriptDialog->resize(607, 417);
        textEdit = new QTextEdit(ModuleScriptDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 611, 421));

        retranslateUi(ModuleScriptDialog);

        QMetaObject::connectSlotsByName(ModuleScriptDialog);
    } // setupUi

    void retranslateUi(QDialog *ModuleScriptDialog)
    {
        ModuleScriptDialog->setWindowTitle(QApplication::translate("ModuleScriptDialog", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ModuleScriptDialog: public Ui_ModuleScriptDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULESCRIPTDIALOG_H
