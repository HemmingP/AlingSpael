#pragma once
#include "Fiskur.h"
#include "EykaFunkti�nir.h"
#include "Aliring�virkan.h"
#include "Alist��.h"
#include "Umhv�rvi�.h"

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
	Aliring(string pNavn, double pBiomassi, int pFiskamongd, std::shared_ptr<FiskaL�vfr��i> fiskL, int pDagurSkapt=0);
	~Aliring();

//	void fiskaV�kstur(int m�r, double** sfr, int dagur=0); // Tilkalla hetta, t� i� fiskurin skal vaksa
	void fiskaV�kstur(int m�r, Alist�� &alist��, int dagur = 0); // Tilkalla hetta, t� i� fiskurin skal vaksa

	string getNavn();
	Fiskur getFiskur();
	bool getAutomatiskF��ring();
	double getF��urPrDag();
	double getF��urGivi�Seinast();
	double getF��urTilSpillisSeinast();
	double getAliCubic();
	double getIltInnihald();
	
	Aliring�virkan& getAliring�virkanir();

	void setAutomatisktF��ur(bool pAutomatiskF��ur);
	void setF��urPrDag(double pF��urPrDag);
	void allarH�ttanirKoma(Umhv�rvi�& u);

	int risikeraH�ttan(shared_ptr<H�ttanDetail> hd, int m�r); // Hetta setur h�ttanin upp � sp�l, sum er � aliringinum // RETURN mongd av h�ttan sum er komi�.
	void risikeraAllarH�ttanir(int m�r);
	void addaStrongd(double s);

private:
	string navn;
	Fiskur fiskur;
	bool automatiskF��ring;
	double f��urPrDag; // Hvat programmi vil geva fiskinum
	double f��urGivi�Seinast; // Mongdin fiskur f�r pga begrensningar..
	double f��urTilSpillisSeinast; // Mongdin av f��ur sum f�r til spillis
	double aliCubic;
	double iltInnihald;

	int dagurSkapt;
	

	bool coparNet;

	Aliring�virkan �virkanir;
};