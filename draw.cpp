#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

void MainWindow::DrawRez(){//создание окна отрисовки
    double shag=360/information.size;//смещения
    QPixmap *pix = new QPixmap(400,500);//холст
    QPainter paint(pix);//ручка
    paint.fillRect(0, 0, 500, 550, QBrush(QColor(Qt::GlobalColor::white)));//белое основание холста
    DrawGrid(&paint,shag);
    drawValue(&paint,shag);
    DrawGraf(&paint,shag);
    DrawInscription(&paint,shag);
    ui->label->setPixmap(*pix); // в примере к лабораторной приведён проект, из которого нужно посмотреть принцип рисования. Происходит всё через label
}

void MainWindow::DrawGrid(QPainter *paint,double shag){//вертикальные и горизонтальные линии(сетка)
    paint->setPen(*(new QColor(0, 0, 0, 255)));
    for (int i=-1; i<=12;i++){
        paint->drawText(0,360-34*i,QString::number(10*i));
        paint->setPen(*(new QColor(61, 141, 233, 255)));
        paint->drawLine(20,360-34*i,380,360-34*i);//отрисовка линии
        paint->setPen(*(new QColor(1, 1, 1, 255)));//изменение цвета ручки
    }
    paint->setPen(*(new QColor(61, 141, 233, 255)));
    for(int i = 1;i<=information.size;i++){
        paint->drawLine(20+i*shag,410,20+i*shag,20);
    }
    paint->setPen(*(new QColor(0, 0, 0, 255)));
    paint->drawLine(20, 360, 380, 360);
    paint->drawLine(20, 20, 20, 410);
    paint->drawText(370,380,"X");
    paint->drawText(10,30,"Y");
}
void MainWindow::DrawGraf(QPainter *paint,double shag){//постройка графа
    for(int i = 1;i<=information.size;i++){
        paint->drawPoint(20+i*shag,360-3.4*information.drawList[i-1]);//точки // здесь нужно передать массив, в котором будут записаны все данные от 1 столбца
        if (i<information.size)
            paint->drawLine(20+i*shag,360-3.4*information.drawList[i-1],20+(i+1)*shag,360-3.4*information.drawList[i]); // как вариант, просто продублировать вектор и записать в массив построчно, но не обрабатывать, как это происходит в minmax
    }                                                                                                                      // и заменить все drawList на этот массив
}
void MainWindow::DrawInscription(QPainter *paint, double shag){//наводим красоту
    for (int i = 1;i<=information.size;i++){//по кол-ву элементов
            int yearDraw=(information.massivdata[i-1]._year);
            paint->drawText(20+i*shag,450,QString::number(yearDraw%10));//циферки снизу
            for (int j=1;j<=3;j++){//циферки снизу
                yearDraw/=10;
                paint->drawText(20+i*shag,450-j*10,QString::number(yearDraw%10));
            }
    }
    for (int i=-1; i<=12;i++){//циферки слева
        paint->drawText(0,360-34*i,QString::number(10*i));
    }
}
void MainWindow::drawValue(QPainter *paint,double shag){
    paint->setPen(*(new QColor(255, 0, 0, 255)));
    paint->drawLine(20,360-(information.maxminavg[2])*3.4,380,360-information.maxminavg[2]*3.4);
    paint->drawText(150,380-(information.maxminavg[2])*3.4,"Mediana");//медиана
    for(int i = 1;i<=information.size;i++){//подпись
        if (information.maxminavg[0]==information.drawList[i-1]){
            paint->setPen(*(new QColor(255, 0, 0, 255)));
            paint->drawEllipse(19+i*shag,357-3.4*information.drawList[i-1],3,3);//маленькая точка, поэтому отрисовываем круг 3 на 3 пикселя
            paint->drawText(30+i*shag,370-3.4*information.drawList[i-1],"Min");//подпись
        }
        if (information.maxminavg[1]==information.drawList[i-1]){
            paint->drawEllipse(19+i*shag,357-3.4*information.drawList[i-1],3,3);//маленькая точка, поэтому отрисовываем круг 3 на 3 пикселя
            paint->drawText(30+i*shag,370-3.4*information.drawList[i-1],"Max");//подпись
        }
    }
    paint->setPen(*(new QColor(0, 0, 0, 255)));
}
