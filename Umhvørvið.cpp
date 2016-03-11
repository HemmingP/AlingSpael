#include "Umhvørvið.h"

Umhvørvið::Umhvørvið()
{
}

Umhvørvið::~Umhvørvið()
{
}

bool Umhvørvið::addaHóttanSumKannKoma(shared_ptr<HóttanDetail> h) // Hetta setur í tjansin at ein hóttan kann koma
{
	for (list<shared_ptr<HóttanDetail>>::iterator it = hóttanir.begin(); it != hóttanir.end(); it++)
	{
		if (*it == h)
		{
			return false;
		}
	}
	hóttanir.push_back(h);
	return true;
}

bool Umhvørvið::fjernaHóttanSumKannKoma(shared_ptr<HóttanDetail> h)
{
	for (list<shared_ptr<HóttanDetail>>::iterator it = hóttanir.begin(); it != hóttanir.end(); it++)
	{
		if (*it == h)
		{
			hóttanir.erase(it);
			return true;
		}
	}
	return false;
}

string Umhvørvið::vísAllarHóttanirViðNavni()
{
	string allarHóttanir = "";

	for (list<shared_ptr<HóttanDetail>>::iterator it = hóttanir.begin(); it != hóttanir.end();)
	{
		allarHóttanir = allarHóttanir + it->get()->getNavn();

		it++;

		if (it != hóttanir.end())
			allarHóttanir = allarHóttanir + ", ";
	}

	return allarHóttanir;
}

bool Umhvørvið::addaMótstøðaSumKannKoma(shared_ptr<MótstøðaDetail> m)
{
	for (list<shared_ptr<MótstøðaDetail>>::iterator it = mótstøður.begin(); it != mótstøður.end(); it++)
	{
		if (*it == m)
		{
			return false;
		}
	}
	mótstøður.push_back(m);
	return true;
}

bool Umhvørvið::fjernaMótstøðaSumKannKoma(shared_ptr<MótstøðaDetail> m)
{
	for (list<shared_ptr<MótstøðaDetail>>::iterator it = mótstøður.begin(); it != mótstøður.end(); it++)
	{
		if (*it == m)
		{
			mótstøður.erase(it);
			return true;
		}
	}
	return false;
}

string Umhvørvið::vísAllarMótstøðurnarViðNavni()
{
	string allarMótstøðurnar = "";

	for (list<shared_ptr<MótstøðaDetail>>::iterator it = mótstøður.begin(); it != mótstøður.end();)
	{
		allarMótstøðurnar = allarMótstøðurnar + it->get()->getMótstøðaNavn();

		it++;

		if (it != mótstøður.end())
			allarMótstøðurnar = allarMótstøðurnar + ", ";
	}

	return allarMótstøðurnar;
}

shared_ptr<HóttanDetail> Umhvørvið::skapaHóttan()
{
	return shared_ptr<HóttanDetail>(nullptr);
}
