#pragma once
#include "MótstøðaDetail.h"
//#include "Hóttan.h"
#include "HDjór.h"
#include "HSníkur.h"
#include "HSjúka.h"
#include "HNáttúra.h"

#include <memory>
using std::unique_ptr;
using std::shared_ptr;

class Mótstøða
{
public:
	Mótstøða();
	Mótstøða(shared_ptr<MótstøðaDetail> pUmMótstøða, int pDagurKeypt);
	~Mótstøða();

	bool gingiðÚt(int dagur);
	int livitíðEftir(int dagur);
	shared_ptr<MótstøðaDetail> getMótstøðaDetail();

private:
	shared_ptr<MótstøðaDetail> umMótstøða;
	int dagurKeypt;



};