#pragma once

#include "EykaH�ttan.h"
//#include "M�tst��a�virkan.h"
//#include "H�ttan.h"
#include <string>
#include <list>
#include <vector>
#include <random>
#include <cmath>
#include <string>
#include <sstream>
#include <exception>
#include <iostream>

using std::string;
using std::list;
using std::stringstream;
using std::getline;

//template<class T>
class H�ttanDetail
{
public:
	H�ttanDetail();
	H�ttanDetail(string pNavn, string pTypaAvH�ttan, double pTjansur, double pTjansurDeviation, double pMaxMongd, double pVaksa, double pVaksaDeviation, double pStressK, double pStressKDeviation, double pDrepur, double pDrepurDeviation, list<EykaH�ttan> pH�ttanAfturat);
	~H�ttanDetail();

	string getNavn() { return navn; }
	string getTypaAvH�ttan() { return typaAvH�ttan; }
	double getTjansur() { return tjansur; }
	double getTjansurDeviation() { return tjansurDeviation; }

	int getMaxMongd() { return maxMongd; }

	double getVaksa() { return vaksa; }
	double getVaksaDeviation() { return vaksaDeviation; }

	double getStressK() { return strongdK; }
	double getStressDeviation() { return strongdKDeviation; }
	
	double getDrepur() { return drepur; }
	double getDrepurDeviation() { return drepurDeviation; }

	bool operator== (H�ttanDetail h);
	H�ttanDetail& operator=(string s);

private:
	string navn;
	string typaAvH�ttan;
	double tjansur;
	double tjansurDeviation;
	double maxMongd;
	double vaksa; // T.D L�sin veksur so sum t��in gongur...
	double vaksaDeviation;
	double strongdK; // Hetta er hall tali� � formulinum y=1-(e^-k*x)
	double strongdKDeviation;
	double drepur;
	double drepurDeviation;
	list<EykaH�ttan> eykaH�ttan; // Hetta hevur h�ttanir, sum kunnu koma afturat, t� i� hendan h�ttanin er virkin.
};

std::ostream& operator<<(std::ostream& os, H�ttanDetail& obj);