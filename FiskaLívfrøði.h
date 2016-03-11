#pragma once
#include "EykaFunktiónir.h"
#include <random>
//#include <math.h>
#include <cmath>

class FiskaLívfrøði
{
public:
	FiskaLívfrøði();
	~FiskaLívfrøði();

	string getFiskaSlag() { return fiskaSlag; }
	double vøksturinPrDag(double fóðurGivið, double fóðurVilHava, double biomassi, double &maxKilo, int dagur, double stress, double maxStress = 200); // Gevur eina mongd, hvussu nógv fiskurin veksur
	double fiskafóðurVilHavaPrDag(int mðr, double stødd, double vekt, double** sfr); // Gevur eina mongd, hvat fiskur vil hava, stress faktorurin ávrikar toppunktið.
	double stressProsent(double stress, double maxStress = 200);
	double stressFóðurÁvirkan(double stress, double maxStress = 200);

private:
	string fiskaSlag;
	double exponentiellurVøksturin;
	double logistiskiVøksturin;
	int logisticSlærInn;
	double logisticMiðpunkt;
	double prosentAvFiskastøddTáIðLogisticSlærInn;
};