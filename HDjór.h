#pragma once
#include "Hóttan.h"

class HDjór : public Hóttan
{
public:
	HDjór(shared_ptr<HóttanDetail> hd, int pMongd = 0);
	~HDjór();

	virtual int mongdAvHóttanSumKemur(int fiskaMongd, double fiskaVekt, int mðr);
	virtual int mongdAvHóttanSumFer(int fiskaMongd, double fiskaVekt, int mðr);
	virtual int veksurOgMinkar(int fiskaMongd, double fiskaVekt, int mðr);
	virtual int fiskurDoyr(int fiskaMongd, double fiskaVekt);
	virtual double fiskurFærStress(int fiskaMongd, double fiskaVekt);

private:
};