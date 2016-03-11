#include "FiskaL�vfr��i.h"
#include <iostream>
using namespace std;

FiskaL�vfr��i::FiskaL�vfr��i()
{
	fiskaSlag = "Laks";
	exponentiellurV�ksturin = 0.00699; // 0.00699
	logistiskiV�ksturin = 0.015; // 0.015
	logisticSl�rInn = 259; // Skal vera 259
	logisticMi�punkt = 315; // Ta� ver�ur funni�, t� i� logistiska ver�ur sligi� inn.
	prosentAvFiskast�ddT�I�LogisticSl�rInn = 27; // var 27 // 38 riggar v�l, t� i� 0.025 er halli�
}

FiskaL�vfr��i::~FiskaL�vfr��i()
{
}

double FiskaL�vfr��i::v�ksturinPrDag(double f��urGivi�, double f��urVilHava, double biomassi, double &maxKilo, int dagur, double stress, double maxStress)
{
	int logisticDagar = dagur - logisticSl�rInn;
	double stressSeturToppunkt = stressProsent(stress, maxStress)*(-0.04625) + 3.35; // Stressi� setur toppunkti� � linjuni
	double stressMun = stressF��ur�virkan(stress, maxStress);
	double f��urOrkarAtEta = f��urVilHava*stressMun;
	
	double y = stressSeturToppunkt;

	double prosentGivi� = f��urGivi� * 100 / f��urOrkarAtEta; // x

	if (f��urOrkarAtEta > 0) // Um fiskurin yvirh�vur hevur hug at eta...
	{
	if (f��urGivi� > f��urOrkarAtEta)
		f��urGivi� = f��urOrkarAtEta;

	//----- Undirf��ring roknast her
	double f��ringHall = (stressSeturToppunkt - (-1.275))/(100-0); // (y2-y1)/(x2-x1) // a
	
	// y = 0.04625x - 1.275; MAX er: 3.35;
	if (prosentGivi� < 100)
		y = f��ringHall * prosentGivi� - 1.275;
	}

	// Skal vera: if(dagur < 315)
	if(dagur <= logisticSl�rInn) // Logistic sl�r inn, t� i� fiskur byrjar at minka um at bl�va vi�, at vaksa
	{
		if (logisticDagar >= 0)
		{
			maxKilo = biomassi*100/prosentAvFiskast�ddT�I�LogisticSl�rInn; // Max skal f�a vir�i, t� i� logistic sl�r inn..
			// Finna x0...
			// x0=x-(ln(1/((L/y)-1))/k)
			logisticMi�punkt = dagur - (log(1 / ((maxKilo / biomassi) - 1)) / logistiskiV�ksturin);
		}

		return (exponentiellurV�ksturin * (y / 3.35)) + 1;	// Hetta tekur h�dd upp� undirf��ring og stress
	}
	else //--------------------------------------- Aftan� hetta, sl�r logaritmiska funkti�nin inn...
	{ // T� i� fiskurin er gamal, er hann ikki � fullum v�kstri meira
		double n� = maxKilo / (1 + exp(-logistiskiV�ksturin*(logisticDagar - (logisticMi�punkt - logisticSl�rInn)))); // y=L/1+e^(-k*(x-x0))

		double hall = ((n� - biomassi) / biomassi);
			
		if(prosentGivi� < 100)
			maxKilo = maxKilo - (n� - biomassi)*(1 - (y / 3.35)); // Undirf��ring �virkar, at fiskur veksur minni � alt...

		if(stress > 0.0001)
			maxKilo = maxKilo - (n� - biomassi)*(1 - stressMun); // Stress �virkar, at fiskur veksur minni � alt...

		return (hall * (y/3.35)) + 1; // stress og undirf��ring skal �virka v�kstur

		// y = L / (1+e^(-k*(u-u0))); L: toppunkt; k: boyggilsi; u: t��in; u0: midpunkt
	}
}

double FiskaL�vfr��i::fiskaf��urVilHavaPrDag(int m�r, double st�dd, double vekt, double** sfr)
{
	double f��urVilHava = fiskurEtur(m�r,st�dd,vekt,sfr); // fiskurEtur() er inni � "EykaFormular.h"

	//f��urVilHava = f��urVilHava - f��urVilHava * (stress / maxStress);

	std::random_device rd;
	std::mt19937 gen(rd());

	std::normal_distribution<> d(f��urVilHava,f��urVilHava*20/100); /// Sett ta� fyribils � eitt deviation upp� 20%
	return d(gen);

	//return f��urVilHava; //* stressSkal�virka(stress,maxStress);
}

double FiskaL�vfr��i::stressProsent(double stress, double maxStress) // Eitt tal sum sigur hvussu n�gv fiska v�kstur broytist av f��ur, sum fiskur ikki �t.
{
	if (stress >= maxStress)
		stress = maxStress - 0.0001;

	return stress * 100 / maxStress;
}

double FiskaL�vfr��i::stressF��ur�virkan(double stress, double maxStress) // Eitt tal sum sigur hvussu n�gv fiska v�kstur broytist av f��ur, sum fiskur ikki �t.
{
	double prosentStress = stressProsent(stress,maxStress);

	// y = 0.04625x - 1.275; MAX er: 3.35;
	// Men meira stress, j� minni vil fiskurin eta
	// y = -0.04625x + 3.35; MAX er: -1.275;
	// y = -0.04625x; MAX er: -1.275;
	double y = -0.04625*prosentStress + 3.35;

	return y/3.35;
}