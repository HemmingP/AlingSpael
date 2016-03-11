#pragma once
//#include "Hóttan.h"
#include "HDjór.h"
#include "HSníkur.h"
#include "HSjúka.h"
#include "HNáttúra.h"

#include <memory>
using std::unique_ptr;
using std::shared_ptr;

const int fiskaStøddir = 8; // Inniheldur x typir av fiski, sum er inni á talvuni á sfr

unique_ptr<Hóttan> addaHóttan(shared_ptr<HóttanDetail> hd);

//template<typename T> void ávirkaMótstøðuHátt(MótstøðaÁvirkan ma, T& parameturin);

double fiskurEtur(int mánaður, double fiskaStødd, double biomassi, double** sfr);

