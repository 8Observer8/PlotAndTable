#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
    class PlotWindow;
}

class PlotWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PlotWindow(QWidget *parent = 0);
    ~PlotWindow();

public slots:
    void slotUpdatePlot( const QSqlTableModel &model );

private:
    Ui::PlotWindow *ui;
};

#endif // PLOTWINDOW_H
