#pragma once
#include "EykaFunkti�nir.h"
#include <random>
//#include <math.h>
#include <cmath>

class FiskaL�vfr��i
{
public:
	FiskaL�vfr��i();
	~FiskaL�vfr��i();

	string getFiskaSlag() { return fiskaSlag; }
	double v�ksturinPrDag(double f��urGivi�, double f��urVilHava, double biomassi, double &maxKilo, int dagur, double stress, double maxStress = 200); // Gevur eina mongd, hvussu n�gv fiskurin veksur
	double fiskaf��urVilHavaPrDag(int m�r, double st�dd, double vekt, double** sfr); // Gevur eina mongd, hvat fiskur vil hava, stress faktorurin �vrikar toppunkti�.
	double stressProsent(double stress, double maxStress = 200);
	double stressF��ur�virkan(double stress, double maxStress = 200);

private:
	string fiskaSlag;
	double exponentiellurV�ksturin;
	double logistiskiV�ksturin;
	int logisticSl�rInn;
	double logisticMi�punkt;
	double prosentAvFiskast�ddT�I�LogisticSl�rInn;
};