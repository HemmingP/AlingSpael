#pragma once
#include "Hóttan.h"

class HSjúka : public Hóttan
{
public:
	HSjúka(shared_ptr<HóttanDetail> hd, int pMongd = 0);
	~HSjúka();

	virtual int mongdAvHóttanSumKemur(int fiskaMongd, double fiskaVekt, int mðr);
	virtual int mongdAvHóttanSumFer(int fiskaMongd, double fiskaVekt, int mðr);
	virtual int veksurOgMinkar(int fiskaMongd, double fiskaVekt, int mðr);
	virtual int fiskurDoyr(int fiskaMongd, double fiskaVekt);
	virtual double fiskurFærStress(int fiskaMongd, double fiskaVekt);

private:
};