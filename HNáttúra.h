#pragma once
#include "Hóttan.h"

class HNáttúra : public Hóttan
{
public:
	HNáttúra(shared_ptr<HóttanDetail> hd, int pMongd = 0);
	~HNáttúra();

	virtual int mongdAvHóttanSumKemur(int fiskaMongd, double fiskaVekt, int mðr);
	virtual int mongdAvHóttanSumFer(int fiskaMongd, double fiskaVekt, int mðr);
	virtual int veksurOgMinkar(int fiskaMongd, double fiskaVekt, int mðr);
	virtual int fiskurDoyr(int fiskaMongd, double fiskaVekt);
	virtual double fiskurFærStress(int fiskaMongd, double fiskaVekt);

private:
};