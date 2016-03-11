#pragma once
#include "F��urTypa.h"
#include <memory>
using std::shared_ptr;

class Bing
{
public:
	Bing(fTypa f, double pMaxSiloVekt);
	~Bing();

	double getMaxSiloVekt() { return maxSiloVekt; }
	double get�Silo() { return �SiloVekt; }
	double getR�mmetrar() { return r�mmetrar; }
	shared_ptr<F��urTypa> getF��urTypa() { return ft; }

	double adda�Silo(double mongd); // RETURN: hvussu n�gv mongd ver�ur adda
	double taka�rSilo(double mongd); // RETURN: hvussu n�gv mongd ver�ur tiki� �r
	bool erT�m();

private:
	shared_ptr<F��urTypa> ft;
	double maxSiloVekt;
	double �SiloVekt;
	double r�mmetrar;
};

std::ostream& operator<<(std::ostream& os, Bing& obj);