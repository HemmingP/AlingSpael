#pragma once
#include "FiskaLívfrøði.h"

#include <string>
#include <memory>

using std::shared_ptr;
using std::string;

class Fiskur
{
public:
	Fiskur(string pFiskaSlag, double pBiomassi, int pFiskaMongd, double pStøddCm, double pStress, shared_ptr<FiskaLívfrøði> pFiskaLívfrøði, double pMaxStress = 200);
	~Fiskur();

	string getFiskaSlag();
	double getBiomassi();
	double getMaxFiskaVekt();
	int getFiskaMongd();
	double getStøddCm();
	double getStrongd();
	double getMaxStrongd();
	shared_ptr<FiskaLívfrøði> getFiskaLívfrøði();

	double getMiðalVekt();

	void setMaxFiskaVekt(double pMax);

	void minkaUmMongd(int mongd);
	void addaUmBiomassan(double addaVekt);
	void addaStrongd(double pStress);

private:
	string fiskaSlag;
	double biomassi;
	double maxFiskaVekt;
	int fiskaMongd;
	double støddCm;
	double strongd;
	double maxStrongd;

	shared_ptr<FiskaLívfrøði> fiskaLívfrøði;
};