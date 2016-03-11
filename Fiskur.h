#pragma once
#include "FiskaL�vfr��i.h"

#include <string>
#include <memory>

using std::shared_ptr;
using std::string;

class Fiskur
{
public:
	Fiskur(string pFiskaSlag, double pBiomassi, int pFiskaMongd, double pSt�ddCm, double pStress, shared_ptr<FiskaL�vfr��i> pFiskaL�vfr��i, double pMaxStress = 200);
	~Fiskur();

	string getFiskaSlag();
	double getBiomassi();
	double getMaxFiskaVekt();
	int getFiskaMongd();
	double getSt�ddCm();
	double getStrongd();
	double getMaxStrongd();
	shared_ptr<FiskaL�vfr��i> getFiskaL�vfr��i();

	double getMi�alVekt();

	void setMaxFiskaVekt(double pMax);

	void minkaUmMongd(int mongd);
	void addaUmBiomassan(double addaVekt);
	void addaStrongd(double pStress);

private:
	string fiskaSlag;
	double biomassi;
	double maxFiskaVekt;
	int fiskaMongd;
	double st�ddCm;
	double strongd;
	double maxStrongd;

	shared_ptr<FiskaL�vfr��i> fiskaL�vfr��i;
};