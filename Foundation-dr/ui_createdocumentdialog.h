/********************************************************************************
** Form generated from reading UI file 'createdocumentdialog.ui'
**
** Created: Mon 14. May 15:55:49 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEDOCUMENTDIALOG_H
#define UI_CREATEDOCUMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateDocumentDialog
{
public:
    QPushButton *postButton;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *numberLabel;
    QLabel *label_2;
    QLabel *datetimeLabel;
    QLabel *label_3;
    QLineEdit *currencyEdit;

    void setupUi(QDialog *CreateDocumentDialog)
    {
        if (CreateDocumentDialog->objectName().isEmpty())
            CreateDocumentDialog->setObjectName(QString::fromUtf8("CreateDocumentDialog"));
        CreateDocumentDialog->resize(362, 182);
        postButton = new QPushButton(CreateDocumentDialog);
        postButton->setObjectName(QString::fromUtf8("postButton"));
        postButton->setGeometry(QRect(40, 10, 75, 23));
        widget = new QWidget(CreateDocumentDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 40, 271, 101));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        numberLabel = new QLabel(widget);
        numberLabel->setObjectName(QString::fromUtf8("numberLabel"));

        gridLayout->addWidget(numberLabel, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        datetimeLabel = new QLabel(widget);
        datetimeLabel->setObjectName(QString::fromUtf8("datetimeLabel"));

        gridLayout->addWidget(datetimeLabel, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        currencyEdit = new QLineEdit(widget);
        currencyEdit->setObjectName(QString::fromUtf8("currencyEdit"));

        gridLayout->addWidget(currencyEdit, 2, 1, 1, 1);


        retranslateUi(CreateDocumentDialog);

        QMetaObject::connectSlotsByName(CreateDocumentDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateDocumentDialog)
    {
        CreateDocumentDialog->setWindowTitle(QApplication::translate("CreateDocumentDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        postButton->setText(QApplication::translate("CreateDocumentDialog", "Post", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CreateDocumentDialog", "number", 0, QApplication::UnicodeUTF8));
        numberLabel->setText(QApplication::translate("CreateDocumentDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CreateDocumentDialog", "datetime", 0, QApplication::UnicodeUTF8));
        datetimeLabel->setText(QApplication::translate("CreateDocumentDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CreateDocumentDialog", "currency", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateDocumentDialog: public Ui_CreateDocumentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEDOCUMENTDIALOG_H
