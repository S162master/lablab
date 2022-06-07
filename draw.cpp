#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

void MainWindow::DrawRez(){
    double shag=360/information.drawList.size();
    QPixmap *pix = new QPixmap(400,500);
    QPainter paint(pix);
    paint.fillRect(0, 0, 500, 550, QBrush(QColor(Qt::GlobalColor::white)));
    DrawGrid(&paint,shag);
    drawValue(&paint,shag);
    DrawGraf(&paint,shag);
    DrawInscription(&paint,shag);
    ui->label->setPixmap(*pix);
}

void MainWindow::DrawGrid(QPainter *paint,double shag){
    paint->setPen(*(new QColor(0, 0, 0, 255)));
    for (int i=-1; i<=12;i++){
        paint->drawText(0,360-34*i,QString::number(10*i));
        paint->setPen(*(new QColor(61, 141, 233, 255)));
        paint->drawLine(20,360-34*i,380,360-34*i);
        paint->setPen(*(new QColor(1, 1, 1, 255)));
    }
    paint->setPen(*(new QColor(61, 141, 233, 255)));
    for(int i = 1;i<=information.drawList.size();i++){
        paint->drawLine(20+i*shag,410,20+i*shag,20);
    }
    paint->setPen(*(new QColor(0, 0, 0, 255)));
    paint->drawLine(20, 360, 380, 360);
    paint->drawLine(20, 20, 20, 410);
    paint->drawText(370,380,"X");
    paint->drawText(10,30,"Y");
}
void MainWindow::DrawGraf(QPainter *paint,double shag){
    for(int i = 1;i<=information.drawList.size();i++){
        paint->drawPoint(20+i*shag,360-3.4*information.drawList[i-1]);
        if (i<information.drawList.size())
            paint->drawLine(20+i*shag,360-3.4*information.drawList[i-1],20+(i+1)*shag,360-3.4*information.drawList[i]);
    }
}
void MainWindow::DrawInscription(QPainter *paint, double shag){
    for (int i = 1;i<=information.drawList.size();i++){
            int yearDraw=(information.massivdata[i-1]._year);
            paint->drawText(20+i*shag,450,QString::number(yearDraw%10));
            for (int j=1;j<=3;j++){
                yearDraw/=10;
                paint->drawText(20+i*shag,450-j*10,QString::number(yearDraw%10));
            }
    }
    for (int i=-1; i<=12;i++){
        paint->drawText(0,360-34*i,QString::number(10*i));
    }
}
void MainWindow::drawValue(QPainter *paint,double shag){
    paint->setPen(*(new QColor(255, 0, 0, 255)));
    paint->drawLine(20,360-(information.maxminavg[2])*3.4,380,360-information.maxminavg[2]*3.4);
    paint->drawText(150,380-(information.maxminavg[2])*3.4,"Mediana");
    for(int i = 1;i<=information.drawList.size();i++){
        if (information.maxminavg[0]==information.drawList[i-1]){
            paint->setPen(*(new QColor(255, 0, 0, 255)));
            paint->drawEllipse(19+i*shag,357-3.4*information.drawList[i-1],3,3);
            paint->drawText(30+i*shag,370-3.4*information.drawList[i-1],"Min");
        }
        if (information.maxminavg[1]==information.drawList[i-1]){
            paint->drawEllipse(19+i*shag,357-3.4*information.drawList[i-1],3,3);
            paint->drawText(30+i*shag,370-3.4*information.drawList[i-1],"Max");
        }
    }
    paint->setPen(*(new QColor(0, 0, 0, 255)));
}
