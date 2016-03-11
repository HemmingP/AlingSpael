#include "MótstøğaDetail.h"

MótstøğaDetail::MótstøğaDetail()
{
	mótstøğaNavn = "";
	livitíğ = 0;
	kostnağur = 0;
	pengabrúkPrDag = 0;
	detail = "";
}

MótstøğaDetail::MótstøğaDetail(string pMótstandur, int pLivitíğ, double pKostnağur, double pPengabrúkPrDag, string pDetail, list<MótstøğaÁvirkan> pÁvirkanir)
	: mótstøğaNavn(pMótstandur),livitíğ(pLivitíğ),kostnağur(pKostnağur),pengabrúkPrDag(pPengabrúkPrDag),detail(pDetail),ávirkanir(pÁvirkanir)
{
}

MótstøğaDetail::~MótstøğaDetail()
{
}

MótstøğaDetail& MótstøğaDetail::operator=(string s)
{
	try
	{
		// navn,typa,tjansur,tjansurDeviation,vaksa,vaksaDeviation,stressK,stressKDeviation,drepur,drepurDeviation,[ávirkar ağrar hóttanir;mongd;deviation;tjansurPrHóttan],[],[]...
		std::istringstream iss(s);
		string pNavn;
		int pLivitíğ;
		double pKostnağur, pPengabrúk;
		

		getline(iss, pNavn, ',');
		
		string temp;
		string::size_type sz;

		getline(iss, temp, ',');
		pLivitíğ = std::stoi(temp);

		getline(iss, temp, ',');
		pKostnağur = std::stod(temp);

		getline(iss, temp, ',');
		pPengabrúk = std::stod(temp, &sz);

		list<MótstøğaÁvirkan> pMótstøğuÁvirkanir;
		getline(iss, temp, '[');
		while (true)
		{
			//[hvørErHóttanin, hvatÍHóttanini, mongdÁvirkan, háttur]
			string hvørErHóttanin,hvatÍHóttanini;
			double mongdÁvirkan;
			string háttur;

			getline(iss, hvørErHóttanin, ',');

			getline(iss, hvatÍHóttanini, ',');

			getline(iss, temp, ',');
			mongdÁvirkan = std::stod(temp);

			getline(iss, háttur, ']');

			pMótstøğuÁvirkanir.push_back(MótstøğaÁvirkan(hvørErHóttanin,hvatÍHóttanini,háttur,mongdÁvirkan));

			char nextAction;
			iss.get(nextAction); // er '[' ella ':'

			if (nextAction == ':')
				break;
			else
				continue; // '[' bara loop víğari...
		}

		//getline(iss,temp,':');

		string pDetail;
		getline(iss,pDetail);

		*this = MótstøğaDetail(pNavn,pLivitíğ,pKostnağur,pPengabrúk,pDetail,pMótstøğuÁvirkanir);
		return *this;

	}
	catch (std::exception e)
	{
		std::cerr << "Error: \"" << e.what() << "\" occured.\n";
		return *this;
	}
}

MótstøğuHáttur mótstøğuHátturin(string s)
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