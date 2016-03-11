#include "AliringÁvirkan.h"

//template<typename Hót, typename Mót>
AliringÁvirkan/*<Hót, Mót>*/::AliringÁvirkan()
{
	mótstøğurHavaBroyttSeg = false;
}

AliringÁvirkan::~AliringÁvirkan()
{
}

void AliringÁvirkan::hóttanirTakaEffect(Fiskur fisk, const int mğr, int &deyğirFiskar, double &stressFingiğ)
{
	std::for_each(hóttanirÍAliringinum.begin(), hóttanirÍAliringinum.end(), [&](unique_ptr<Hóttan>& h) {
		deyğirFiskar = deyğirFiskar + h->fiskurDoyr(fisk.getFiskaMongd(), fisk.getMiğalVekt());
		stressFingiğ = stressFingiğ + h->fiskurFærStress(fisk.getFiskaMongd(), fisk.getMiğalVekt());
	});
}

void AliringÁvirkan::hóttanirVaksaOgMinka(Fiskur fisk, const int mğr)
{
	std::for_each(hóttanirÍAliringinum.begin(), hóttanirÍAliringinum.end(), [&](unique_ptr<Hóttan>& h) {
		h->veksurOgMinkar(fisk.getFiskaMongd(), fisk.getMiğalVekt(), mğr);
	});
}

int AliringÁvirkan::hóttanKemur(shared_ptr<HóttanDetail> hd, int fiskamongd, double fiskaVekt, int mğr) // Addar hóttan frá uttanfrá. RETURN: mongd komiğ afturat.
{
	int mongdKomiğ = 0;
	bool hóttanErInni = false;

	// Kannar her um hóttanin er inni í aliringinum, um so, spæl viğ mongdina
	std::find_if(hóttanirÍAliringinum.begin(), hóttanirÍAliringinum.end(), [&](unique_ptr<Hóttan>& h) {
		if(*hd == *h->getDetail())
		{
			hóttanErInni = true;
			int mongdÁğrenn = h->getMongd();
			h->addaMongd(h->mongdAvHóttanSumKemur(fiskamongd,fiskaVekt,mğr),fiskamongd,fiskaVekt);
			h->addaMongd(h->mongdAvHóttanSumFer(fiskamongd,fiskaVekt,mğr), fiskamongd, fiskaVekt);
			mongdKomiğ = h->getMongd() - mongdÁğrenn;

			if (h->getMongd() <= 0)
				hóttanirÍAliringinum.remove(h);
			return true;
		}
		return false;
	});

	// Um so Hóttain ikki var í aliringinum, adda, og set eina mongd í
	if (!hóttanErInni)
	{
		try{
			hóttanirÍAliringinum.push_back(addaHóttan(hd)); // addaHóttan(shared_ptr<Hóttan>) er inni í eyka funktiónir
		
			hóttanirÍAliringinum.back().get()->addaMongd(hóttanirÍAliringinum.back().get()->mongdAvHóttanSumKemur(fiskamongd,fiskaVekt, mğr), fiskamongd, fiskaVekt);
			hóttanirÍAliringinum.back().get()->addaMongd(hóttanirÍAliringinum.back().get()->mongdAvHóttanSumFer(fiskamongd, fiskaVekt, mğr), fiskamongd, fiskaVekt);
			mongdKomiğ = hóttanirÍAliringinum.back().get()->getMongd();
			if (mongdKomiğ <= 0)
				hóttanirÍAliringinum.pop_back();

		} catch(std::exception e)
		{ 
			std::cerr << e.what();
		}
	}

	return mongdKomiğ;
}

bool AliringÁvirkan::hevurHóttan(shared_ptr<HóttanDetail> hd)
{
	bool funniğ = false;
	std::find_if(hóttanirÍAliringinum.begin(), hóttanirÍAliringinum.end(), [hd,&funniğ](unique_ptr<Hóttan>& h) {
		if (hd->getNavn() == h->getDetail()->getNavn())
		{
			funniğ = true;
			return true;
		}
		return false;
	});

	return funniğ;
}

int AliringÁvirkan::getMongdAvHóttan(string hóttanNavn)
{
	for (list<unique_ptr<Hóttan>>::iterator it = hóttanirÍAliringinum.begin(); it != hóttanirÍAliringinum.end(); it++)
		if (hóttanNavn == it->get()->getDetail()->getNavn())
			return it->get()->getMongd();
	return 0;
}

bool AliringÁvirkan::addaMótstøğa(shared_ptr<MótstøğaDetail> md, int dagur)
{
	bool funniğ = false;
	// if mótstøğa ikki finst í aliringinum
	std::find_if(mótstøğurÍAliringinum.begin(), mótstøğurÍAliringinum.end(), [md, &funniğ](unique_ptr<Mótstøğa>& m) {
		if (m->getMótstøğaDetail() == md)
		{
			funniğ = true;
			return true;
		}
		return false;
	});
	// do: set mótstøğuna í listan
	if(!funniğ)
	{
		mótstøğurÍAliringinum.push_back(unique_ptr<Mótstøğa>(new Mótstøğa(md, dagur)));
		mótstøğurHavaBroyttSeg = true;
		return true;
	}
	else
	return false;
}

bool AliringÁvirkan::takaMótstøğaÚr(shared_ptr<MótstøğaDetail> md)
{
	bool funniğ = false;
	// Finn mótstøğuna í aliringinum
	for (list<unique_ptr<Mótstøğa>>::iterator it = mótstøğurÍAliringinum.begin(); it != mótstøğurÍAliringinum.end(); it++)
	{
		// Tak mótstøğuna úr listanum
		if (it->get()->getMótstøğaDetail() == md)
		{
			mótstøğurÍAliringinum.erase(it);
			mótstøğurHavaBroyttSeg = true;
			return true;
		}
	}
	// Mótstøğan finst ikki:
	return false;
}

void AliringÁvirkan::mótstøğurÁvirka()
{
	// Um onkrar mótstøğur eru komnar, ella farnar...
	if (mótstøğurHavaBroyttSeg)
	{
		// nullstilla hóttanir, so at hóttanir virka aftur sum normalt
		std::for_each(hóttanirÍAliringinum.begin(), hóttanirÍAliringinum.end(), [](unique_ptr<Hóttan>& h) {
			h->nullstillaÁvirkanir();
		});

		// Far ígjøgnum mótstøğur og finn útav hvat skal broytast inni í hóttanir.
		for (list<unique_ptr<Mótstøğa>>::iterator itM = mótstøğurÍAliringinum.begin();itM != mótstøğurÍAliringinum.end();itM++)
		{
			/*for (list<MótstøğaÁvirkan>::iterator itMá = itM->get()->getMótstøğaDetail()->getÁvirkanir().begin(); itMá != itM->get()->getMótstøğaDetail()->getÁvirkanir().end(); itMá++)
			{
				for (list<unique_ptr<Hóttan>>::iterator itHó = hóttanirÍAliringinum.begin(); itHó != hóttanirÍAliringinum.end();itHó++)
				{
						itHó->get()->ávirkaParametur(*itMá);
				}
			}*/
			list<MótstøğaÁvirkan> lMa = itM->get()->getMótstøğaDetail()->getÁvirkanir();
			std::for_each(lMa.begin(), lMa.end(), [&](MótstøğaÁvirkan pMa) {
				for (list<unique_ptr<Hóttan>>::iterator itHó = hóttanirÍAliringinum.begin(); itHó != hóttanirÍAliringinum.end(); itHó++)
				{
					itHó->get()->ávirkaParametur(pMa);
				}
			});	
		}
		mótstøğurHavaBroyttSeg = false;
	}
}

void AliringÁvirkan::mótstøğurGangaÚt(int dagur)
{
	for (list<unique_ptr<Mótstøğa>>::iterator it = mótstøğurÍAliringinum.begin(); it != mótstøğurÍAliringinum.end(); )
	{
		if (it->get()->gingiğÚt(dagur))
		{
			auto it2 = it;
			it++;
			mótstøğurÍAliringinum.erase(it2); // Bara so at "it" ikki peikar á onki.
		}
		else
		{
			it++;
		}
	}
}