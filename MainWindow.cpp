#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_plotWindow = new PlotWindow( this );
    m_tableWindow = new TableWindow( this );

    ui->mdiArea->addSubWindow( m_plotWindow );
    ui->mdiArea->addSubWindow( m_tableWindow );

    connect( m_tableWindow, SIGNAL( signalUpdatePlot( QSqlTableModel ) ),
             m_plotWindow, SLOT( slotUpdatePlot( QSqlTableModel ) ) );
}

MainWindow::~MainWindow()
{
    delete ui;
}
