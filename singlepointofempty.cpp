#include "singlepointofempty.h"

void SinglePointOfEmpty(dat* information){
  switch(information->workfile){
      case(0):{
      minmaxavg(information);
      break;
      }
      case(1):{
      int kolvo = read_file(information);
      break;
      }
  }
};
