#ifndef CREATETABLEDIALOG_H
#define CREATETABLEDIALOG_H

#include <QDialog>

namespace Ui {
    class CreateTableDialog;
}

class CreateTableDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateTableDialog(QWidget *parent = 0);
    ~CreateTableDialog();

signals:
    void signalCreateTable( int nrows );

private slots:
    void on_createButton_clicked();

private:
    Ui::CreateTableDialog *ui;
};

#endif // CREATETABLEDIALOG_H
