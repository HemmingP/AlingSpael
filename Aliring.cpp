#include "Aliring.h"
#include <iostream>

Aliring::Aliring() : fiskur(Fiskur("Laks", 16801, 50000, -1, 0, shared_ptr<FiskaL�vfr��i>(new FiskaL�vfr��i())))
{
	navn = "TestAliring1";
	automatiskF��ring = true;
	//biomassi = 16801;
	//maxFiskaVekt = -1;
	//fiskamongd = 50000;
	//st�ddCm = -1;
	f��urPrDag = 200;
	f��urGivi�Seinast = 0;
	aliCubic = -1;
	iltInnihald = -1;
	//stress = 0;
	f��urTilSpillisSeinast = 0;
	dagurSkapt = 0;
}

Aliring::Aliring(string pNavn, double pBiomassi, int pFiskamongd, std::shared_ptr<FiskaL�vfr��i> fiskL, int pDagurSkapt)
	: fiskur(Fiskur("Laks", pBiomassi, pFiskamongd, -1, 0, fiskL))
{
	navn = pNavn;
	automatiskF��ring = true;
	f��urPrDag = 200;
	f��urGivi�Seinast = 0;
	aliCubic = -1;
	iltInnihald = -1;
	f��urTilSpillisSeinast = 0;
	dagurSkapt = pDagurSkapt;
}


Aliring::~Aliring()
{
}

void Aliring::fiskaV�kstur(int m�r, Alist��& alist��, int dagur)
{
	double biomassi = fiskur.getBiomassi();
	int fiskaMongd = fiskur.getFiskaMongd();
	double maxFiskaVekt = fiskur.getMaxFiskaVekt();
	double stress = fiskur.getStrongd();

	 double fiskurinVilHava = fiskur.getFiskaL�vfr��i()->fiskaf��urVilHavaPrDag(m�r,biomassi/fiskaMongd,biomassi,alist��.getSfr()); // Skap hvat fiskurin vil hava

	 if(automatiskF��ring)	// Instillar h�ttin, br�karin hevur valt at f��ra upp�.
	 {
		 f��urPrDag = fiskurEtur(m�r, biomassi / fiskaMongd, biomassi, alist��.getSfr()); 
		 // Manuel f��ring skal f�a eitt verd�, t� br�karin sl�r ta� til.
	 }
	 else
	 {

	 }

	 f��urGivi�Seinast = alist��.gevaF��ur(f��urPrDag, biomassi / fiskaMongd);

	 double biomassiN� = biomassi * fiskur.getFiskaL�vfr��i()->v�ksturinPrDag(f��urGivi�Seinast, fiskurinVilHava, biomassi, maxFiskaVekt, dagur - dagurSkapt, stress); // t.d: 1000 kg * 1.1 = 1100 kg
	 f��urTilSpillisSeinast = f��urGivi�Seinast - fiskurinVilHava;
	 fiskur.setMaxFiskaVekt(maxFiskaVekt);
	 fiskur.addaUmBiomassan(biomassiN� - biomassi);
}

// ALLAR GET METHODUR ------------------------------
string Aliring::getNavn()
{
	return navn;
}

Fiskur Aliring::getFiskur()
{
	return fiskur;
}

bool Aliring::getAutomatiskF��ring()
{
	return automatiskF��ring;
}

double Aliring::getF��urPrDag()
{
	return f��urPrDag;
}

double Aliring::getF��urGivi�Seinast()
{
	return f��urGivi�Seinast;
}

double Aliring::getF��urTilSpillisSeinast()
{
	return f��urTilSpillisSeinast;
}

double Aliring::getAliCubic()
{
	return aliCubic;
}

double Aliring::getIltInnihald()
{
	return iltInnihald;
}

Aliring�virkan& Aliring::getAliring�virkanir()
{
	return �virkanir;
}

void Aliring::setAutomatisktF��ur(bool pAutomatiskF��ur)
{
	automatiskF��ring = pAutomatiskF��ur;
}

void Aliring::setF��urPrDag(double pF��urPrDag)
{
	f��urPrDag = pF��urPrDag;
}

void Aliring::allarH�ttanirKoma(Umhv�rvi�& u)
{
	for (list<shared_ptr<H�ttanDetail>>::iterator it = u.getBeginH�ttan(); it != u.getEndH�ttan(); it++)
	{
		�virkanir.h�ttanKemur(*it,fiskur.getFiskaMongd(),fiskur.getMi�alVekt(),0);
	}
}

int Aliring::risikeraH�ttan(shared_ptr<H�ttanDetail> hd, int m�r)
{
	// Vita um h�ttanin er inni � h�ttanir listanum
	list<unique_ptr<H�ttan>>::iterator start = �virkanir.getH�ttanir�Aliringinum().begin(), stop = �virkanir.getH�ttanir�Aliringinum().end();

	//	std::cout << it->get()->getDetail();

	while (start != stop)
	{
		if (start->get()->getDetail()->getNavn() == hd->getNavn()) {
			if(start->get()->getMongd() > 0)
			{
				fiskur.addaStrongd(start->get()->fiskurF�rStress(fiskur.getFiskaMongd(), fiskur.getMi�alVekt()));

				fiskur.minkaUmMongd(start->get()->fiskurDoyr(fiskur.getFiskaMongd(), fiskur.getMi�alVekt()));

				int fyrrverandiMongdAvH�ttan = start->get()->getMongd();
				int mongdSumKemur = start->get()->veksurOgMinkar(fiskur.getFiskaMongd(), fiskur.getMi�alVekt(), m�r);
				start->get()->addaMongd(mongdSumKemur, fiskur.getFiskaMongd(), fiskur.getMi�alVekt());

				return start->get()->getMongd() - fyrrverandiMongdAvH�ttan;
			}
			else
			{
				�virkanir.getH�ttanir�Aliringinum().erase(start);
				return 0;
			}
		}
		start++;
	}
}

void Aliring::risikeraAllarH�ttanir(int m�r)
{
	int dey�i = 0;
	double strongd = 0;

	�virkanir.h�ttanirTakaEffect(fiskur, m�r, dey�i, strongd);
	//�virkanir.getH�ttanir�Aliringinum().begin()->get()->veksurOgMinkar(fiskur.getFiskaMongd(),fiskur.getMi�alVekt(),0);
	�virkanir.h�ttanirVaksaOgMinka(fiskur,0);

	fiskur.minkaUmMongd(dey�i);
	fiskur.addaStrongd(strongd);
}

void Aliring::addaStrongd(double s)
{
	fiskur.addaStrongd(s);
}