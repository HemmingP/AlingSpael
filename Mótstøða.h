#pragma once
#include "M�tst��aDetail.h"
//#include "H�ttan.h"
#include "HDj�r.h"
#include "HSn�kur.h"
#include "HSj�ka.h"
#include "HN�tt�ra.h"

#include <memory>
using std::unique_ptr;
using std::shared_ptr;

class M�tst��a
{
public:
	M�tst��a();
	M�tst��a(shared_ptr<M�tst��aDetail> pUmM�tst��a, int pDagurKeypt);
	~M�tst��a();

	bool gingi��t(int dagur);
	int livit��Eftir(int dagur);
	shared_ptr<M�tst��aDetail> getM�tst��aDetail();

private:
	shared_ptr<M�tst��aDetail> umM�tst��a;
	int dagurKeypt;



};