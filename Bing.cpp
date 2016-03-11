#include "Bing.h"
#include <iostream>

Bing::Bing(fTypa f, double pMaxSiloVekt)
{
	ft = shared_ptr<F��urTypa>(new F��urTypa(f));
	maxSiloVekt = pMaxSiloVekt;
	�SiloVekt = 0;
	r�mmetrar = -1;
}

Bing::~Bing()
{
}

double Bing::adda�Silo(double f��urMongd)
{
	if (f��urMongd <= maxSiloVekt - �SiloVekt)
	{
		�SiloVekt = �SiloVekt + f��urMongd;
	}
	else
	{
		f��urMongd = maxSiloVekt - �SiloVekt;
		�SiloVekt = maxSiloVekt;
	}

	return f��urMongd;
}

double Bing::taka�rSilo(double f��urMongd)
{
	if(�SiloVekt >= f��urMongd)
	{
		�SiloVekt = �SiloVekt - f��urMongd;
	}
	else
	{
		f��urMongd = �SiloVekt;
		�SiloVekt = 0;
	}

	return f��urMongd;
}

bool Bing::erT�m()
{
	return �SiloVekt == 0;
}

std::ostream& operator<<(std::ostream& os, Bing& obj)
{
	os << "Fodur typa: " << obj.getF��urTypa()->getTypaNavn() << std::endl;
	os << "Sum er til laks millum: " << obj.getF��urTypa()->getMinSt�ddKg() << " - " << obj.getF��urTypa()->getMaxSt�ddKg() << " kg." << std::endl;
	os << "Har er: " << obj.get�Silo() << " av " << obj.getMaxSiloVekt() << " kg i silo." << std::endl;

	return os;
}