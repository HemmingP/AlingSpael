#include "HSn�kur.h"

HSn�kur::HSn�kur(shared_ptr<H�ttanDetail> hd, int pMongd) : H�ttan(hd,pMongd)
{
}

HSn�kur::~HSn�kur()
{
}

int HSn�kur::mongdAvH�ttanSumKemur(int fiskaMongd, double fiskaVekt, int m�r)
{
	// normal distribution
	if (�virkaTjansurDeviation != 0)
	{
		std::random_device rd;
		std::mt19937 gen(rd());

		std::normal_distribution<> d(�virkaTjansur, �virkaTjansurDeviation);
		double �rslit = d(gen);
		return �rslit; // ERROR check
	}
	else
		return �virkaTjansur;
}

int HSn�kur::mongdAvH�ttanSumFer(int fiskaMongd, double fiskaVekt, int m�r)
{
	return 0;
}

int HSn�kur::veksurOgMinkar(int fiskaMongd, double fiskaVekt, int m�r)
{
	double v�kstur = 0;
	if(�virkaVaksaDeviation != 0)
	{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<> d(�virkaVaksa, �virkaVaksaDeviation);
	v�kstur = d(gen);
	}
	else
		v�kstur = �virkaVaksa;
	// y = L / (1+e^(-k*x)); L: toppunkt; k: boyggilsi; u: t��in; u0: midpunkt
	// Finna x0...
	// Hvar eru vit � x? x = ln(1/((L/y)-1))/k
	double mestalagi� = �virkaMaxMongd * fiskaMongd;

	if(mongd < mestalagi�){
	double x = log(1 / ((mestalagi� / (double)mongd) - 1.0)) / v�kstur;
	double v�ksturinDaginEftir = mestalagi� / (1.0 + exp(-v�kstur*(x + 1.0)));
	return v�ksturinDaginEftir - mongd;
	}
	else
	{
		return mestalagi�;
	}
}

int HSn�kur::fiskurDoyr(int fiskaMongd, double fiskaVekt)
{
	// Parametrar sum vit hava br�k fyri...
	std::random_device rd;
	std::mt19937 gen(rd());

	std::normal_distribution<> d(umH�ttan->getDrepur()*mongd, umH�ttan->getDrepurDeviation()*mongd); /// Sett ta� fyribils � eitt deviation upp� 20%
	int �rslit = d(gen);

	if (�rslit < 0)
		�rslit = 0;

	return �rslit;
}

double HSn�kur::fiskurF�rStress(int fiskaMongd, double fiskaVekt)
{
	//y = 1-(e^(-k*x))
	//k = ln(-1/(y-1))/x
	//double k = log(1 / (0.8 - 1)) / fiskaMongd;

	double l�samongdPrFisk = (double)mongd / fiskaMongd;
	// k=log(-1/(y-1))/x  // 4 l�s pr fisk gevur 80% stress.

	double k = umH�ttan->getStressK();
	double y = 1-(exp(-k*l�samongdPrFisk));

	// SO KANN MAN EISINI PROGRAMERA UPP�, AT FISKAMONGDIN SKAL EISINI VERA EIN PARAMETUR AT TAKA H�DD UPP�..
	// Hetta er vi� l�s. K�purin � ��rum hondum.. skal stressa fiskin minni, um fiskavekin ikki er so st�r.

	return y*100;
}

void HSn�kur::addaMongd(int pMongd, int fiskaMongd, double fiskaVekt)
{
	if (mongd + pMongd <= �virkaMaxMongd*fiskaMongd)
		mongd = mongd + pMongd;
	else
		mongd = �virkaMaxMongd*fiskaMongd;
}