#pragma once
#include "Fiskur.h"
#include "EykaFunktiónir.h"
#include "AliringÁvirkan.h"
#include "Alistøð.h"
#include "Umhvørvið.h"

#include <vector>
#include <list>
#include <memory>
#include <iterator>
#include <algorithm>
using std::vector;
using std::list;
using std::unique_ptr;
using std::shared_ptr;

class Aliring
{
public:
	Aliring();
	Aliring(string pNavn, double pBiomassi, int pFiskamongd, std::shared_ptr<FiskaLívfrøði> fiskL, int pDagurSkapt=0);
	~Aliring();

//	void fiskaVøkstur(int mðr, double** sfr, int dagur=0); // Tilkalla hetta, tá ið fiskurin skal vaksa
	void fiskaVøkstur(int mðr, Alistøð &alistøð, int dagur = 0); // Tilkalla hetta, tá ið fiskurin skal vaksa

	string getNavn();
	Fiskur getFiskur();
	bool getAutomatiskFóðring();
	double getFóðurPrDag();
	double getFóðurGiviðSeinast();
	double getFóðurTilSpillisSeinast();
	double getAliCubic();
	double getIltInnihald();
	
	AliringÁvirkan& getAliringÁvirkanir();

	void setAutomatisktFóður(bool pAutomatiskFóður);
	void setFóðurPrDag(double pFóðurPrDag);
	void allarHóttanirKoma(Umhvørvið& u);

	int risikeraHóttan(shared_ptr<HóttanDetail> hd, int mðr); // Hetta setur hóttanin upp á spæl, sum er í aliringinum // RETURN mongd av hóttan sum er komið.
	void risikeraAllarHóttanir(int mðr);
	void addaStrongd(double s);

private:
	string navn;
	Fiskur fiskur;
	bool automatiskFóðring;
	double fóðurPrDag; // Hvat programmi vil geva fiskinum
	double fóðurGiviðSeinast; // Mongdin fiskur fær pga begrensningar..
	double fóðurTilSpillisSeinast; // Mongdin av fóður sum fór til spillis
	double aliCubic;
	double iltInnihald;

	int dagurSkapt;
	

	bool coparNet;

	AliringÁvirkan ávirkanir;
};