#pragma once

//#include "Hóttan.h"
#include "HDjór.h"
#include "HSníkur.h"
#include "HSjúka.h"
#include "HNáttúra.h"

#include "Fiskur.h"

#include "Mótstøğa.h"

#include "EykaFunktiónir.h"

#include <random>
#include <algorithm>
#include <exception>
#include <iostream>

using std::unique_ptr;

class AliringÁvirkan // Heldur í Hóttanir og Mótstøğurnar, sum aliringurin hevur
{
public:
	AliringÁvirkan();
	~AliringÁvirkan();

	void hóttanirTakaEffect(Fiskur fisk, const int mğr, int &deyğirFiskar, double &stressFingiğ);
	void hóttanirVaksaOgMinka(Fiskur fisk, const int mğr);
	
	int hóttanKemur(shared_ptr<HóttanDetail> hd, int fiskamongd, double fiskaVekt, int mğr); // Finnur fram um ein hóttan er, um ikki, so skulu vit risikera.
	bool hevurHóttan(shared_ptr<HóttanDetail> hd);
	int getMongdAvHóttan(string hóttanNavn);

	bool addaMótstøğa(shared_ptr<MótstøğaDetail> md, int dagur);
	bool takaMótstøğaÚr(shared_ptr<MótstøğaDetail> md);
	void mótstøğurÁvirka();
	void mótstøğurGangaÚt(int dagur);

	//list<unique_ptr<Hóttan>>::iterator getFirstHóttan() { return hóttanirÍAliringinum.begin(); }
	//list<unique_ptr<Hóttan>>::iterator getEndHóttan() { return hóttanirÍAliringinum.end(); }
	//auto& getFirstMótstøğa() { return mótstøğurÍAliringinum.begin(); }
	//auto& getEndMótstøğa() { return mótstøğurÍAliringinum.end(); }

	list<unique_ptr<Hóttan>>& getHóttanirÍAliringinum() { return hóttanirÍAliringinum; }
	list<unique_ptr<Mótstøğa>>& getMótstøğurÍAliringinum() { return mótstøğurÍAliringinum; }

private:

	list<unique_ptr<Hóttan>> hóttanirÍAliringinum;
	list<unique_ptr<Mótstøğa>> mótstøğurÍAliringinum;
	bool mótstøğurHavaBroyttSeg;
};