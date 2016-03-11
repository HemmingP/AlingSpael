#include "Aliring.h"
#include <iostream>

Aliring::Aliring() : fiskur(Fiskur("Laks", 16801, 50000, -1, 0, shared_ptr<FiskaLívfrøði>(new FiskaLívfrøði())))
{
	navn = "TestAliring1";
	automatiskFóðring = true;
	//biomassi = 16801;
	//maxFiskaVekt = -1;
	//fiskamongd = 50000;
	//støddCm = -1;
	fóðurPrDag = 200;
	fóðurGiviðSeinast = 0;
	aliCubic = -1;
	iltInnihald = -1;
	//stress = 0;
	fóðurTilSpillisSeinast = 0;
	dagurSkapt = 0;
}

Aliring::Aliring(string pNavn, double pBiomassi, int pFiskamongd, std::shared_ptr<FiskaLívfrøði> fiskL, int pDagurSkapt)
	: fiskur(Fiskur("Laks", pBiomassi, pFiskamongd, -1, 0, fiskL))
{
	navn = pNavn;
	automatiskFóðring = true;
	fóðurPrDag = 200;
	fóðurGiviðSeinast = 0;
	aliCubic = -1;
	iltInnihald = -1;
	fóðurTilSpillisSeinast = 0;
	dagurSkapt = pDagurSkapt;
}


Aliring::~Aliring()
{
}

void Aliring::fiskaVøkstur(int mðr, Alistøð& alistøð, int dagur)
{
	double biomassi = fiskur.getBiomassi();
	int fiskaMongd = fiskur.getFiskaMongd();
	double maxFiskaVekt = fiskur.getMaxFiskaVekt();
	double stress = fiskur.getStrongd();

	 double fiskurinVilHava = fiskur.getFiskaLívfrøði()->fiskafóðurVilHavaPrDag(mðr,biomassi/fiskaMongd,biomassi,alistøð.getSfr()); // Skap hvat fiskurin vil hava

	 if(automatiskFóðring)	// Instillar háttin, brúkarin hevur valt at fóðra uppá.
	 {
		 fóðurPrDag = fiskurEtur(mðr, biomassi / fiskaMongd, biomassi, alistøð.getSfr()); 
		 // Manuel fóðring skal fáa eitt verdí, tá brúkarin slær tað til.
	 }
	 else
	 {

	 }

	 fóðurGiviðSeinast = alistøð.gevaFóður(fóðurPrDag, biomassi / fiskaMongd);

	 double biomassiNú = biomassi * fiskur.getFiskaLívfrøði()->vøksturinPrDag(fóðurGiviðSeinast, fiskurinVilHava, biomassi, maxFiskaVekt, dagur - dagurSkapt, stress); // t.d: 1000 kg * 1.1 = 1100 kg
	 fóðurTilSpillisSeinast = fóðurGiviðSeinast - fiskurinVilHava;
	 fiskur.setMaxFiskaVekt(maxFiskaVekt);
	 fiskur.addaUmBiomassan(biomassiNú - biomassi);
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

bool Aliring::getAutomatiskFóðring()
{
	return automatiskFóðring;
}

double Aliring::getFóðurPrDag()
{
	return fóðurPrDag;
}

double Aliring::getFóðurGiviðSeinast()
{
	return fóðurGiviðSeinast;
}

double Aliring::getFóðurTilSpillisSeinast()
{
	return fóðurTilSpillisSeinast;
}

double Aliring::getAliCubic()
{
	return aliCubic;
}

double Aliring::getIltInnihald()
{
	return iltInnihald;
}

AliringÁvirkan& Aliring::getAliringÁvirkanir()
{
	return ávirkanir;
}

void Aliring::setAutomatisktFóður(bool pAutomatiskFóður)
{
	automatiskFóðring = pAutomatiskFóður;
}

void Aliring::setFóðurPrDag(double pFóðurPrDag)
{
	fóðurPrDag = pFóðurPrDag;
}

void Aliring::allarHóttanirKoma(Umhvørvið& u)
{
	for (list<shared_ptr<HóttanDetail>>::iterator it = u.getBeginHóttan(); it != u.getEndHóttan(); it++)
	{
		ávirkanir.hóttanKemur(*it,fiskur.getFiskaMongd(),fiskur.getMiðalVekt(),0);
	}
}

int Aliring::risikeraHóttan(shared_ptr<HóttanDetail> hd, int mðr)
{
	// Vita um hóttanin er inni á hóttanir listanum
	list<unique_ptr<Hóttan>>::iterator start = ávirkanir.getHóttanirÍAliringinum().begin(), stop = ávirkanir.getHóttanirÍAliringinum().end();

	//	std::cout << it->get()->getDetail();

	while (start != stop)
	{
		if (start->get()->getDetail()->getNavn() == hd->getNavn()) {
			if(start->get()->getMongd() > 0)
			{
				fiskur.addaStrongd(start->get()->fiskurFærStress(fiskur.getFiskaMongd(), fiskur.getMiðalVekt()));

				fiskur.minkaUmMongd(start->get()->fiskurDoyr(fiskur.getFiskaMongd(), fiskur.getMiðalVekt()));

				int fyrrverandiMongdAvHóttan = start->get()->getMongd();
				int mongdSumKemur = start->get()->veksurOgMinkar(fiskur.getFiskaMongd(), fiskur.getMiðalVekt(), mðr);
				start->get()->addaMongd(mongdSumKemur, fiskur.getFiskaMongd(), fiskur.getMiðalVekt());

				return start->get()->getMongd() - fyrrverandiMongdAvHóttan;
			}
			else
			{
				ávirkanir.getHóttanirÍAliringinum().erase(start);
				return 0;
			}
		}
		start++;
	}
}

void Aliring::risikeraAllarHóttanir(int mðr)
{
	int deyði = 0;
	double strongd = 0;

	ávirkanir.hóttanirTakaEffect(fiskur, mðr, deyði, strongd);
	//ávirkanir.getHóttanirÍAliringinum().begin()->get()->veksurOgMinkar(fiskur.getFiskaMongd(),fiskur.getMiðalVekt(),0);
	ávirkanir.hóttanirVaksaOgMinka(fiskur,0);

	fiskur.minkaUmMongd(deyði);
	fiskur.addaStrongd(strongd);
}

void Aliring::addaStrongd(double s)
{
	fiskur.addaStrongd(s);
}