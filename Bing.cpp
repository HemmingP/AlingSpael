#include "Bing.h"
#include <iostream>

Bing::Bing(fTypa f, double pMaxSiloVekt)
{
	ft = shared_ptr<FóðurTypa>(new FóðurTypa(f));
	maxSiloVekt = pMaxSiloVekt;
	íSiloVekt = 0;
	rúmmetrar = -1;
}

Bing::~Bing()
{
}

double Bing::addaÍSilo(double fóðurMongd)
{
	if (fóðurMongd <= maxSiloVekt - íSiloVekt)
	{
		íSiloVekt = íSiloVekt + fóðurMongd;
	}
	else
	{
		fóðurMongd = maxSiloVekt - íSiloVekt;
		íSiloVekt = maxSiloVekt;
	}

	return fóðurMongd;
}

double Bing::takaÚrSilo(double fóðurMongd)
{
	if(íSiloVekt >= fóðurMongd)
	{
		íSiloVekt = íSiloVekt - fóðurMongd;
	}
	else
	{
		fóðurMongd = íSiloVekt;
		íSiloVekt = 0;
	}

	return fóðurMongd;
}

bool Bing::erTóm()
{
	return íSiloVekt == 0;
}

std::ostream& operator<<(std::ostream& os, Bing& obj)
{
	os << "Fodur typa: " << obj.getFóðurTypa()->getTypaNavn() << std::endl;
	os << "Sum er til laks millum: " << obj.getFóðurTypa()->getMinStøddKg() << " - " << obj.getFóðurTypa()->getMaxStøddKg() << " kg." << std::endl;
	os << "Har er: " << obj.getÍSilo() << " av " << obj.getMaxSiloVekt() << " kg i silo." << std::endl;

	return os;
}