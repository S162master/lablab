#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "struct.h"

void MainWindow::Work_table(){
    ui->TableWidget->setRowCount(information.size);
    ui->TableWidget->setColumnCount(7);//делаем таблицу
    ui->TableWidget->setHorizontalHeaderLabels(QStringList()<<"Year"<<"Region"<<"Npg"<<"Birth_rate"<<"Death_rate"<<"Gdw"<<"Urbanization");
    if (information.size == 0)
        return;
    for (int i = 0; i < information.size; i++){//заносим данные
        for(int j = 0; j < 7; j++){
            switch (j) {
            case 0:
                ui->TableWidget->setItem(i, j, new QTableWidgetItem(QString::number(information.massivdata[i]._year)));
                break;
            case 1:
                ui->TableWidget->setItem(i, j, new QTableWidgetItem(information.massivdata[i]._region));
                break;
            case 2:
                ui->TableWidget->setItem(i, j, new QTableWidgetItem(QString::number(information.massivdata[i]._npg)));
               break;
            case 3:
                ui->TableWidget->setItem(i, j, new QTableWidgetItem(QString::number(information.massivdata[i]._birth_rate)));
               break;
            case 4:
                ui->TableWidget->setItem(i, j, new QTableWidgetItem(QString::number(information.massivdata[i]._death_rate)));
               break;
            case 5:
                ui->TableWidget->setItem(i, j, new QTableWidgetItem(QString::number(information.massivdata[i]._gdw)));
               break;
            case 6:
                ui->TableWidget->setItem(i, j, new QTableWidgetItem(QString::number(information.massivdata[i]._urbanization)));
               break;
            default:
                break;
            }
        }
    }
    return;
}
