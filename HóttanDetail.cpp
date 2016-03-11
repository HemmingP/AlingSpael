#include "H�ttanDetail.h"

H�ttanDetail::H�ttanDetail()
{
	navn = "";
	typaAvH�ttan = "";
	tjansur = 0;
	tjansurDeviation = 0;
	maxMongd = 0;
	vaksa = 0;
	vaksaDeviation = 0;
	strongdK = 0;
	strongdKDeviation = 0;
	drepur = 0;
	drepurDeviation = 0;
	eykaH�ttan = list<EykaH�ttan>();
}

H�ttanDetail::H�ttanDetail(string pNavn, string pTypaAvH�ttan,double pTjansur, double pTjansurDeviation, double pMaxMongd, double pVaksa, double pVaksaDeviation, double pStressK, double pStressKDeviation, double pDrepur, double pDrepurDeviation, list<EykaH�ttan> pH�ttanAfturat)
{
	navn = pNavn;
	typaAvH�ttan = pTypaAvH�ttan;
	tjansur = pTjansur;
	tjansurDeviation = pTjansurDeviation;
	maxMongd = pMaxMongd;
	vaksa = pVaksa;
	vaksaDeviation = pVaksaDeviation;
	strongdK = pStressK;
	strongdKDeviation = pStressKDeviation;
	drepur = pDrepur;
	drepurDeviation = pDrepurDeviation;
	eykaH�ttan = pH�ttanAfturat;
}

H�ttanDetail::~H�ttanDetail()
{
}

bool H�ttanDetail::operator== (H�ttanDetail h)
{
	return navn == h.getNavn();
}

H�ttanDetail& H�ttanDetail::operator=(string s)
{
	try
	{
		// navn,typa,tjansur,tjansurDeviation,vaksa,vaksaDeviation,stressK,stressKDeviation,drepur,drepurDeviation,[�virkar a�rar h�ttanir;mongd;deviation;tjansurPrH�ttan],[],[]...
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

		list<EykaH�ttan> pEykaH�ttan;

		while (getline(iss,temp,'['))
		{
			// [�virkar a�rar h�ttanir;mongd;deviation;tjansurPrH�ttan]
			string pEyH�ttan;
			double pEykaMongd, pEykaDeviation, pEykaTjansurPrH�ttan;

			getline(iss, pEyH�ttan, ';');

			getline(iss, temp, ';');
			pEykaMongd = std::stod(temp);

			getline(iss, temp, ';');
			pEykaDeviation = std::stod(temp);

			getline(iss, temp, ';');
			pEykaTjansurPrH�ttan = std::stod(temp);

			pEykaH�ttan.push_back(EykaH�ttan(pEyH�ttan,pEykaMongd,pEykaDeviation,pEykaTjansurPrH�ttan));

			getline(iss,temp,']');
			if (iss.eof())
				break;
		}

		*this = H�ttanDetail(pNavn, pTypa, pTjansur, pTjansurDeviation, pMaxMongd, pVaksa, pVaksaDeviation, pStressK, pStressKDeviation, pDrepur, pDrepurDeviation, pEykaH�ttan);
		return *this;

	} catch(std::exception e)
	{
		std::cerr << "Error: \"" << e.what() << "\" occured.\n";
		return H�ttanDetail();
	}

}

std::ostream& operator<<(std::ostream& os, H�ttanDetail& obj)
{
	os << "Navn: " << obj.getNavn() << " Sum er: " << obj.getTypaAvH�ttan() << "\n";
	os << "Tjansurin: " << obj.getTjansur() << "\n";
	os << "V�kstur: " << obj.getVaksa() << " Deviation: " << obj.getVaksaDeviation() << "\n";
	os << "Stress�virkan: " << obj.getStressK() << " Deviation: " << obj.getStressDeviation() << "\n";
	os << "Drepur: " << obj.getDrepur() << " Deviation: " << obj.getDrepurDeviation() << "\n";

	return os;
}

