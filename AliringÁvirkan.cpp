#include "Aliring�virkan.h"

//template<typename H�t, typename M�t>
Aliring�virkan/*<H�t, M�t>*/::Aliring�virkan()
{
	m�tst��urHavaBroyttSeg = false;
}

Aliring�virkan::~Aliring�virkan()
{
}

void Aliring�virkan::h�ttanirTakaEffect(Fiskur fisk, const int m�r, int &dey�irFiskar, double &stressFingi�)
{
	std::for_each(h�ttanir�Aliringinum.begin(), h�ttanir�Aliringinum.end(), [&](unique_ptr<H�ttan>& h) {
		dey�irFiskar = dey�irFiskar + h->fiskurDoyr(fisk.getFiskaMongd(), fisk.getMi�alVekt());
		stressFingi� = stressFingi� + h->fiskurF�rStress(fisk.getFiskaMongd(), fisk.getMi�alVekt());
	});
}

void Aliring�virkan::h�ttanirVaksaOgMinka(Fiskur fisk, const int m�r)
{
	std::for_each(h�ttanir�Aliringinum.begin(), h�ttanir�Aliringinum.end(), [&](unique_ptr<H�ttan>& h) {
		h->veksurOgMinkar(fisk.getFiskaMongd(), fisk.getMi�alVekt(), m�r);
	});
}

int Aliring�virkan::h�ttanKemur(shared_ptr<H�ttanDetail> hd, int fiskamongd, double fiskaVekt, int m�r) // Addar h�ttan fr� uttanfr�. RETURN: mongd komi� afturat.
{
	int mongdKomi� = 0;
	bool h�ttanErInni = false;

	// Kannar her um h�ttanin er inni � aliringinum, um so, sp�l vi� mongdina
	std::find_if(h�ttanir�Aliringinum.begin(), h�ttanir�Aliringinum.end(), [&](unique_ptr<H�ttan>& h) {
		if(*hd == *h->getDetail())
		{
			h�ttanErInni = true;
			int mongd��renn = h->getMongd();
			h->addaMongd(h->mongdAvH�ttanSumKemur(fiskamongd,fiskaVekt,m�r),fiskamongd,fiskaVekt);
			h->addaMongd(h->mongdAvH�ttanSumFer(fiskamongd,fiskaVekt,m�r), fiskamongd, fiskaVekt);
			mongdKomi� = h->getMongd() - mongd��renn;

			if (h->getMongd() <= 0)
				h�ttanir�Aliringinum.remove(h);
			return true;
		}
		return false;
	});

	// Um so H�ttain ikki var � aliringinum, adda, og set eina mongd �
	if (!h�ttanErInni)
	{
		try{
			h�ttanir�Aliringinum.push_back(addaH�ttan(hd)); // addaH�ttan(shared_ptr<H�ttan>) er inni � eyka funkti�nir
		
			h�ttanir�Aliringinum.back().get()->addaMongd(h�ttanir�Aliringinum.back().get()->mongdAvH�ttanSumKemur(fiskamongd,fiskaVekt, m�r), fiskamongd, fiskaVekt);
			h�ttanir�Aliringinum.back().get()->addaMongd(h�ttanir�Aliringinum.back().get()->mongdAvH�ttanSumFer(fiskamongd, fiskaVekt, m�r), fiskamongd, fiskaVekt);
			mongdKomi� = h�ttanir�Aliringinum.back().get()->getMongd();
			if (mongdKomi� <= 0)
				h�ttanir�Aliringinum.pop_back();

		} catch(std::exception e)
		{ 
			std::cerr << e.what();
		}
	}

	return mongdKomi�;
}

bool Aliring�virkan::hevurH�ttan(shared_ptr<H�ttanDetail> hd)
{
	bool funni� = false;
	std::find_if(h�ttanir�Aliringinum.begin(), h�ttanir�Aliringinum.end(), [hd,&funni�](unique_ptr<H�ttan>& h) {
		if (hd->getNavn() == h->getDetail()->getNavn())
		{
			funni� = true;
			return true;
		}
		return false;
	});

	return funni�;
}

int Aliring�virkan::getMongdAvH�ttan(string h�ttanNavn)
{
	for (list<unique_ptr<H�ttan>>::iterator it = h�ttanir�Aliringinum.begin(); it != h�ttanir�Aliringinum.end(); it++)
		if (h�ttanNavn == it->get()->getDetail()->getNavn())
			return it->get()->getMongd();
	return 0;
}

bool Aliring�virkan::addaM�tst��a(shared_ptr<M�tst��aDetail> md, int dagur)
{
	bool funni� = false;
	// if m�tst��a ikki finst � aliringinum
	std::find_if(m�tst��ur�Aliringinum.begin(), m�tst��ur�Aliringinum.end(), [md, &funni�](unique_ptr<M�tst��a>& m) {
		if (m->getM�tst��aDetail() == md)
		{
			funni� = true;
			return true;
		}
		return false;
	});
	// do: set m�tst��una � listan
	if(!funni�)
	{
		m�tst��ur�Aliringinum.push_back(unique_ptr<M�tst��a>(new M�tst��a(md, dagur)));
		m�tst��urHavaBroyttSeg = true;
		return true;
	}
	else
	return false;
}

bool Aliring�virkan::takaM�tst��a�r(shared_ptr<M�tst��aDetail> md)
{
	bool funni� = false;
	// Finn m�tst��una � aliringinum
	for (list<unique_ptr<M�tst��a>>::iterator it = m�tst��ur�Aliringinum.begin(); it != m�tst��ur�Aliringinum.end(); it++)
	{
		// Tak m�tst��una �r listanum
		if (it->get()->getM�tst��aDetail() == md)
		{
			m�tst��ur�Aliringinum.erase(it);
			m�tst��urHavaBroyttSeg = true;
			return true;
		}
	}
	// M�tst��an finst ikki:
	return false;
}

void Aliring�virkan::m�tst��ur�virka()
{
	// Um onkrar m�tst��ur eru komnar, ella farnar...
	if (m�tst��urHavaBroyttSeg)
	{
		// nullstilla h�ttanir, so at h�ttanir virka aftur sum normalt
		std::for_each(h�ttanir�Aliringinum.begin(), h�ttanir�Aliringinum.end(), [](unique_ptr<H�ttan>& h) {
			h->nullstilla�virkanir();
		});

		// Far �gj�gnum m�tst��ur og finn �tav hvat skal broytast inni � h�ttanir.
		for (list<unique_ptr<M�tst��a>>::iterator itM = m�tst��ur�Aliringinum.begin();itM != m�tst��ur�Aliringinum.end();itM++)
		{
			/*for (list<M�tst��a�virkan>::iterator itM� = itM->get()->getM�tst��aDetail()->get�virkanir().begin(); itM� != itM->get()->getM�tst��aDetail()->get�virkanir().end(); itM�++)
			{
				for (list<unique_ptr<H�ttan>>::iterator itH� = h�ttanir�Aliringinum.begin(); itH� != h�ttanir�Aliringinum.end();itH�++)
				{
						itH�->get()->�virkaParametur(*itM�);
				}
			}*/
			list<M�tst��a�virkan> lMa = itM->get()->getM�tst��aDetail()->get�virkanir();
			std::for_each(lMa.begin(), lMa.end(), [&](M�tst��a�virkan pMa) {
				for (list<unique_ptr<H�ttan>>::iterator itH� = h�ttanir�Aliringinum.begin(); itH� != h�ttanir�Aliringinum.end(); itH�++)
				{
					itH�->get()->�virkaParametur(pMa);
				}
			});	
		}
		m�tst��urHavaBroyttSeg = false;
	}
}

void Aliring�virkan::m�tst��urGanga�t(int dagur)
{
	for (list<unique_ptr<M�tst��a>>::iterator it = m�tst��ur�Aliringinum.begin(); it != m�tst��ur�Aliringinum.end(); )
	{
		if (it->get()->gingi��t(dagur))
		{
			auto it2 = it;
			it++;
			m�tst��ur�Aliringinum.erase(it2); // Bara so at "it" ikki peikar � onki.
		}
		else
		{
			it++;
		}
	}
}