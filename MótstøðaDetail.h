#pragma once

#include "MótstøğaÁvirkan.h"
#include "HóttanDetail.h"

#include <string>
#include <list>
#include <iterator>
#include <vector>
#include <random>
#include <cmath>
#include <string>
#include <memory>

using std::string;
using std::list;
using std::vector;
using std::shared_ptr;

class MótstøğaDetail
{
public:
	MótstøğaDetail(string pMótstandur, int pLivitíğ, double pKostnağur,	double pPengabrúkPrDag,	string pDetail, list<MótstøğaÁvirkan> pÁvirkanir);
	MótstøğaDetail();
	~MótstøğaDetail();

	string getMótstøğaNavn() { return mótstøğaNavn; }
	int getLivitíğ() { return livitíğ; }
	double getKostnağur() { return kostnağur; }
	double getPengabrúkPrDag() { return pengabrúkPrDag; }
	string getDetail() { return detail; }
	list<MótstøğaÁvirkan> getÁvirkanir() { return ávirkanir; }

	MótstøğaDetail& operator=(string s);

private:
	string mótstøğaNavn;
	int livitíğ;
	double kostnağur;
	double pengabrúkPrDag;
	string detail;

	list<MótstøğaÁvirkan> ávirkanir;
	//shared_ptr<HóttanDetail> hóttanir; // Ikki so umráandi at implementera enn.
};