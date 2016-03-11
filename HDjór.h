#pragma once
#include "H�ttan.h"

class HDj�r : public H�ttan
{
public:
	HDj�r(shared_ptr<H�ttanDetail> hd, int pMongd = 0);
	~HDj�r();

	virtual int mongdAvH�ttanSumKemur(int fiskaMongd, double fiskaVekt, int m�r);
	virtual int mongdAvH�ttanSumFer(int fiskaMongd, double fiskaVekt, int m�r);
	virtual int veksurOgMinkar(int fiskaMongd, double fiskaVekt, int m�r);
	virtual int fiskurDoyr(int fiskaMongd, double fiskaVekt);
	virtual double fiskurF�rStress(int fiskaMongd, double fiskaVekt);

private:
};