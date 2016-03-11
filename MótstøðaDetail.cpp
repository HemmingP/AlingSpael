#include "M�tst��aDetail.h"

M�tst��aDetail::M�tst��aDetail()
{
	m�tst��aNavn = "";
	livit�� = 0;
	kostna�ur = 0;
	pengabr�kPrDag = 0;
	detail = "";
}

M�tst��aDetail::M�tst��aDetail(string pM�tstandur, int pLivit��, double pKostna�ur, double pPengabr�kPrDag, string pDetail, list<M�tst��a�virkan> p�virkanir)
	: m�tst��aNavn(pM�tstandur),livit��(pLivit��),kostna�ur(pKostna�ur),pengabr�kPrDag(pPengabr�kPrDag),detail(pDetail),�virkanir(p�virkanir)
{
}

M�tst��aDetail::~M�tst��aDetail()
{
}

M�tst��aDetail& M�tst��aDetail::operator=(string s)
{
	try
	{
		// navn,typa,tjansur,tjansurDeviation,vaksa,vaksaDeviation,stressK,stressKDeviation,drepur,drepurDeviation,[�virkar a�rar h�ttanir;mongd;deviation;tjansurPrH�ttan],[],[]...
		std::istringstream iss(s);
		string pNavn;
		int pLivit��;
		double pKostna�ur, pPengabr�k;
		

		getline(iss, pNavn, ',');
		
		string temp;
		string::size_type sz;

		getline(iss, temp, ',');
		pLivit�� = std::stoi(temp);

		getline(iss, temp, ',');
		pKostna�ur = std::stod(temp);

		getline(iss, temp, ',');
		pPengabr�k = std::stod(temp, &sz);

		list<M�tst��a�virkan> pM�tst��u�virkanir;
		getline(iss, temp, '[');
		while (true)
		{
			//[hv�rErH�ttanin, hvat�H�ttanini, mongd�virkan, h�ttur]
			string hv�rErH�ttanin,hvat�H�ttanini;
			double mongd�virkan;
			string h�ttur;

			getline(iss, hv�rErH�ttanin, ',');

			getline(iss, hvat�H�ttanini, ',');

			getline(iss, temp, ',');
			mongd�virkan = std::stod(temp);

			getline(iss, h�ttur, ']');

			pM�tst��u�virkanir.push_back(M�tst��a�virkan(hv�rErH�ttanin,hvat�H�ttanini,h�ttur,mongd�virkan));

			char nextAction;
			iss.get(nextAction); // er '[' ella ':'

			if (nextAction == ':')
				break;
			else
				continue; // '[' bara loop v��ari...
		}

		//getline(iss,temp,':');

		string pDetail;
		getline(iss,pDetail);

		*this = M�tst��aDetail(pNavn,pLivit��,pKostna�ur,pPengabr�k,pDetail,pM�tst��u�virkanir);
		return *this;

	}
	catch (std::exception e)
	{
		std::cerr << "Error: \"" << e.what() << "\" occured.\n";
		return *this;
	}
}

M�tst��uH�ttur m�tst��uH�tturin(string s)
{
	if (s == "MONGD")
		return MONGD;
	else if (s == "PROSENT")
		return PROSENT;
	else
	{
		throw(s + " er ikki ein motstodu hattur.");
	}
}