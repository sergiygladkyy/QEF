#include "modulescriptdialog.h"
#include "ui_modulescriptdialog.h"

ModuleScriptDialog::ModuleScriptDialog(QString filename, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModuleScriptDialog)
{
    this->m_filename = filename;
    ui->setupUi(this);
    ModuleScriptDialog::setWindowTitle(filename);
    QFile file("./scripts/" + this->m_filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<m_filename + " cannot open for reading";
    }
    else
    {
        QTextStream in(&file);
        ui->textEdit->setText(in.readAll());
        qDebug()<<m_filename + " was read";
    }

}

ModuleScriptDialog::~ModuleScriptDialog()
{
    delete ui;
}
void ModuleScriptDialog::closeEvent(QCloseEvent *)
{
    QFile file("./scripts/" + this->m_filename);
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug()<<m_filename + " cannot open";
        return;
    }
    else
    {
        QTextStream out(&file);
        out<<ui->textEdit->toPlainText();
        qDebug()<<m_filename + " module is writen!";
    }
}
