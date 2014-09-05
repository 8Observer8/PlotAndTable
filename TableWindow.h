#ifndef TABLEWINDOW_H
#define TABLEWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QSqlTableModel>

namespace Ui {
    class TableWindow;
}

class TableWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TableWindow(QWidget *parent = 0);
    ~TableWindow();

signals:
    void signalUpdatePlot( const QSqlTableModel &model );

private slots:
    void on_createTableButton_clicked();
    void on_addRowButton_clicked();

    void slotCreateTable( int nrows );

    void on_showPlotButton_clicked();

private:
    Ui::TableWindow *ui;
    QSqlDatabase m_database;
    QSqlTableModel *m_model;
};

#endif // TABLEWINDOW_H
