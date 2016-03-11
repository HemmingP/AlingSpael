#pragma once

#include "EykaHóttan.h"
//#include "MótstøðaÁvirkan.h"
//#include "Hóttan.h"
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
class HóttanDetail
{
public:
	HóttanDetail();
	HóttanDetail(string pNavn, string pTypaAvHóttan, double pTjansur, double pTjansurDeviation, double pMaxMongd, double pVaksa, double pVaksaDeviation, double pStressK, double pStressKDeviation, double pDrepur, double pDrepurDeviation, list<EykaHóttan> pHóttanAfturat);
	~HóttanDetail();

	string getNavn() { return navn; }
	string getTypaAvHóttan() { return typaAvHóttan; }
	double getTjansur() { return tjansur; }
	double getTjansurDeviation() { return tjansurDeviation; }

	int getMaxMongd() { return maxMongd; }

	double getVaksa() { return vaksa; }
	double getVaksaDeviation() { return vaksaDeviation; }

	double getStressK() { return strongdK; }
	double getStressDeviation() { return strongdKDeviation; }
	
	double getDrepur() { return drepur; }
	double getDrepurDeviation() { return drepurDeviation; }

	bool operator== (HóttanDetail h);
	HóttanDetail& operator=(string s);

private:
	string navn;
	string typaAvHóttan;
	double tjansur;
	double tjansurDeviation;
	double maxMongd;
	double vaksa; // T.D Lúsin veksur so sum tíðin gongur...
	double vaksaDeviation;
	double strongdK; // Hetta er hall talið á formulinum y=1-(e^-k*x)
	double strongdKDeviation;
	double drepur;
	double drepurDeviation;
	list<EykaHóttan> eykaHóttan; // Hetta hevur hóttanir, sum kunnu koma afturat, tá ið hendan hóttanin er virkin.
};

std::ostream& operator<<(std::ostream& os, HóttanDetail& obj);