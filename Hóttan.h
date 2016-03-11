#pragma once
#include <memory>
#include <random>
#include "HóttanDetail.h"
#include "MótstøğaÁvirkan.h"
//#include "EykaFunktiónir.h"
using std::shared_ptr;

class Hóttan
{
public:
	Hóttan();
	Hóttan(shared_ptr<HóttanDetail>, int pMongd = 0);
	~Hóttan();

	virtual int mongdAvHóttanSumKemur(int fiskaMongd, double fiskaVekt, int mğr) = 0;
	virtual int mongdAvHóttanSumFer(int fiskaMongd, double fiskaVekt, int mğr) = 0;
	virtual int veksurOgMinkar(int fiskaMongd, double fiskaVekt, int mğr) = 0;
	virtual int fiskurDoyr(int fiskaMongd, double fiskaVekt) = 0;
	virtual double fiskurFærStress(int fiskaMongd, double fiskaVekt) = 0;

	int getMongd() { return mongd; }
	shared_ptr<HóttanDetail> getDetail() { return umHóttan; }
	virtual void addaMongd(int pMongd, int fiskaMongd, double fiskaVekt);
	
	void nullstillaÁvirkanir();

	bool ávirkaParametur(MótstøğaÁvirkan ma);

	int getÁvirkaMaxMongd() { return ávirkaMaxMongd; }
	double getÁvirkaTjansur() { return ávirkaTjansur; }
	double getÁvirkaTjansurDeviation() { return ávirkaTjansurDeviation; }
	double getÁvirkaVaksa() { return ávirkaVaksa; }
	double getÁvirkaVaksaDeviation() { return ávirkaVaksaDeviation; }

	void setÁvirkaMaxMongd(int á) { ávirkaMaxMongd = á; }
	void setÁvirkaTjansur(double á) { ávirkaTjansur = á; }
	void setÁvirkaTjansurDeviation(double á) { ávirkaTjansurDeviation = á; }
	void setÁvirkaVaksa(double á) { ávirkaVaksa = á; }
	void setÁvirkaVaksaDeviation(double á) { ávirkaVaksaDeviation = á; }

	int operator+ (const int& a);
	int operator- (const int& a);

protected:
	shared_ptr<HóttanDetail> umHóttan;
	int mongd;
	int ávirkaMaxMongd;
	double ávirkaTjansur;
	double ávirkaTjansurDeviation;
	double ávirkaVaksa;
	double ávirkaVaksaDeviation;

private:

	template<typename T>
	void ávirkaMótstøğuHátt(MótstøğaÁvirkan ma, T& parameturin)
	{
		switch (ma.getMótstøğuHáttur())
		{
		case MONGD:
			parameturin = parameturin - ma.getMongdÁvirkan();
			break;
		case PROSENT:
			parameturin = parameturin - (parameturin * ma.getMongdÁvirkan() / 100);
			break;
		default:
			break;
		}
	}

};
