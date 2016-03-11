#pragma once
#include <memory>
#include <random>
#include "H�ttanDetail.h"
#include "M�tst��a�virkan.h"
//#include "EykaFunkti�nir.h"
using std::shared_ptr;

class H�ttan
{
public:
	H�ttan();
	H�ttan(shared_ptr<H�ttanDetail>, int pMongd = 0);
	~H�ttan();

	virtual int mongdAvH�ttanSumKemur(int fiskaMongd, double fiskaVekt, int m�r) = 0;
	virtual int mongdAvH�ttanSumFer(int fiskaMongd, double fiskaVekt, int m�r) = 0;
	virtual int veksurOgMinkar(int fiskaMongd, double fiskaVekt, int m�r) = 0;
	virtual int fiskurDoyr(int fiskaMongd, double fiskaVekt) = 0;
	virtual double fiskurF�rStress(int fiskaMongd, double fiskaVekt) = 0;

	int getMongd() { return mongd; }
	shared_ptr<H�ttanDetail> getDetail() { return umH�ttan; }
	virtual void addaMongd(int pMongd, int fiskaMongd, double fiskaVekt);
	
	void nullstilla�virkanir();

	bool �virkaParametur(M�tst��a�virkan ma);

	int get�virkaMaxMongd() { return �virkaMaxMongd; }
	double get�virkaTjansur() { return �virkaTjansur; }
	double get�virkaTjansurDeviation() { return �virkaTjansurDeviation; }
	double get�virkaVaksa() { return �virkaVaksa; }
	double get�virkaVaksaDeviation() { return �virkaVaksaDeviation; }

	void set�virkaMaxMongd(int �) { �virkaMaxMongd = �; }
	void set�virkaTjansur(double �) { �virkaTjansur = �; }
	void set�virkaTjansurDeviation(double �) { �virkaTjansurDeviation = �; }
	void set�virkaVaksa(double �) { �virkaVaksa = �; }
	void set�virkaVaksaDeviation(double �) { �virkaVaksaDeviation = �; }

	int operator+ (const int& a);
	int operator- (const int& a);

protected:
	shared_ptr<H�ttanDetail> umH�ttan;
	int mongd;
	int �virkaMaxMongd;
	double �virkaTjansur;
	double �virkaTjansurDeviation;
	double �virkaVaksa;
	double �virkaVaksaDeviation;

private:

	template<typename T>
	void �virkaM�tst��uH�tt(M�tst��a�virkan ma, T& parameturin)
	{
		switch (ma.getM�tst��uH�ttur())
		{
		case MONGD:
			parameturin = parameturin - ma.getMongd�virkan();
			break;
		case PROSENT:
			parameturin = parameturin - (parameturin * ma.getMongd�virkan() / 100);
			break;
		default:
			break;
		}
	}

};
