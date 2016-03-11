#include "H�ttan.h"

H�ttan::H�ttan()
{
	mongd = 0;
}

H�ttan::H�ttan(shared_ptr<H�ttanDetail> hd, int pMongd)
{
	umH�ttan = hd;
	mongd = pMongd;
	nullstilla�virkanir();
}

H�ttan::~H�ttan()
{
}

void H�ttan::addaMongd(int pMongd, int fiskaMongd, double fiskaVekt)
{
	if (mongd + pMongd <= umH�ttan->getMaxMongd())
		mongd = mongd + pMongd;
	else
		mongd = umH�ttan->getMaxMongd();
}

void H�ttan::nullstilla�virkanir()
{
	�virkaMaxMongd = umH�ttan->getMaxMongd();
	�virkaTjansur = umH�ttan->getTjansur();
	�virkaTjansurDeviation = umH�ttan->getTjansurDeviation();
	�virkaVaksa = umH�ttan->getVaksa();
	�virkaVaksaDeviation = umH�ttan->getVaksaDeviation();
}

bool H�ttan::�virkaParametur(M�tst��a�virkan ma)
{
	if (ma.getHv�rH�ttan() == umH�ttan->getNavn())
	{
		if (ma.getHvat�H�ttanini() == "mongd")
		{
			�virkaM�tst��uH�tt(ma, mongd);
		}
		else
			if (ma.getHvat�H�ttanini() == "maxMongd")
			{
				�virkaM�tst��uH�tt(ma, �virkaMaxMongd);
			}
			else
				if (ma.getHvat�H�ttanini() == "tjansur")
				{
					�virkaM�tst��uH�tt(ma, �virkaTjansur);
				}
				else
					if (ma.getHvat�H�ttanini() == "tjansurDeviation")
					{
						�virkaM�tst��uH�tt(ma, �virkaTjansurDeviation);
					}
					else
						if (ma.getHvat�H�ttanini() == "vaksa")
						{
							�virkaM�tst��uH�tt(ma, �virkaVaksa);
						}
						else
							if (ma.getHvat�H�ttanini() == "vaksaDeviation")
							{
								�virkaM�tst��uH�tt(ma, �virkaVaksaDeviation);
							}
							else
							{
								return true;
							}

		return true;
	}
	return false;
}

/*
template <typename T>
bool H�ttan::�virkaParametur(M�tst��a�virkan ma)
{
	if (ma.getHv�rH�ttan() == umH�ttan->getNavn())
	{
		T *parameturin;

		if (ma.getHvat�H�ttanini() == "mongd")
			parameturin = &mongd;
		else
			if (ma.getHvat�H�ttanini() == "tjansur")
				parameturin = &�virkaTjansur;
			else
				if (ma.getHvat�H�ttanini() == "tjansurDeviation")
					parameturin = &�virkaTjansurDeviation;
				else
					if (ma.getHvat�H�ttanini() == "vaksa")
						parameturin = &�virkaVaksa;
					else
						if (ma.getHvat�H�ttanini() == "vaksaDeviation")
							parameturin = &�virkaVaksaDeviation;
						else
						{
							parameturin = nullptr;
							delete parameturin;
							return true;
						}

		switch (ma.getM�tst��uH�ttur())
		{
		case MONGD:
			*parameturin = *parameturin - ma.getMongd�virkan();
			break;
		case PROSENT:
			*parameturin = *parameturin - ((*parameturin) * ma.getMongd�virkan() / 100);
			break;
		default:
			break;
		}
		parameturin = nullptr;
		delete parameturin;
		return true;
	}
	return false;
}*/

int H�ttan::operator+ (const int& a)
{
		return mongd + a;
}

int H�ttan::operator- (const int& a)
{
		return mongd - a;
}