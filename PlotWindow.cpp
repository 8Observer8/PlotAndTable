
#include <QVector>
#include <QSqlRecord>
#include "PlotWindow.h"
#include "ui_PlotWindow.h"

PlotWindow::PlotWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlotWindow)
{
    ui->setupUi(this);
}

PlotWindow::~PlotWindow()
{
    delete ui;
}

void PlotWindow::slotUpdatePlot(const QSqlTableModel &model)
{
    int rowCount = model.rowCount();
    QVector<double> x( rowCount ), y( rowCount ); // initialize with entries 0..100

    QSqlRecord record;
    for ( int row = 0; row < rowCount; ++row ) {
        record = model.record( row );
        x[row] = record.fieldName( 0 ).toDouble();
        y[row] = record.fieldName( 1 ).toDouble();
    }

    // create graph and assign data to it:
    ui->plotWidget->addGraph();
    ui->plotWidget->graph( 0 )->setData( x, y );
    // give the axes some labels:
    ui->plotWidget->xAxis->setLabel( "x" );
    ui->plotWidget->yAxis->setLabel( "y" );
    // set axes ranges, so we see all data:
    ui->plotWidget->xAxis->setRange( -1, 1 );
    ui->plotWidget->yAxis->setRange( 0, 1 );

    ui->plotWidget->update();
}
