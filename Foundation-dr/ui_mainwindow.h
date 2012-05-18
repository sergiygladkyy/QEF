/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 17. May 10:38:08 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCurrency_exchange;
    QAction *actionRecords_of_currency_exchange;
    QAction *actionS;
    QAction *actionConversion;
    QAction *actionCurrency_exchange_2;
    QAction *actionCurrecny_exchange;
    QAction *actionLog_iles;
    QWidget *centralWidget;
    QPushButton *buttonCreateDocument;
    QTableView *tableView;
    QPushButton *buttonCreateCatalog;
    QComboBox *comboBoxCatalogs;
    QComboBox *comboBoxDocuments;
    QLabel *labelConnection;
    QLabel *labelName;
    QMenuBar *menuBar;
    QMenu *menuDocuments;
    QMenu *menuRegisters;
    QMenu *menuScripts;
    QMenu *menuGlobal_modules;
    QMenu *menuObject_modules;
    QMenu *menuForm_modules;
    QMenu *menuCatalogs;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(858, 655);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(false);
        actionCurrency_exchange = new QAction(MainWindow);
        actionCurrency_exchange->setObjectName(QString::fromUtf8("actionCurrency_exchange"));
        actionRecords_of_currency_exchange = new QAction(MainWindow);
        actionRecords_of_currency_exchange->setObjectName(QString::fromUtf8("actionRecords_of_currency_exchange"));
        actionS = new QAction(MainWindow);
        actionS->setObjectName(QString::fromUtf8("actionS"));
        actionConversion = new QAction(MainWindow);
        actionConversion->setObjectName(QString::fromUtf8("actionConversion"));
        actionCurrency_exchange_2 = new QAction(MainWindow);
        actionCurrency_exchange_2->setObjectName(QString::fromUtf8("actionCurrency_exchange_2"));
        actionCurrecny_exchange = new QAction(MainWindow);
        actionCurrecny_exchange->setObjectName(QString::fromUtf8("actionCurrecny_exchange"));
        actionLog_iles = new QAction(MainWindow);
        actionLog_iles->setObjectName(QString::fromUtf8("actionLog_iles"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        buttonCreateDocument = new QPushButton(centralWidget);
        buttonCreateDocument->setObjectName(QString::fromUtf8("buttonCreateDocument"));
        buttonCreateDocument->setGeometry(QRect(20, 70, 101, 31));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 130, 811, 361));
        buttonCreateCatalog = new QPushButton(centralWidget);
        buttonCreateCatalog->setObjectName(QString::fromUtf8("buttonCreateCatalog"));
        buttonCreateCatalog->setGeometry(QRect(20, 20, 101, 31));
        comboBoxCatalogs = new QComboBox(centralWidget);
        comboBoxCatalogs->setObjectName(QString::fromUtf8("comboBoxCatalogs"));
        comboBoxCatalogs->setGeometry(QRect(140, 25, 211, 21));
        comboBoxCatalogs->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        comboBoxDocuments = new QComboBox(centralWidget);
        comboBoxDocuments->setObjectName(QString::fromUtf8("comboBoxDocuments"));
        comboBoxDocuments->setGeometry(QRect(140, 75, 211, 20));
        labelConnection = new QLabel(centralWidget);
        labelConnection->setObjectName(QString::fromUtf8("labelConnection"));
        labelConnection->setGeometry(QRect(30, 530, 281, 41));
        labelName = new QLabel(centralWidget);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        labelName->setGeometry(QRect(570, 70, 231, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 858, 21));
        menuDocuments = new QMenu(menuBar);
        menuDocuments->setObjectName(QString::fromUtf8("menuDocuments"));
        menuRegisters = new QMenu(menuBar);
        menuRegisters->setObjectName(QString::fromUtf8("menuRegisters"));
        menuScripts = new QMenu(menuBar);
        menuScripts->setObjectName(QString::fromUtf8("menuScripts"));
        menuGlobal_modules = new QMenu(menuScripts);
        menuGlobal_modules->setObjectName(QString::fromUtf8("menuGlobal_modules"));
        menuObject_modules = new QMenu(menuScripts);
        menuObject_modules->setObjectName(QString::fromUtf8("menuObject_modules"));
        menuForm_modules = new QMenu(menuScripts);
        menuForm_modules->setObjectName(QString::fromUtf8("menuForm_modules"));
        menuCatalogs = new QMenu(menuBar);
        menuCatalogs->setObjectName(QString::fromUtf8("menuCatalogs"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCatalogs->menuAction());
        menuBar->addAction(menuDocuments->menuAction());
        menuBar->addAction(menuRegisters->menuAction());
        menuBar->addAction(menuScripts->menuAction());
        menuScripts->addAction(menuGlobal_modules->menuAction());
        menuScripts->addAction(menuObject_modules->menuAction());
        menuScripts->addAction(menuForm_modules->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ProofConcept", 0, QApplication::UnicodeUTF8));
        actionCurrency_exchange->setText(QApplication::translate("MainWindow", "Currency exchange", 0, QApplication::UnicodeUTF8));
        actionRecords_of_currency_exchange->setText(QApplication::translate("MainWindow", "Records of currency exchange", 0, QApplication::UnicodeUTF8));
        actionS->setText(QApplication::translate("MainWindow", "s\320\262", 0, QApplication::UnicodeUTF8));
        actionConversion->setText(QApplication::translate("MainWindow", "Conversion", 0, QApplication::UnicodeUTF8));
        actionCurrency_exchange_2->setText(QApplication::translate("MainWindow", "Currency exchange", 0, QApplication::UnicodeUTF8));
        actionCurrecny_exchange->setText(QApplication::translate("MainWindow", "Currecny exchange", 0, QApplication::UnicodeUTF8));
        actionLog_iles->setText(QApplication::translate("MainWindow", "Log-files", 0, QApplication::UnicodeUTF8));
        buttonCreateDocument->setText(QApplication::translate("MainWindow", "Create document", 0, QApplication::UnicodeUTF8));
        buttonCreateCatalog->setText(QApplication::translate("MainWindow", "Create catalog", 0, QApplication::UnicodeUTF8));
        labelConnection->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        labelName->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        menuDocuments->setTitle(QApplication::translate("MainWindow", "Documents", 0, QApplication::UnicodeUTF8));
        menuRegisters->setTitle(QApplication::translate("MainWindow", "Registers", 0, QApplication::UnicodeUTF8));
        menuScripts->setTitle(QApplication::translate("MainWindow", "Scripts", 0, QApplication::UnicodeUTF8));
        menuGlobal_modules->setTitle(QApplication::translate("MainWindow", "Global modules", 0, QApplication::UnicodeUTF8));
        menuObject_modules->setTitle(QApplication::translate("MainWindow", "Object modules", 0, QApplication::UnicodeUTF8));
        menuForm_modules->setTitle(QApplication::translate("MainWindow", "Form modules", 0, QApplication::UnicodeUTF8));
        menuCatalogs->setTitle(QApplication::translate("MainWindow", "Catalogs", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
