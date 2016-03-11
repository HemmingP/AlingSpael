#pragma once
#include <string>
#include <ostream>
using std::string;

/*extern*/ enum fTypa // Fóður typa
{
	mm3, mm4, mm6, mm9, mm12, mmNULL
}; 


class FóðurTypa
{
protected:
	
public:
	FóðurTypa(fTypa f);
	~FóðurTypa();
	double getMinStøddKg() { return minStøddKg;	}
	double getMaxStøddKg() { return maxStøddKg; }
	string getTypaNavn();
	fTypa getTypa();

private:
	fTypa typa;
	double minStøddKg, maxStøddKg;
};

std::ostream& operator<<(std::ostream& os, FóðurTypa ft);