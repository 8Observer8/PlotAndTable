#-------------------------------------------------
#
# Project created by QtCreator 2014-08-30T17:27:29
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = PlotAndTable
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    PlotWindow.cpp \
    TableWindow.cpp \
    QCustomPlot.cpp \
    CreateTableDialog.cpp

HEADERS  += MainWindow.h \
    PlotWindow.h \
    TableWindow.h \
    QCustomPlot.h \
    CreateTableDialog.h

FORMS    += MainWindow.ui \
    PlotWindow.ui \
    TableWindow.ui \
    CreateTableDialog.ui
