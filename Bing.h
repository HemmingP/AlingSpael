#pragma once
#include "FóðurTypa.h"
#include <memory>
using std::shared_ptr;

class Bing
{
public:
	Bing(fTypa f, double pMaxSiloVekt);
	~Bing();

	double getMaxSiloVekt() { return maxSiloVekt; }
	double getÍSilo() { return íSiloVekt; }
	double getRúmmetrar() { return rúmmetrar; }
	shared_ptr<FóðurTypa> getFóðurTypa() { return ft; }

	double addaÍSilo(double mongd); // RETURN: hvussu nógv mongd verður adda
	double takaÚrSilo(double mongd); // RETURN: hvussu nógv mongd verður tikið úr
	bool erTóm();

private:
	shared_ptr<FóðurTypa> ft;
	double maxSiloVekt;
	double íSiloVekt;
	double rúmmetrar;
};

std::ostream& operator<<(std::ostream& os, Bing& obj);