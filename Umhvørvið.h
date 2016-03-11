#pragma once
//#include "HóttanDetail.h"
#include "HDjór.h"
#include "HSníkur.h"
#include "HSjúka.h"
#include "HNáttúra.h"
#include "MótstøðaDetail.h"
//#include "Botnur.h"

#include <memory>
#include <algorithm>

using std::shared_ptr;

class Umhvørvið
{
public:
	Umhvørvið();
	~Umhvørvið();

	bool addaHóttanSumKannKoma(shared_ptr<HóttanDetail> h);
	bool fjernaHóttanSumKannKoma(shared_ptr<HóttanDetail> h);
	string vísAllarHóttanirViðNavni();

	bool addaMótstøðaSumKannKoma(shared_ptr<MótstøðaDetail> m);
	bool fjernaMótstøðaSumKannKoma(shared_ptr<MótstøðaDetail> m);
	string vísAllarMótstøðurnarViðNavni();

	shared_ptr<HóttanDetail> skapaHóttan();

	//list<shared_ptr<HóttanDetail>> getHóttanir() { return hóttanir; }
	list<shared_ptr<HóttanDetail>>::iterator getBeginHóttan() { return hóttanir.begin(); }
	list<shared_ptr<HóttanDetail>>::iterator getEndHóttan() { return hóttanir.end(); }
	
	//list<shared_ptr<MótstøðaDetail>> getMótstand() { return mótstøður; }
	list<shared_ptr<MótstøðaDetail>>::iterator getBeginMótstøða() { return mótstøður.begin(); }
	list<shared_ptr<MótstøðaDetail>>::iterator getEndMótstøða() { return mótstøður.end(); }

private:
	list<shared_ptr<HóttanDetail>> hóttanir;
	list<shared_ptr<MótstøðaDetail>> mótstøður;
	//Botnur botnur;
};