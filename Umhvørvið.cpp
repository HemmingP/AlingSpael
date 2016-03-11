#include "Umhv�rvi�.h"

Umhv�rvi�::Umhv�rvi�()
{
}

Umhv�rvi�::~Umhv�rvi�()
{
}

bool Umhv�rvi�::addaH�ttanSumKannKoma(shared_ptr<H�ttanDetail> h) // Hetta setur � tjansin at ein h�ttan kann koma
{
	for (list<shared_ptr<H�ttanDetail>>::iterator it = h�ttanir.begin(); it != h�ttanir.end(); it++)
	{
		if (*it == h)
		{
			return false;
		}
	}
	h�ttanir.push_back(h);
	return true;
}

bool Umhv�rvi�::fjernaH�ttanSumKannKoma(shared_ptr<H�ttanDetail> h)
{
	for (list<shared_ptr<H�ttanDetail>>::iterator it = h�ttanir.begin(); it != h�ttanir.end(); it++)
	{
		if (*it == h)
		{
			h�ttanir.erase(it);
			return true;
		}
	}
	return false;
}

string Umhv�rvi�::v�sAllarH�ttanirVi�Navni()
{
	string allarH�ttanir = "";

	for (list<shared_ptr<H�ttanDetail>>::iterator it = h�ttanir.begin(); it != h�ttanir.end();)
	{
		allarH�ttanir = allarH�ttanir + it->get()->getNavn();

		it++;

		if (it != h�ttanir.end())
			allarH�ttanir = allarH�ttanir + ", ";
	}

	return allarH�ttanir;
}

bool Umhv�rvi�::addaM�tst��aSumKannKoma(shared_ptr<M�tst��aDetail> m)
{
	for (list<shared_ptr<M�tst��aDetail>>::iterator it = m�tst��ur.begin(); it != m�tst��ur.end(); it++)
	{
		if (*it == m)
		{
			return false;
		}
	}
	m�tst��ur.push_back(m);
	return true;
}

bool Umhv�rvi�::fjernaM�tst��aSumKannKoma(shared_ptr<M�tst��aDetail> m)
{
	for (list<shared_ptr<M�tst��aDetail>>::iterator it = m�tst��ur.begin(); it != m�tst��ur.end(); it++)
	{
		if (*it == m)
		{
			m�tst��ur.erase(it);
			return true;
		}
	}
	return false;
}

string Umhv�rvi�::v�sAllarM�tst��urnarVi�Navni()
{
	string allarM�tst��urnar = "";

	for (list<shared_ptr<M�tst��aDetail>>::iterator it = m�tst��ur.begin(); it != m�tst��ur.end();)
	{
		allarM�tst��urnar = allarM�tst��urnar + it->get()->getM�tst��aNavn();

		it++;

		if (it != m�tst��ur.end())
			allarM�tst��urnar = allarM�tst��urnar + ", ";
	}

	return allarM�tst��urnar;
}

shared_ptr<H�ttanDetail> Umhv�rvi�::skapaH�ttan()
{
	return shared_ptr<H�ttanDetail>(nullptr);
}
