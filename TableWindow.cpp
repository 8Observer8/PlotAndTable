
#include <QMessageBox.h>
#include <QFileInfo>
#include "TableWindow.h"
#include "ui_TableWindow.h"
#include "CreateTableDialog.h"

TableWindow::TableWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableWindow)
{
    ui->setupUi(this);

    int nrows = 1;
    slotCreateTable( nrows );

    m_database = QSqlDatabase::addDatabase( "QSQLITE" );

    QString pathToDB = QDir::currentPath() + QString( "/Plot.sqlite" );
    m_database.setDatabaseName( pathToDB );

    QFileInfo checkFile( pathToDB );

    QString message;
    if ( checkFile.isFile() ) {
        if ( m_database.open() ) {
            m_model = new QSqlTableModel( this, m_database );
            m_model->setTable( "PlotTable" );
            m_model->setEditStrategy( QSqlTableModel::OnFieldChange );
            m_model->select();
//            m_model->setHeaderData( 0, Qt::Horizontal, tr( "Id" ) );
//            m_model->setHeaderData( 1, Qt::Horizontal, tr( "Last Name" ) );
//            m_model->setHeaderData( 2, Qt::Horizontal, tr( "First Name" ) );
//            m_model->setHeaderData( 2, Qt::Horizontal, tr( "Patronymic" ) );
//            m_model->setHeaderData( 3, Qt::Horizontal, tr( "Salary" ) );
            ui->tableView->setModel( m_model );
        } else {
            message = tr( "Error: database file was not opened" );
            QMessageBox::information( this, tr( "Error" ),
                                      message );
        }
    } else {
        message = tr( "Error: database file does not exist" );
        QMessageBox::information( this, tr( "Error" ),
                                  message );
    }
}

TableWindow::~TableWindow()
{
    m_database.close();
    delete ui;
}

void TableWindow::on_createTableButton_clicked()
{
    CreateTableDialog dialog;
    dialog.setModal( true );
    connect( &dialog, SIGNAL( signalCreateTable( int ) ),
             this, SLOT( slotCreateTable( int ) ) );
    dialog.exec();
}

void TableWindow::on_addRowButton_clicked()
{

}

void TableWindow::slotCreateTable(int nrows)
{

}

void TableWindow::on_showPlotButton_clicked()
{
    signalUpdatePlot( *m_model );
}
