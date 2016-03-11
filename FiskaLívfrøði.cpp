#include "FiskaLívfrøði.h"
#include <iostream>
using namespace std;

FiskaLívfrøði::FiskaLívfrøði()
{
	fiskaSlag = "Laks";
	exponentiellurVøksturin = 0.00699; // 0.00699
	logistiskiVøksturin = 0.015; // 0.015
	logisticSlærInn = 259; // Skal vera 259
	logisticMiðpunkt = 315; // Tað verður funnið, tá ið logistiska verður sligið inn.
	prosentAvFiskastøddTáIðLogisticSlærInn = 27; // var 27 // 38 riggar væl, tá ið 0.025 er hallið
}

FiskaLívfrøði::~FiskaLívfrøði()
{
}

double FiskaLívfrøði::vøksturinPrDag(double fóðurGivið, double fóðurVilHava, double biomassi, double &maxKilo, int dagur, double stress, double maxStress)
{
	int logisticDagar = dagur - logisticSlærInn;
	double stressSeturToppunkt = stressProsent(stress, maxStress)*(-0.04625) + 3.35; // Stressið setur toppunktið á linjuni
	double stressMun = stressFóðurÁvirkan(stress, maxStress);
	double fóðurOrkarAtEta = fóðurVilHava*stressMun;
	
	double y = stressSeturToppunkt;

	double prosentGivið = fóðurGivið * 100 / fóðurOrkarAtEta; // x

	if (fóðurOrkarAtEta > 0) // Um fiskurin yvirhøvur hevur hug at eta...
	{
	if (fóðurGivið > fóðurOrkarAtEta)
		fóðurGivið = fóðurOrkarAtEta;

	//----- Undirfóðring roknast her
	double fóðringHall = (stressSeturToppunkt - (-1.275))/(100-0); // (y2-y1)/(x2-x1) // a
	
	// y = 0.04625x - 1.275; MAX er: 3.35;
	if (prosentGivið < 100)
		y = fóðringHall * prosentGivið - 1.275;
	}

	// Skal vera: if(dagur < 315)
	if(dagur <= logisticSlærInn) // Logistic slær inn, tá ið fiskur byrjar at minka um at blíva við, at vaksa
	{
		if (logisticDagar >= 0)
		{
			maxKilo = biomassi*100/prosentAvFiskastøddTáIðLogisticSlærInn; // Max skal fáa virði, tá ið logistic slær inn..
			// Finna x0...
			// x0=x-(ln(1/((L/y)-1))/k)
			logisticMiðpunkt = dagur - (log(1 / ((maxKilo / biomassi) - 1)) / logistiskiVøksturin);
		}

		return (exponentiellurVøksturin * (y / 3.35)) + 1;	// Hetta tekur hædd uppá undirfóðring og stress
	}
	else //--------------------------------------- Aftaná hetta, slær logaritmiska funktiónin inn...
	{ // Tá ið fiskurin er gamal, er hann ikki í fullum vøkstri meira
		double nú = maxKilo / (1 + exp(-logistiskiVøksturin*(logisticDagar - (logisticMiðpunkt - logisticSlærInn)))); // y=L/1+e^(-k*(x-x0))

		double hall = ((nú - biomassi) / biomassi);
			
		if(prosentGivið < 100)
			maxKilo = maxKilo - (nú - biomassi)*(1 - (y / 3.35)); // Undirfóðring ávirkar, at fiskur veksur minni í alt...

		if(stress > 0.0001)
			maxKilo = maxKilo - (nú - biomassi)*(1 - stressMun); // Stress ávirkar, at fiskur veksur minni í alt...

		return (hall * (y/3.35)) + 1; // stress og undirfóðring skal ávirka vøkstur

		// y = L / (1+e^(-k*(u-u0))); L: toppunkt; k: boyggilsi; u: tíðin; u0: midpunkt
	}
}

double FiskaLívfrøði::fiskafóðurVilHavaPrDag(int mðr, double stødd, double vekt, double** sfr)
{
	double fóðurVilHava = fiskurEtur(mðr,stødd,vekt,sfr); // fiskurEtur() er inni á "EykaFormular.h"

	//fóðurVilHava = fóðurVilHava - fóðurVilHava * (stress / maxStress);

	std::random_device rd;
	std::mt19937 gen(rd());

	std::normal_distribution<> d(fóðurVilHava,fóðurVilHava*20/100); /// Sett tað fyribils á eitt deviation uppá 20%
	return d(gen);

	//return fóðurVilHava; //* stressSkalÁvirka(stress,maxStress);
}

double FiskaLívfrøði::stressProsent(double stress, double maxStress) // Eitt tal sum sigur hvussu nógv fiska vøkstur broytist av fóður, sum fiskur ikki át.
{
	if (stress >= maxStress)
		stress = maxStress - 0.0001;

	return stress * 100 / maxStress;
}

double FiskaLívfrøði::stressFóðurÁvirkan(double stress, double maxStress) // Eitt tal sum sigur hvussu nógv fiska vøkstur broytist av fóður, sum fiskur ikki át.
{
	double prosentStress = stressProsent(stress,maxStress);

	// y = 0.04625x - 1.275; MAX er: 3.35;
	// Men meira stress, jú minni vil fiskurin eta
	// y = -0.04625x + 3.35; MAX er: -1.275;
	// y = -0.04625x; MAX er: -1.275;
	double y = -0.04625*prosentStress + 3.35;

	return y/3.35;
}