#pragma once
#include "H�ttan.h"

class HN�tt�ra : public H�ttan
{
public:
	HN�tt�ra(shared_ptr<H�ttanDetail> hd, int pMongd = 0);
	~HN�tt�ra();

	virtual int mongdAvH�ttanSumKemur(int fiskaMongd, double fiskaVekt, int m�r);
	virtual int mongdAvH�ttanSumFer(int fiskaMongd, double fiskaVekt, int m�r);
	virtual int veksurOgMinkar(int fiskaMongd, double fiskaVekt, int m�r);
	virtual int fiskurDoyr(int fiskaMongd, double fiskaVekt);
	virtual double fiskurF�rStress(int fiskaMongd, double fiskaVekt);

private:
};