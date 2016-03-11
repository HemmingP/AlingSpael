#include "Alist��.h"
#include "Aliring.h"
#include <sstream>
#include <fstream>
using std::string;
using std::ifstream;

Alist��::Alist��()
{
	// Lesur SFR inn.
	{
	ifstream is("SFR.txt",std::ios::in); // Skal taka sfr tabelluna
	string a = ""; // Inniheldur eina linju av texti � gangin.
	
	if(is.is_open())
		for (int i = 0; !is.eof(); i++) // Hevur typir
		{
			if (i >= fiskaSt�ddir) break;

			std::getline(is,a);
			std::istringstream iss(a);

			for (int j = 0; !iss.eof(); j++) // Hevur m�na�ir
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

Alist��::~Alist��()
{

}

double Alist��::automatiskF��ring(int m�na�ur, double fiskaSt�dd, double biomassi)
{
	return fiskurEtur(m�na�ur,fiskaSt�dd,biomassi,getSfr()); // fiskurEtur er inni � "EykaFormular.h"
}

double Alist��::manuelF��ring(double f��urMongd)
{
	return f��urMongd;
}

void Alist��::keypaSilo(fTypa f, double maxVekt)
{
	f��urGoymsla.push_back(Bing(f,maxVekt));
}

double Alist��::keypaF��urInn(double mongdSkalKeypa, fTypa typa)
{
	for (list<Bing>::iterator it = f��urGoymsla.begin(); it != f��urGoymsla.end(); it++)
	{
		if (typa == it->getF��urTypa()->getTypa())
		{
			mongdSkalKeypa = mongdSkalKeypa - it->adda�Silo(mongdSkalKeypa);
			if (mongdSkalKeypa <= 0.0001)
				return 0;
		}
	}
	return mongdSkalKeypa;
}

double Alist��::gevaF��ur(double mongdSkalHava, double fiskaVekt)
{
	double mongdF�r = 0;

	for (list<Bing>::iterator it = f��urGoymsla.begin(); it != f��urGoymsla.end(); it++)
	{
		if (fiskaVekt >= it->getF��urTypa()->getMinSt�ddKg() &&
			fiskaVekt <= it->getF��urTypa()->getMaxSt�ddKg())
		{
			mongdF�r = it->taka�rSilo(mongdSkalHava - mongdF�r);
		}
		if (mongdSkalHava - mongdF�r <= 0.0001)
			break;
	}

	return mongdF�r;
}

int Alist��::bingLength()
{
	return f��urGoymsla.size();
}

list<Bing>& Alist��::getF��urGoymsla()
{
	return f��urGoymsla;
}

double** Alist��::getSfr()
{
	double** array2D = 0;
	int m�r = 12;
	array2D = new double*[m�r];

	for (int h = 0; h < m�r; h++)
	{
		array2D[h] = new double[fiskaSt�ddir];

		for (int w = 0; w < fiskaSt�ddir; w++)
		{
			// fill in some initial values
			// (filling in zeros would be more logic, but this is just for the example)
			array2D[h][w] = sfr[h][w];
		}
	}

	return array2D;
}