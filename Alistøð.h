#pragma once
//#include "Aliring.h"
#include "Bing.h"
#include "EykaFunktiónir.h"

#include <vector>
#include <list>
#include <ostream>
using std::vector;
using std::list;
using std::unique_ptr;

// Alistøðin inni heldur fóður mongd við allar typurnar
class Alistøð
{
public:
	Alistøð();
	~Alistøð();

	double automatiskFóðring(int mánaður, double fiskaStødd, double biomassi); // Geva fóður eftir sfr meting
	double manuelFóðring(double fóðurMongd); // Brúkarin hevur givið
	void keypaSilo(fTypa typa, double maxVekt);
	double keypaFóðurInn(double mongd, fTypa typa); // RETURN: hvussu nógv fóður leyp av, sum ikki passaði í
	double gevaFóður(double mongd, double fiskaVekt); // RETURN: Fóður sum aliringurin fær
	int bingLength();
	list<Bing>& getFóðurGoymsla();
	
	double getSfr(int mðr, int stødd) { return sfr[mðr][stødd]; }

	double** getSfr();

private:
	list<Bing> fóðurGoymsla;
	double pengar;
	int maxSiloir;
	//vector<Mótstand> mótstandir;
	double sfr[12][fiskaStøddir];
};