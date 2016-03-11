#include "HSníkur.h"

HSníkur::HSníkur(shared_ptr<HóttanDetail> hd, int pMongd) : Hóttan(hd,pMongd)
{
}

HSníkur::~HSníkur()
{
}

int HSníkur::mongdAvHóttanSumKemur(int fiskaMongd, double fiskaVekt, int mðr)
{
	// normal distribution
	if (ávirkaTjansurDeviation != 0)
	{
		std::random_device rd;
		std::mt19937 gen(rd());

		std::normal_distribution<> d(ávirkaTjansur, ávirkaTjansurDeviation);
		double úrslit = d(gen);
		return úrslit; // ERROR check
	}
	else
		return ávirkaTjansur;
}

int HSníkur::mongdAvHóttanSumFer(int fiskaMongd, double fiskaVekt, int mðr)
{
	return 0;
}

int HSníkur::veksurOgMinkar(int fiskaMongd, double fiskaVekt, int mðr)
{
	double vøkstur = 0;
	if(ávirkaVaksaDeviation != 0)
	{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<> d(ávirkaVaksa, ávirkaVaksaDeviation);
	vøkstur = d(gen);
	}
	else
		vøkstur = ávirkaVaksa;
	// y = L / (1+e^(-k*x)); L: toppunkt; k: boyggilsi; u: tíðin; u0: midpunkt
	// Finna x0...
	// Hvar eru vit á x? x = ln(1/((L/y)-1))/k
	double mestalagið = ávirkaMaxMongd * fiskaMongd;

	if(mongd < mestalagið){
	double x = log(1 / ((mestalagið / (double)mongd) - 1.0)) / vøkstur;
	double vøksturinDaginEftir = mestalagið / (1.0 + exp(-vøkstur*(x + 1.0)));
	return vøksturinDaginEftir - mongd;
	}
	else
	{
		return mestalagið;
	}
}

int HSníkur::fiskurDoyr(int fiskaMongd, double fiskaVekt)
{
	// Parametrar sum vit hava brúk fyri...
	std::random_device rd;
	std::mt19937 gen(rd());

	std::normal_distribution<> d(umHóttan->getDrepur()*mongd, umHóttan->getDrepurDeviation()*mongd); /// Sett tað fyribils á eitt deviation uppá 20%
	int úrslit = d(gen);

	if (úrslit < 0)
		úrslit = 0;

	return úrslit;
}

double HSníkur::fiskurFærStress(int fiskaMongd, double fiskaVekt)
{
	//y = 1-(e^(-k*x))
	//k = ln(-1/(y-1))/x
	//double k = log(1 / (0.8 - 1)) / fiskaMongd;

	double lúsamongdPrFisk = (double)mongd / fiskaMongd;
	// k=log(-1/(y-1))/x  // 4 lús pr fisk gevur 80% stress.

	double k = umHóttan->getStressK();
	double y = 1-(exp(-k*lúsamongdPrFisk));

	// SO KANN MAN EISINI PROGRAMERA UPPÍ, AT FISKAMONGDIN SKAL EISINI VERA EIN PARAMETUR AT TAKA HÆDD UPPÁ..
	// Hetta er við lús. Kópurin í øðrum hondum.. skal stressa fiskin minni, um fiskavekin ikki er so stór.

	return y*100;
}

void HSníkur::addaMongd(int pMongd, int fiskaMongd, double fiskaVekt)
{
	if (mongd + pMongd <= ávirkaMaxMongd*fiskaMongd)
		mongd = mongd + pMongd;
	else
		mongd = ávirkaMaxMongd*fiskaMongd;
}