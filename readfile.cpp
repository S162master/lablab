#include "readfile.h"

void copyfromvectortoarray(vector<alldata> vibor, dat* variants){
    variants->size = vibor.size();
    variants->massivdata = (alldata*)calloc(variants->size, sizeof(alldata));
    for(int i = 0; i < variants->size; i++){
        variants->massivdata[i] =  vibor[i];
    }
}

int read_file(dat* variants){
    fstream file;
    file.open(variants->linePathFile.toStdString());
    vector <alldata> vibor;


    if (file.is_open()){
            string str, str_shapka;
            getline(file, str_shapka, '\n');//считываем шапку
            string inregion;
            while (getline(file, str, '\n')) {//последовательно берем по одной строке
                stringstream inputt(str);
                string mas[7];
                int i = 0, j=0;
                while (getline(inputt, mas[i], ','))//работа со строкой
                    i++;
                if (mas[0] != "" && mas[2] != "" && mas[3] != "" && mas[4] != "" && mas[5] != "" && mas[6] != "" && mas[1] == variants->lineNameRegion.toStdString()){
                    vibor.push_back({stoi(mas[0]),QString::fromStdString(mas[1]),stod(mas[2]),stod(mas[3]),stod(mas[4]),stod(mas[5]),stod(mas[6])});
                    j++;
                }else
                    qDebug("обнаружено неверное значение");
            }
        }else
          return -1;
    file.close();
    copyfromvectortoarray(vibor,variants);
    return 0;
}

