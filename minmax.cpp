#include "minmax.h"


void minmaxavg(dat* information){
    vector<double> sort_list;
    for(int i=0;i < information->size;i++){//все элементы
        if (information->stolb.toStdString()=="3")//когда 3 берет значение
            sort_list.push_back(information->massivdata[i]._npg);
        else if (information->stolb.toStdString()=="4")
            sort_list.push_back(information->massivdata[i]._birth_rate);
        else if (information->stolb.toStdString()=="5")
            sort_list.push_back(information->massivdata[i]._death_rate);
        else if (information->stolb.toStdString()=="6")
            sort_list.push_back(information->massivdata[i]._gdw);
        else if (information->stolb.toStdString()=="7")
            sort_list.push_back(information->massivdata[i]._urbanization);
        else
            qDebug("введён не правильный столбец");
    }
    double median;
    sort(sort_list.begin(),sort_list.end());
    double min = sort_list.at(0);
    double max = sort_list.at(sort_list.size()-1);
    if (sort_list.size()%2 == 1)
        median = sort_list.at(sort_list.size()/2);
    else
        median = (sort_list.at(sort_list.size() / 2)+ sort_list.at((sort_list.size() / 2)-1))/2;
    information->maxminavg[0]=min;
    information->maxminavg[1]=max;
    information->maxminavg[2]=median;
}
