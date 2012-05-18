#ifndef MODULESCRIPTDIALOG_H
#define MODULESCRIPTDIALOG_H

#include <QDialog>
#include <QtGui>
namespace Ui {
class ModuleScriptDialog;
}

class ModuleScriptDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ModuleScriptDialog(QString filename, QWidget *parent = 0);
    void closeEvent(QCloseEvent *);
    ~ModuleScriptDialog();
    
private:
    Ui::ModuleScriptDialog *ui;
    QString m_filename;
};

#endif // MODULESCRIPTDIALOG_H
