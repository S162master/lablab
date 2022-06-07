#ifndef READFILE_H
#define READFILE_H
#pragma once
#include <sstream>
#include <string>
#include <fstream>
#include <string>
#include "struct.h"
using namespace std;

int read_file(dat* variants);

void copyfromvectortoarray(vector<alldata> vibor, dat* variants);

#endif // READFILE_H
