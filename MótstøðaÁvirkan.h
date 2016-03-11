#pragma once

#include <string>
using std::string;

enum M�tst��uH�ttur
{
MONGD,PROSENT,ERROR
};

class M�tst��a�virkan
{
public:
	M�tst��a�virkan(string pHv�rH�ttan, string pHvat�H�ttanini, M�tst��uH�ttur pH�tturin, double pMongd�virkan);
	M�tst��a�virkan(string pHv�rH�ttan, string pHvat�H�ttanini, string pH�tturin, double pMongd�virkan);
	~M�tst��a�virkan();

	string getHv�rH�ttan() { return hv�rH�ttan; }
	string getHvat�H�ttanini() { return hvat�H�ttanini; }
	M�tst��uH�ttur getM�tst��uH�ttur() { return h�tturin; }
	double getMongd�virkan() { return mongd�virkan; }

private:

	string hv�rH�ttan;
	string hvat�H�ttanini;
	M�tst��uH�ttur h�tturin;
	double mongd�virkan;
};