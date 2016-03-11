#pragma once
//#include "H�ttan.h"
#include "HDj�r.h"
#include "HSn�kur.h"
#include "HSj�ka.h"
#include "HN�tt�ra.h"

#include <memory>
using std::unique_ptr;
using std::shared_ptr;

const int fiskaSt�ddir = 8; // Inniheldur x typir av fiski, sum er inni � talvuni � sfr

unique_ptr<H�ttan> addaH�ttan(shared_ptr<H�ttanDetail> hd);

//template<typename T> void �virkaM�tst��uH�tt(M�tst��a�virkan ma, T& parameturin);

double fiskurEtur(int m�na�ur, double fiskaSt�dd, double biomassi, double** sfr);

