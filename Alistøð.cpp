#include "Alistøð.h"
#include "Aliring.h"
#include <sstream>
#include <fstream>
using std::string;
using std::ifstream;

Alistøð::Alistøð()
{
	// Lesur SFR inn.
	{
	ifstream is("SFR.txt",std::ios::in); // Skal taka sfr tabelluna
	string a = ""; // Inniheldur eina linju av texti á gangin.
	
	if(is.is_open())
		for (int i = 0; !is.eof(); i++) // Hevur typir
		{
			if (i >= fiskaStøddir) break;

			std::getline(is,a);
			std::istringstream iss(a);

			for (int j = 0; !iss.eof(); j++) // Hevur mánaðir
			{
				if(j < 12)
				{
				iss >> sfr[j][i];
				}
				else break;
			}
		}
	is.close();
	}
}

Alistøð::~Alistøð()
{

}

double Alistøð::automatiskFóðring(int mánaður, double fiskaStødd, double biomassi)
{
	return fiskurEtur(mánaður,fiskaStødd,biomassi,getSfr()); // fiskurEtur er inni á "EykaFormular.h"
}

double Alistøð::manuelFóðring(double fóðurMongd)
{
	return fóðurMongd;
}

void Alistøð::keypaSilo(fTypa f, double maxVekt)
{
	fóðurGoymsla.push_back(Bing(f,maxVekt));
}

double Alistøð::keypaFóðurInn(double mongdSkalKeypa, fTypa typa)
{
	for (list<Bing>::iterator it = fóðurGoymsla.begin(); it != fóðurGoymsla.end(); it++)
	{
		if (typa == it->getFóðurTypa()->getTypa())
		{
			mongdSkalKeypa = mongdSkalKeypa - it->addaÍSilo(mongdSkalKeypa);
			if (mongdSkalKeypa <= 0.0001)
				return 0;
		}
	}
	return mongdSkalKeypa;
}

double Alistøð::gevaFóður(double mongdSkalHava, double fiskaVekt)
{
	double mongdFær = 0;

	for (list<Bing>::iterator it = fóðurGoymsla.begin(); it != fóðurGoymsla.end(); it++)
	{
		if (fiskaVekt >= it->getFóðurTypa()->getMinStøddKg() &&
			fiskaVekt <= it->getFóðurTypa()->getMaxStøddKg())
		{
			mongdFær = it->takaÚrSilo(mongdSkalHava - mongdFær);
		}
		if (mongdSkalHava - mongdFær <= 0.0001)
			break;
	}

	return mongdFær;
}

int Alistøð::bingLength()
{
	return fóðurGoymsla.size();
}

list<Bing>& Alistøð::getFóðurGoymsla()
{
	return fóðurGoymsla;
}

double** Alistøð::getSfr()
{
	double** array2D = 0;
	int mðr = 12;
	array2D = new double*[mðr];

	for (int h = 0; h < mðr; h++)
	{
		array2D[h] = new double[fiskaStøddir];

		for (int w = 0; w < fiskaStøddir; w++)
		{
			// fill in some initial values
			// (filling in zeros would be more logic, but this is just for the example)
			array2D[h][w] = sfr[h][w];
		}
	}

	return array2D;
}