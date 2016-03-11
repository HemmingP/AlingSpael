#include "EykaH�ttan.h"

EykaH�ttan::EykaH�ttan(string pH�ttanin, double pMongd, double pDeviation, double pTjansurinAtH�ttaninKemurPrH�ttan) : h�ttanin(pH�ttanin), mongd(pMongd), deviation(pDeviation),tjansurinAtH�ttaninKemurPrH�ttan(pTjansurinAtH�ttaninKemurPrH�ttan)
{
	//k = ln(1/(y-1))/x
	k = log(-1 / (tjansurinAtH�ttaninKemurPrH�ttan - 1));
}

EykaH�ttan::~EykaH�ttan()
{
}

string EykaH�ttan::getH�ttanin()
{
	return h�ttanin;
}

double EykaH�ttan::getTjansurinAtH�ttaninKemurPrH�ttan()
{
	return tjansurinAtH�ttaninKemurPrH�ttan;
}

double EykaH�ttan::getK()
{
	return k;
}