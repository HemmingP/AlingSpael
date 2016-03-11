#include "EykaHóttan.h"

EykaHóttan::EykaHóttan(string pHóttanin, double pMongd, double pDeviation, double pTjansurinAtHóttaninKemurPrHóttan) : hóttanin(pHóttanin), mongd(pMongd), deviation(pDeviation),tjansurinAtHóttaninKemurPrHóttan(pTjansurinAtHóttaninKemurPrHóttan)
{
	//k = ln(1/(y-1))/x
	k = log(-1 / (tjansurinAtHóttaninKemurPrHóttan - 1));
}

EykaHóttan::~EykaHóttan()
{
}

string EykaHóttan::getHóttanin()
{
	return hóttanin;
}

double EykaHóttan::getTjansurinAtHóttaninKemurPrHóttan()
{
	return tjansurinAtHóttaninKemurPrHóttan;
}

double EykaHóttan::getK()
{
	return k;
}