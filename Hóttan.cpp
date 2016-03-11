#include "Hóttan.h"

Hóttan::Hóttan()
{
	mongd = 0;
}

Hóttan::Hóttan(shared_ptr<HóttanDetail> hd, int pMongd)
{
	umHóttan = hd;
	mongd = pMongd;
	nullstillaÁvirkanir();
}

Hóttan::~Hóttan()
{
}

void Hóttan::addaMongd(int pMongd, int fiskaMongd, double fiskaVekt)
{
	if (mongd + pMongd <= umHóttan->getMaxMongd())
		mongd = mongd + pMongd;
	else
		mongd = umHóttan->getMaxMongd();
}

void Hóttan::nullstillaÁvirkanir()
{
	ávirkaMaxMongd = umHóttan->getMaxMongd();
	ávirkaTjansur = umHóttan->getTjansur();
	ávirkaTjansurDeviation = umHóttan->getTjansurDeviation();
	ávirkaVaksa = umHóttan->getVaksa();
	ávirkaVaksaDeviation = umHóttan->getVaksaDeviation();
}

bool Hóttan::ávirkaParametur(MótstøğaÁvirkan ma)
{
	if (ma.getHvørHóttan() == umHóttan->getNavn())
	{
		if (ma.getHvatÍHóttanini() == "mongd")
		{
			ávirkaMótstøğuHátt(ma, mongd);
		}
		else
			if (ma.getHvatÍHóttanini() == "maxMongd")
			{
				ávirkaMótstøğuHátt(ma, ávirkaMaxMongd);
			}
			else
				if (ma.getHvatÍHóttanini() == "tjansur")
				{
					ávirkaMótstøğuHátt(ma, ávirkaTjansur);
				}
				else
					if (ma.getHvatÍHóttanini() == "tjansurDeviation")
					{
						ávirkaMótstøğuHátt(ma, ávirkaTjansurDeviation);
					}
					else
						if (ma.getHvatÍHóttanini() == "vaksa")
						{
							ávirkaMótstøğuHátt(ma, ávirkaVaksa);
						}
						else
							if (ma.getHvatÍHóttanini() == "vaksaDeviation")
							{
								ávirkaMótstøğuHátt(ma, ávirkaVaksaDeviation);
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
bool Hóttan::ávirkaParametur(MótstøğaÁvirkan ma)
{
	if (ma.getHvørHóttan() == umHóttan->getNavn())
	{
		T *parameturin;

		if (ma.getHvatÍHóttanini() == "mongd")
			parameturin = &mongd;
		else
			if (ma.getHvatÍHóttanini() == "tjansur")
				parameturin = &ávirkaTjansur;
			else
				if (ma.getHvatÍHóttanini() == "tjansurDeviation")
					parameturin = &ávirkaTjansurDeviation;
				else
					if (ma.getHvatÍHóttanini() == "vaksa")
						parameturin = &ávirkaVaksa;
					else
						if (ma.getHvatÍHóttanini() == "vaksaDeviation")
							parameturin = &ávirkaVaksaDeviation;
						else
						{
							parameturin = nullptr;
							delete parameturin;
							return true;
						}

		switch (ma.getMótstøğuHáttur())
		{
		case MONGD:
			*parameturin = *parameturin - ma.getMongdÁvirkan();
			break;
		case PROSENT:
			*parameturin = *parameturin - ((*parameturin) * ma.getMongdÁvirkan() / 100);
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

int Hóttan::operator+ (const int& a)
{
		return mongd + a;
}

int Hóttan::operator- (const int& a)
{
		return mongd - a;
}