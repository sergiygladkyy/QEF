/********************************************************************************
** Form generated from reading UI file 'documentdialog.ui'
**
** Created: Mon 14. May 15:55:49 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCUMENTDIALOG_H
#define UI_DOCUMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DocumentDialog
{
public:
    QPushButton *buttonPost;

    void setupUi(QDialog *DocumentDialog)
    {
        if (DocumentDialog->objectName().isEmpty())
            DocumentDialog->setObjectName(QString::fromUtf8("DocumentDialog"));
        DocumentDialog->resize(400, 300);
        buttonPost = new QPushButton(DocumentDialog);
        buttonPost->setObjectName(QString::fromUtf8("buttonPost"));
        buttonPost->setGeometry(QRect(100, 240, 191, 23));

        retranslateUi(DocumentDialog);

        QMetaObject::connectSlotsByName(DocumentDialog);
    } // setupUi

    void retranslateUi(QDialog *DocumentDialog)
    {
        DocumentDialog->setWindowTitle(QApplication::translate("DocumentDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        buttonPost->setText(QApplication::translate("DocumentDialog", "Post", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DocumentDialog: public Ui_DocumentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCUMENTDIALOG_H
