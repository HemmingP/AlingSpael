#include "M�tst��a.h"

M�tst��a::M�tst��a()
{
	umM�tst��a = shared_ptr<M�tst��aDetail>(nullptr);
	dagurKeypt = -1;
}

M�tst��a::M�tst��a(shared_ptr<M�tst��aDetail> pUmM�tst��a, int pDagurKeypt)
{
	umM�tst��a = pUmM�tst��a;
	dagurKeypt = pDagurKeypt;
}

M�tst��a::~M�tst��a()
{
}

bool M�tst��a::gingi��t(int dagur)
{
	if (dagur - dagurKeypt > umM�tst��a->getLivit��())
		return true;
	else
		return false;
}

int M�tst��a::livit��Eftir(int dagur)
{
	return umM�tst��a->getLivit��() - (dagur - dagurKeypt);
}

shared_ptr<M�tst��aDetail> M�tst��a::getM�tst��aDetail()
{
	return umM�tst��a;
}