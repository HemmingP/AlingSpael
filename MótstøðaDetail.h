#pragma once

#include "M�tst��a�virkan.h"
#include "H�ttanDetail.h"

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

class M�tst��aDetail
{
public:
	M�tst��aDetail(string pM�tstandur, int pLivit��, double pKostna�ur,	double pPengabr�kPrDag,	string pDetail, list<M�tst��a�virkan> p�virkanir);
	M�tst��aDetail();
	~M�tst��aDetail();

	string getM�tst��aNavn() { return m�tst��aNavn; }
	int getLivit��() { return livit��; }
	double getKostna�ur() { return kostna�ur; }
	double getPengabr�kPrDag() { return pengabr�kPrDag; }
	string getDetail() { return detail; }
	list<M�tst��a�virkan> get�virkanir() { return �virkanir; }

	M�tst��aDetail& operator=(string s);

private:
	string m�tst��aNavn;
	int livit��;
	double kostna�ur;
	double pengabr�kPrDag;
	string detail;

	list<M�tst��a�virkan> �virkanir;
	//shared_ptr<H�ttanDetail> h�ttanir; // Ikki so umr�andi at implementera enn.
};