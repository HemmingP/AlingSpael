#include "Mótstøða.h"

Mótstøða::Mótstøða()
{
	umMótstøða = shared_ptr<MótstøðaDetail>(nullptr);
	dagurKeypt = -1;
}

Mótstøða::Mótstøða(shared_ptr<MótstøðaDetail> pUmMótstøða, int pDagurKeypt)
{
	umMótstøða = pUmMótstøða;
	dagurKeypt = pDagurKeypt;
}

Mótstøða::~Mótstøða()
{
}

bool Mótstøða::gingiðÚt(int dagur)
{
	if (dagur - dagurKeypt > umMótstøða->getLivitíð())
		return true;
	else
		return false;
}

int Mótstøða::livitíðEftir(int dagur)
{
	return umMótstøða->getLivitíð() - (dagur - dagurKeypt);
}

shared_ptr<MótstøðaDetail> Mótstøða::getMótstøðaDetail()
{
	return umMótstøða;
}