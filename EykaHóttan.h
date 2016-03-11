#pragma once

#include <string>
using std::string;

class EykaH�ttan // y = 1-(e^(-k*x)) til at finna hvussu st�rur tjansurin er, at h�ttanin kemur, um hendan h�ttan er aktiv.
{
public:
	EykaH�ttan(string pH�ttanin, double pMongd, double pDeviation, double pTjansurinAtH�ttaninKemurPrH�ttan);
	~EykaH�ttan();

	string getH�ttanin();
	double getTjansurinAtH�ttaninKemurPrH�ttan();
	double getK();

private:
	string h�ttanin;
	double mongd;
	double deviation;
	double tjansurinAtH�ttaninKemurPrH�ttan;
	double k;
};