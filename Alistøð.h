#pragma once
//#include "Aliring.h"
#include "Bing.h"
#include "EykaFunkti�nir.h"

#include <vector>
#include <list>
#include <ostream>
using std::vector;
using std::list;
using std::unique_ptr;

// Alist��in inni heldur f��ur mongd vi� allar typurnar
class Alist��
{
public:
	Alist��();
	~Alist��();

	double automatiskF��ring(int m�na�ur, double fiskaSt�dd, double biomassi); // Geva f��ur eftir sfr meting
	double manuelF��ring(double f��urMongd); // Br�karin hevur givi�
	void keypaSilo(fTypa typa, double maxVekt);
	double keypaF��urInn(double mongd, fTypa typa); // RETURN: hvussu n�gv f��ur leyp av, sum ikki passa�i �
	double gevaF��ur(double mongd, double fiskaVekt); // RETURN: F��ur sum aliringurin f�r
	int bingLength();
	list<Bing>& getF��urGoymsla();
	
	double getSfr(int m�r, int st�dd) { return sfr[m�r][st�dd]; }

	double** getSfr();

private:
	list<Bing> f��urGoymsla;
	double pengar;
	int maxSiloir;
	//vector<M�tstand> m�tstandir;
	double sfr[12][fiskaSt�ddir];
};