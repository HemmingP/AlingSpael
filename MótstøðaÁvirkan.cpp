#include "M�tst��a�virkan.h"

M�tst��a�virkan::M�tst��a�virkan(string pHv�rH�ttan, string pHvat�H�ttanini,M�tst��uH�ttur pH�tturin, double pMongd�virkan)
{
	hv�rH�ttan = pHv�rH�ttan;
	hvat�H�ttanini = pHvat�H�ttanini;
	h�tturin = pH�tturin;
	mongd�virkan = pMongd�virkan;
}

M�tst��a�virkan::M�tst��a�virkan(string pHv�rH�ttan, string pHvat�H�ttanini, string pH�tturin, double pMongd�virkan)
{
	hv�rH�ttan = pHv�rH�ttan;
	hvat�H�ttanini = pHvat�H�ttanini;

	// pH�tturin M� vera millum: MONGD, PROSENT, ERROR
	if (pH�tturin == "MONGD")
		h�tturin = MONGD;
	else
		if (pH�tturin == "PROSENT")
			h�tturin = PROSENT;
		else
			h�tturin = ERROR;

	mongd�virkan = pMongd�virkan;
}

M�tst��a�virkan::~M�tst��a�virkan()
{
}