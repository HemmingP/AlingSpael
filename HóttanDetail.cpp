#include "HóttanDetail.h"

HóttanDetail::HóttanDetail()
{
	navn = "";
	typaAvHóttan = "";
	tjansur = 0;
	tjansurDeviation = 0;
	maxMongd = 0;
	vaksa = 0;
	vaksaDeviation = 0;
	strongdK = 0;
	strongdKDeviation = 0;
	drepur = 0;
	drepurDeviation = 0;
	eykaHóttan = list<EykaHóttan>();
}

HóttanDetail::HóttanDetail(string pNavn, string pTypaAvHóttan,double pTjansur, double pTjansurDeviation, double pMaxMongd, double pVaksa, double pVaksaDeviation, double pStressK, double pStressKDeviation, double pDrepur, double pDrepurDeviation, list<EykaHóttan> pHóttanAfturat)
{
	navn = pNavn;
	typaAvHóttan = pTypaAvHóttan;
	tjansur = pTjansur;
	tjansurDeviation = pTjansurDeviation;
	maxMongd = pMaxMongd;
	vaksa = pVaksa;
	vaksaDeviation = pVaksaDeviation;
	strongdK = pStressK;
	strongdKDeviation = pStressKDeviation;
	drepur = pDrepur;
	drepurDeviation = pDrepurDeviation;
	eykaHóttan = pHóttanAfturat;
}

HóttanDetail::~HóttanDetail()
{
}

bool HóttanDetail::operator== (HóttanDetail h)
{
	return navn == h.getNavn();
}

HóttanDetail& HóttanDetail::operator=(string s)
{
	try
	{
		// navn,typa,tjansur,tjansurDeviation,vaksa,vaksaDeviation,stressK,stressKDeviation,drepur,drepurDeviation,[ávirkar aðrar hóttanir;mongd;deviation;tjansurPrHóttan],[],[]...
		std::istringstream iss(s);
		string pNavn, pTypa;
		double pTjansur, pTjansurDeviation, pVaksa, pVaksaDeviation, pStressK, pStressKDeviation, pDrepur, pDrepurDeviation;
		int pMaxMongd;

		getline(iss, pNavn, ',');
		getline(iss, pTypa, ',');

		string temp;
		string::size_type sz;

		getline(iss, temp, ',');
		pTjansur = std::stod(temp);

		getline(iss, temp, ',');
		pTjansurDeviation = std::stod(temp);

		getline(iss, temp, ',');
		pMaxMongd = std::stoi(temp,&sz);

		getline(iss, temp, ',');
		pVaksa = std::stod(temp);

		getline(iss, temp, ',');
		pVaksaDeviation = std::stod(temp);

		getline(iss, temp, ',');
		pStressK = std::stod(temp);

		getline(iss, temp, ',');
		pStressKDeviation = std::stod(temp);

		getline(iss, temp, ',');
		pDrepur = std::stod(temp);

		getline(iss, temp, ',');
		pDrepurDeviation = std::stod(temp);

		list<EykaHóttan> pEykaHóttan;

		while (getline(iss,temp,'['))
		{
			// [ávirkar aðrar hóttanir;mongd;deviation;tjansurPrHóttan]
			string pEyHóttan;
			double pEykaMongd, pEykaDeviation, pEykaTjansurPrHóttan;

			getline(iss, pEyHóttan, ';');

			getline(iss, temp, ';');
			pEykaMongd = std::stod(temp);

			getline(iss, temp, ';');
			pEykaDeviation = std::stod(temp);

			getline(iss, temp, ';');
			pEykaTjansurPrHóttan = std::stod(temp);

			pEykaHóttan.push_back(EykaHóttan(pEyHóttan,pEykaMongd,pEykaDeviation,pEykaTjansurPrHóttan));

			getline(iss,temp,']');
			if (iss.eof())
				break;
		}

		*this = HóttanDetail(pNavn, pTypa, pTjansur, pTjansurDeviation, pMaxMongd, pVaksa, pVaksaDeviation, pStressK, pStressKDeviation, pDrepur, pDrepurDeviation, pEykaHóttan);
		return *this;

	} catch(std::exception e)
	{
		std::cerr << "Error: \"" << e.what() << "\" occured.\n";
		return HóttanDetail();
	}

}

std::ostream& operator<<(std::ostream& os, HóttanDetail& obj)
{
	os << "Navn: " << obj.getNavn() << " Sum er: " << obj.getTypaAvHóttan() << "\n";
	os << "Tjansurin: " << obj.getTjansur() << "\n";
	os << "Vøkstur: " << obj.getVaksa() << " Deviation: " << obj.getVaksaDeviation() << "\n";
	os << "StressÁvirkan: " << obj.getStressK() << " Deviation: " << obj.getStressDeviation() << "\n";
	os << "Drepur: " << obj.getDrepur() << " Deviation: " << obj.getDrepurDeviation() << "\n";

	return os;
}

