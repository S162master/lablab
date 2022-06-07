#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "readfile.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    free(information.massivdata);
    delete ui;
}




void MainWindow::on_btn_openfile_clicked()
{
    QString path_file;
    if (ui->linePathFile->text() == ""){
       path_file = QFileDialog::getOpenFileName(this, tr("Open File"), "C://", "All files(*.*);;Table File(*.csv");
       ui->linePathFile->setText(path_file);
    }
}


void MainWindow::on_btn_loaddata_clicked()//слот под кнопку загрузки
{
    if ((ui->nameregion->text() == "") or (ui->linePathFile->text() == "")){
        if (ui->nameregion->text() == ""){
            QMessageBox::information(this,"окно","пустой регион");
        }
        if (ui->linePathFile->text() == ""){
            QMessageBox::information(this,"окно","пустой регион");
        }
    }else{
        if(information.size != 0)free(information.massivdata);
        information.linePathFile = ui->linePathFile->text();
        information.lineNameRegion= ui->nameregion->text();
        information.workfile = variants::readfile;
        SinglePointOfEmpty(&information);
        Work_table();
    }

}



void MainWindow::on_pushButton_calculations_clicked()
{
    if (ui->numbercolomn->text() == "" or ui->numbercolomn->text() != "3" or ui->numbercolomn->text() != "4" or ui->numbercolomn->text() == "5" or ui->numbercolomn->text() != "6" or ui->numbercolomn->text() != "7"){
        QMessageBox::information(this,"окно","пустой регион");
    }else{
        information.stolb = ui->numbercolomn->text();
        information.workfile = variants::maxandmin;
        information.maxminavg = (double*)calloc(3, sizeof(double));
        SinglePointOfEmpty(&information);
        if (information.maxminavg[0] == 0 and information.maxminavg[1] == 0 and information.maxminavg[2] == 0){
            QMessageBox::information(this,"окно","пустые значения");
        }else{
            ui->min->setText(QString::number(information.maxminavg[0]));
            ui->max->setText(QString::number(information.maxminavg[1]));
            ui->med->setText(QString::number(information.maxminavg[2]));
        }
        free(information.maxminavg);
    }
}

