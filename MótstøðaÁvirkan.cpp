#include "MótstøğaÁvirkan.h"

MótstøğaÁvirkan::MótstøğaÁvirkan(string pHvørHóttan, string pHvatÍHóttanini,MótstøğuHáttur pHátturin, double pMongdÁvirkan)
{
	hvørHóttan = pHvørHóttan;
	hvatÍHóttanini = pHvatÍHóttanini;
	hátturin = pHátturin;
	mongdÁvirkan = pMongdÁvirkan;
}

MótstøğaÁvirkan::MótstøğaÁvirkan(string pHvørHóttan, string pHvatÍHóttanini, string pHátturin, double pMongdÁvirkan)
{
	hvørHóttan = pHvørHóttan;
	hvatÍHóttanini = pHvatÍHóttanini;

	// pHátturin Má vera millum: MONGD, PROSENT, ERROR
	if (pHátturin == "MONGD")
		hátturin = MONGD;
	else
		if (pHátturin == "PROSENT")
			hátturin = PROSENT;
		else
			hátturin = ERROR;

	mongdÁvirkan = pMongdÁvirkan;
}

MótstøğaÁvirkan::~MótstøğaÁvirkan()
{
}