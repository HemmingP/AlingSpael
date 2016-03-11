#pragma once

#include <string>
using std::string;

class EykaHóttan // y = 1-(e^(-k*x)) til at finna hvussu stórur tjansurin er, at hóttanin kemur, um hendan hóttan er aktiv.
{
public:
	EykaHóttan(string pHóttanin, double pMongd, double pDeviation, double pTjansurinAtHóttaninKemurPrHóttan);
	~EykaHóttan();

	string getHóttanin();
	double getTjansurinAtHóttaninKemurPrHóttan();
	double getK();

private:
	string hóttanin;
	double mongd;
	double deviation;
	double tjansurinAtHóttaninKemurPrHóttan;
	double k;
};