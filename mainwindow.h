#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QStringList>
#include <QTableWidgetItem>
#include <QMainWindow>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QFileDialog>
#include "struct.h"
#include <singlepointofempty.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_openfile_clicked();

    void on_btn_loaddata_clicked();

    void on_pushButton_calculations_clicked();

private:
    Ui::MainWindow *ui;
    dat information ;

    void DrawGrid(QPainter * paint,double shag);
        void DrawGraf(QPainter * paint,double shag);
        void DrawRez();
        void DrawInscription(QPainter * paint,double shag);
        void drawValue(QPainter *paint,double shag);
        void Work_table();
};

#endif // MAINWINDOW_H

