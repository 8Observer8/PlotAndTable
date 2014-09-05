#include "CreateTableDialog.h"
#include "ui_CreateTableDialog.h"

CreateTableDialog::CreateTableDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateTableDialog)
{
    ui->setupUi(this);
}

CreateTableDialog::~CreateTableDialog()
{
    delete ui;
}

void CreateTableDialog::on_createButton_clicked()
{
    int nrows = ui->nRowsSpinBox->value();
    emit signalCreateTable( nrows );
}
