#include "Fiskur.h"

Fiskur::Fiskur(string pFiskaSlag, double pBiomassi, int pFiskaMongd, double pSt�ddCm, double pStress, shared_ptr<FiskaL�vfr��i> pFiskaL�vfr��i, double pMaxStress)
{
	fiskaSlag = pFiskaSlag;
	biomassi = pBiomassi;
	maxFiskaVekt = -1;
	fiskaMongd = pFiskaMongd;
	st�ddCm = pSt�ddCm;
	strongd = pStress;
	maxStrongd = pMaxStress;

	fiskaL�vfr��i = pFiskaL�vfr��i;
}

Fiskur::~Fiskur()
{
}

string Fiskur::getFiskaSlag()
{
	return fiskaSlag;
}

double Fiskur::getBiomassi()
{
	return biomassi;
}

double Fiskur::getMaxFiskaVekt()
{
	return maxFiskaVekt;
}

int Fiskur::getFiskaMongd()
{
	return fiskaMongd;
}

double Fiskur::getSt�ddCm()
{
	return st�ddCm;
}

double Fiskur::getStrongd()
{
	return strongd;
}

double Fiskur::getMaxStrongd()
{
	return maxStrongd;
}

double Fiskur::getMi�alVekt()
{
	return biomassi / fiskaMongd;
}

shared_ptr<FiskaL�vfr��i> Fiskur::getFiskaL�vfr��i()
{
	return fiskaL�vfr��i;
}

void Fiskur::setMaxFiskaVekt(double pMax)
{
	maxFiskaVekt = pMax;
}

void Fiskur::minkaUmMongd(int mongd)
{
	biomassi = biomassi - (mongd*getMi�alVekt());
	fiskaMongd = fiskaMongd - mongd;

	if (fiskaMongd <= 0)
	{
		fiskaMongd = 0;
		biomassi = 0;
	}
}

void Fiskur::addaUmBiomassan(double addaVekt)
{
	biomassi = biomassi + addaVekt;
}

void Fiskur::addaStrongd(double pStress)
{
	if (strongd + pStress < 0)
		strongd = 0;
	else
		if (strongd + pStress > maxStrongd)
			strongd = maxStrongd;
		else
			strongd = strongd + pStress;
}