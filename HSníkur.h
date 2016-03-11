#pragma once
#include "H�ttan.h"

class HSn�kur : public H�ttan
{
public:
	HSn�kur(shared_ptr<H�ttanDetail> hd, int pMongd = 0);
	~HSn�kur();

	virtual int mongdAvH�ttanSumKemur(int fiskaMongd, double fiskaVekt, int m�r);
	virtual int mongdAvH�ttanSumFer(int fiskaMongd, double fiskaVekt, int m�r);
	virtual int veksurOgMinkar(int fiskaMongd, double fiskaVekt, int m�r);
	virtual int fiskurDoyr(int fiskaMongd, double fiskaVekt);
	virtual double fiskurF�rStress(int fiskaMongd, double fiskaVekt);

	virtual void addaMongd(int pMongd, int fiskaMongd, double fiskaVekt);

private:
};