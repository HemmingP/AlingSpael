#include "FóðurTypa.h"

FóðurTypa::FóðurTypa(fTypa f)
{
	typa = f;

	switch (f) {
	case mm3:
		minStøddKg = 0.040; //kg
		maxStøddKg = 0.150; //kg
		break;
	case mm4:
		minStøddKg = 0.150; //kg
		maxStøddKg = 0.300; //kg
		break;
	case mm6:
		minStøddKg = 0.300; //kg
		maxStøddKg = 0.800; //kg
		break;
	case mm9:
		minStøddKg = 0.800; //kg
		maxStøddKg = 2.500; //kg
		break;
	case mm12:
		minStøddKg = 2.500; //kg
		maxStøddKg = 10.000; //kg
		break;
	default:
		minStøddKg = 0.000; //kg
		maxStøddKg = 0.000; //kg
		break;
	}
}

FóðurTypa::~FóðurTypa()
{
}

string FóðurTypa::getTypaNavn() {
	switch (typa)
	{
	case mm3:
		return "3 mm";
		break;
	case mm4:
		return "4 mm";
		break;
	case mm6:
		return "6 mm";
		break;
	case mm9:
		return "9 mm";
		break;
	case mm12:
		return "12 mm";
		break;
	default:
		return "Unspecified";
		break;
	}
}

fTypa FóðurTypa::getTypa()
{
	return typa;
}

std::ostream& operator<<(std::ostream& os, FóðurTypa ft)
{
	os << ft.getTypa();
	return os;
}