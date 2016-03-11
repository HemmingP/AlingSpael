#pragma once

#include <string>
using std::string;

enum MótstøğuHáttur
{
MONGD,PROSENT,ERROR
};

class MótstøğaÁvirkan
{
public:
	MótstøğaÁvirkan(string pHvørHóttan, string pHvatÍHóttanini, MótstøğuHáttur pHátturin, double pMongdÁvirkan);
	MótstøğaÁvirkan(string pHvørHóttan, string pHvatÍHóttanini, string pHátturin, double pMongdÁvirkan);
	~MótstøğaÁvirkan();

	string getHvørHóttan() { return hvørHóttan; }
	string getHvatÍHóttanini() { return hvatÍHóttanini; }
	MótstøğuHáttur getMótstøğuHáttur() { return hátturin; }
	double getMongdÁvirkan() { return mongdÁvirkan; }

private:

	string hvørHóttan;
	string hvatÍHóttanini;
	MótstøğuHáttur hátturin;
	double mongdÁvirkan;
};