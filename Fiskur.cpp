#include "Fiskur.h"

Fiskur::Fiskur(string pFiskaSlag, double pBiomassi, int pFiskaMongd, double pStøddCm, double pStress, shared_ptr<FiskaLívfrøði> pFiskaLívfrøði, double pMaxStress)
{
	fiskaSlag = pFiskaSlag;
	biomassi = pBiomassi;
	maxFiskaVekt = -1;
	fiskaMongd = pFiskaMongd;
	støddCm = pStøddCm;
	strongd = pStress;
	maxStrongd = pMaxStress;

	fiskaLívfrøði = pFiskaLívfrøði;
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

double Fiskur::getStøddCm()
{
	return støddCm;
}

double Fiskur::getStrongd()
{
	return strongd;
}

double Fiskur::getMaxStrongd()
{
	return maxStrongd;
}

double Fiskur::getMiðalVekt()
{
	return biomassi / fiskaMongd;
}

shared_ptr<FiskaLívfrøði> Fiskur::getFiskaLívfrøði()
{
	return fiskaLívfrøði;
}

void Fiskur::setMaxFiskaVekt(double pMax)
{
	maxFiskaVekt = pMax;
}

void Fiskur::minkaUmMongd(int mongd)
{
	biomassi = biomassi - (mongd*getMiðalVekt());
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