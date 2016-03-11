#pragma once
#include <string>
#include <ostream>
using std::string;

/*extern*/ enum fTypa // F��ur typa
{
	mm3, mm4, mm6, mm9, mm12, mmNULL
}; 


class F��urTypa
{
protected:
	
public:
	F��urTypa(fTypa f);
	~F��urTypa();
	double getMinSt�ddKg() { return minSt�ddKg;	}
	double getMaxSt�ddKg() { return maxSt�ddKg; }
	string getTypaNavn();
	fTypa getTypa();

private:
	fTypa typa;
	double minSt�ddKg, maxSt�ddKg;
};

std::ostream& operator<<(std::ostream& os, F��urTypa ft);