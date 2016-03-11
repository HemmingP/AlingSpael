#include "EykaFunkti�nir.h"

double fiskurEtur(int m�na�ur, double fiskaSt�dd, double biomassi, double** sfr)
{
	int fiskTypa = 0;

	if (fiskaSt�dd < 0.100)
		fiskTypa = 0;
	else
		if (fiskaSt�dd < 0.300)
			fiskTypa = 1;
		else
			if (fiskaSt�dd < 0.500)
				fiskTypa = 2;
			else
				if (fiskaSt�dd < 1.000)
					fiskTypa = 3;
				else
					if (fiskaSt�dd < 2.000)
						fiskTypa = 4;
					else
						if (fiskaSt�dd < 4.000)
							fiskTypa = 5;
						else
							if (fiskaSt�dd < 6.000)
								fiskTypa = 6;
							else
								fiskTypa = 7;

	return sfr[m�na�ur][fiskTypa] * biomassi / 100;
}

unique_ptr<H�ttan> addaH�ttan(shared_ptr<H�ttanDetail> hd)
{
	if (hd->getTypaAvH�ttan() == "Dj�r")
		return unique_ptr<H�ttan>(new HDj�r(hd));
	else
		if (hd->getTypaAvH�ttan() == "Sn�kur")
			return unique_ptr<H�ttan>(new HSn�kur(hd));
		else
			if (hd->getTypaAvH�ttan() == "Sj�ka")
				return unique_ptr<H�ttan>(new HSj�ka(hd));
			else
				if (hd->getTypaAvH�ttan() == "N�tt�ra")
					return unique_ptr<H�ttan>(new HN�tt�ra(hd));

throw("Typan av Hottan var ikki funnid.");
}

//template <typename T>
/*bool �virkaParametur(unique_ptr<H�ttan>& h,M�tst��a�virkan ma)
{
	if (ma.getHv�rH�ttan() == h->getDetail()->getNavn())
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

/*template<typename T>
void �virkaM�tst��uH�tt(M�tst��a�virkan ma, T& parameturin)
{
	switch (ma.getM�tst��uH�ttur())
	{
	case MONGD:
		parameturin = parameturin - ma.getMongd�virkan();
		break;
	case PROSENT:
		parameturin = parameturin - (parameturin * ma.getMongd�virkan() / 100);
		break;
	default:
		break;
	}
}*/