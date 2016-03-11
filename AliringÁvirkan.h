#pragma once

//#include "H�ttan.h"
#include "HDj�r.h"
#include "HSn�kur.h"
#include "HSj�ka.h"
#include "HN�tt�ra.h"

#include "Fiskur.h"

#include "M�tst��a.h"

#include "EykaFunkti�nir.h"

#include <random>
#include <algorithm>
#include <exception>
#include <iostream>

using std::unique_ptr;

class Aliring�virkan // Heldur � H�ttanir og M�tst��urnar, sum aliringurin hevur
{
public:
	Aliring�virkan();
	~Aliring�virkan();

	void h�ttanirTakaEffect(Fiskur fisk, const int m�r, int &dey�irFiskar, double &stressFingi�);
	void h�ttanirVaksaOgMinka(Fiskur fisk, const int m�r);
	
	int h�ttanKemur(shared_ptr<H�ttanDetail> hd, int fiskamongd, double fiskaVekt, int m�r); // Finnur fram um ein h�ttan er, um ikki, so skulu vit risikera.
	bool hevurH�ttan(shared_ptr<H�ttanDetail> hd);
	int getMongdAvH�ttan(string h�ttanNavn);

	bool addaM�tst��a(shared_ptr<M�tst��aDetail> md, int dagur);
	bool takaM�tst��a�r(shared_ptr<M�tst��aDetail> md);
	void m�tst��ur�virka();
	void m�tst��urGanga�t(int dagur);

	//list<unique_ptr<H�ttan>>::iterator getFirstH�ttan() { return h�ttanir�Aliringinum.begin(); }
	//list<unique_ptr<H�ttan>>::iterator getEndH�ttan() { return h�ttanir�Aliringinum.end(); }
	//auto& getFirstM�tst��a() { return m�tst��ur�Aliringinum.begin(); }
	//auto& getEndM�tst��a() { return m�tst��ur�Aliringinum.end(); }

	list<unique_ptr<H�ttan>>& getH�ttanir�Aliringinum() { return h�ttanir�Aliringinum; }
	list<unique_ptr<M�tst��a>>& getM�tst��ur�Aliringinum() { return m�tst��ur�Aliringinum; }

private:

	list<unique_ptr<H�ttan>> h�ttanir�Aliringinum;
	list<unique_ptr<M�tst��a>> m�tst��ur�Aliringinum;
	bool m�tst��urHavaBroyttSeg;
};