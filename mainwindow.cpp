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
    if (ui->LinePathFile->text() == ""){
       path_file = QFileDialog::getOpenFileName(this, tr("Open File"), "C://", "All files(*.*);;Table File(*.csv");
       ui->LinePathFile->setText(path_file);
    }
}


void MainWindow::on_btn_loaddata_clicked()//слот под кнопку загрузки
{
    if ((ui->NameRegion->text() == "") or (ui->LinePathFile->text() == "")){
        if (ui->NameRegion->text() == ""){
            QMessageBox::information(this,"окно","пустой регион");
        }
        if (ui->LinePathFile->text() == ""){
            QMessageBox::information(this,"окно","пустой регион");
        }
    }else{
        if(information.size != 0)free(information.massivdata);
        information.linePathFile = ui->LinePathFile->text();
        information.lineNameRegion= ui->NameRegion->text();
        information.workfile = variants::readfile;
        SinglePointOfEmpty(&information);
        Work_table();
    }

}



void MainWindow::on_pushButton_calculations_clicked()
{
    if (ui->NameRegion->text() == "" or ui->NameRegion->text() != "3" or ui->NameRegion->text() != "4" or ui->NameRegion->text() == "5" or ui->NameRegion->text() != "6" or ui->NameRegion->text() != "7"){
        QMessageBox::information(this,"окно","пустой регион");
    }else{
        information.stolb = ui->NameRegion->text();
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

