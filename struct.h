#ifndef STRUCT_H
#define STRUCT_H
#pragma once
#include <QString>
#include <vector>
using namespace std;

enum variants{
 maxandmin, readfile
};


 struct alldata{
      int _year;
      QString _region;
      double _npg;
      double _birth_rate;
      double _death_rate;
      double _gdw;
      double _urbanization;
      //alldata(int year, QString region,double npg,double birth_rate,double death_rate,double gdw, double urbanization);
  };
  struct dat{
      QString stolb;
      QString linePathFile, lineNameRegion, Column;
      variants workfile;
      alldata* massivdata;
      size_t size = 0;
      double* maxminavg;
      };
#endif // STRUCT_H
