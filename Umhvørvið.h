#pragma once
//#include "H�ttanDetail.h"
#include "HDj�r.h"
#include "HSn�kur.h"
#include "HSj�ka.h"
#include "HN�tt�ra.h"
#include "M�tst��aDetail.h"
//#include "Botnur.h"

#include <memory>
#include <algorithm>

using std::shared_ptr;

class Umhv�rvi�
{
public:
	Umhv�rvi�();
	~Umhv�rvi�();

	bool addaH�ttanSumKannKoma(shared_ptr<H�ttanDetail> h);
	bool fjernaH�ttanSumKannKoma(shared_ptr<H�ttanDetail> h);
	string v�sAllarH�ttanirVi�Navni();

	bool addaM�tst��aSumKannKoma(shared_ptr<M�tst��aDetail> m);
	bool fjernaM�tst��aSumKannKoma(shared_ptr<M�tst��aDetail> m);
	string v�sAllarM�tst��urnarVi�Navni();

	shared_ptr<H�ttanDetail> skapaH�ttan();

	//list<shared_ptr<H�ttanDetail>> getH�ttanir() { return h�ttanir; }
	list<shared_ptr<H�ttanDetail>>::iterator getBeginH�ttan() { return h�ttanir.begin(); }
	list<shared_ptr<H�ttanDetail>>::iterator getEndH�ttan() { return h�ttanir.end(); }
	
	//list<shared_ptr<M�tst��aDetail>> getM�tstand() { return m�tst��ur; }
	list<shared_ptr<M�tst��aDetail>>::iterator getBeginM�tst��a() { return m�tst��ur.begin(); }
	list<shared_ptr<M�tst��aDetail>>::iterator getEndM�tst��a() { return m�tst��ur.end(); }

private:
	list<shared_ptr<H�ttanDetail>> h�ttanir;
	list<shared_ptr<M�tst��aDetail>> m�tst��ur;
	//Botnur botnur;
};