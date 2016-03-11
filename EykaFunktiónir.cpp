#include "EykaFunktiónir.h"

double fiskurEtur(int mánağur, double fiskaStødd, double biomassi, double** sfr)
{
	int fiskTypa = 0;

	if (fiskaStødd < 0.100)
		fiskTypa = 0;
	else
		if (fiskaStødd < 0.300)
			fiskTypa = 1;
		else
			if (fiskaStødd < 0.500)
				fiskTypa = 2;
			else
				if (fiskaStødd < 1.000)
					fiskTypa = 3;
				else
					if (fiskaStødd < 2.000)
						fiskTypa = 4;
					else
						if (fiskaStødd < 4.000)
							fiskTypa = 5;
						else
							if (fiskaStødd < 6.000)
								fiskTypa = 6;
							else
								fiskTypa = 7;

	return sfr[mánağur][fiskTypa] * biomassi / 100;
}

unique_ptr<Hóttan> addaHóttan(shared_ptr<HóttanDetail> hd)
{
	if (hd->getTypaAvHóttan() == "Djór")
		return unique_ptr<Hóttan>(new HDjór(hd));
	else
		if (hd->getTypaAvHóttan() == "Sníkur")
			return unique_ptr<Hóttan>(new HSníkur(hd));
		else
			if (hd->getTypaAvHóttan() == "Sjúka")
				return unique_ptr<Hóttan>(new HSjúka(hd));
			else
				if (hd->getTypaAvHóttan() == "Náttúra")
					return unique_ptr<Hóttan>(new HNáttúra(hd));

throw("Typan av Hottan var ikki funnid.");
}

//template <typename T>
/*bool ávirkaParametur(unique_ptr<Hóttan>& h,MótstøğaÁvirkan ma)
{
	if (ma.getHvørHóttan() == h->getDetail()->getNavn())
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

/*template<typename T>
void ávirkaMótstøğuHátt(MótstøğaÁvirkan ma, T& parameturin)
{
	switch (ma.getMótstøğuHáttur())
	{
	case MONGD:
		parameturin = parameturin - ma.getMongdÁvirkan();
		break;
	case PROSENT:
		parameturin = parameturin - (parameturin * ma.getMongdÁvirkan() / 100);
		break;
	default:
		break;
	}
}*/