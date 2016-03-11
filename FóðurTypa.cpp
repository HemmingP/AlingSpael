#include "F��urTypa.h"

F��urTypa::F��urTypa(fTypa f)
{
	typa = f;

	switch (f) {
	case mm3:
		minSt�ddKg = 0.040; //kg
		maxSt�ddKg = 0.150; //kg
		break;
	case mm4:
		minSt�ddKg = 0.150; //kg
		maxSt�ddKg = 0.300; //kg
		break;
	case mm6:
		minSt�ddKg = 0.300; //kg
		maxSt�ddKg = 0.800; //kg
		break;
	case mm9:
		minSt�ddKg = 0.800; //kg
		maxSt�ddKg = 2.500; //kg
		break;
	case mm12:
		minSt�ddKg = 2.500; //kg
		maxSt�ddKg = 10.000; //kg
		break;
	default:
		minSt�ddKg = 0.000; //kg
		maxSt�ddKg = 0.000; //kg
		break;
	}
}

F��urTypa::~F��urTypa()
{
}

string F��urTypa::getTypaNavn() {
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

fTypa F��urTypa::getTypa()
{
	return typa;
}

std::ostream& operator<<(std::ostream& os, F��urTypa ft)
{
	os << ft.getTypa();
	return os;
}