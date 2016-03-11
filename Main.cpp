#include "Alistøð.h"
#include "Aliring.h"
#include "Umhvørvið.h"

#include <iostream>
#include <memory>
#include <string>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <conio.h>
#include <exception>
using std::cout;
using std::endl;
using std::for_each;
using std::ifstream;

class TestFasur
{
public:
	TestFasur();
	~TestFasur();

	int testAvVøkstur();
	int hóttanTest();
	int testProgram1();
	bool velFóðurMetoda();

	fTypa velFTypa(Aliring& a);
	shared_ptr<MótstøðaDetail> keypaMótstøðu();

private:
	Umhvørvið umhvørvið;
	Alistøð alistøð;
	Aliring aliring;
};

TestFasur::TestFasur()
{
}

TestFasur::~TestFasur()
{
}

int TestFasur::testAvVøkstur()
{
	Alistøð støð;
	Aliring a;

	støð.keypaSilo(mm3,10000);
	støð.keypaSilo(mm4, 10000);
	støð.keypaSilo(mm6, 10000);
	støð.keypaSilo(mm9, 10000);
	støð.keypaSilo(mm12, 10000);
	//støð.keypaFóðurInn(10000,mm3);
	//støð.keypaFóðurInn(10000, mm4);
	//støð.keypaFóðurInn(10000, mm6);
	//støð.keypaFóðurInn(10000, mm9);

	int dagur = 0;

	std::ofstream os("VektHvørjaViku.txt", std::ofstream::out);

	while (dagur < 500)
	{
		cout << "Dagur: " << dagur << endl;
		cout << "Fiskur vigar tls:" << a.getFiskur().getBiomassi() << endl;
		cout << "MiðalVektin er:" << a.getFiskur().getBiomassi()/a.getFiskur().getFiskaMongd() << endl;

		a.fiskaVøkstur(0, støð, dagur);
		cout << "Fodur mongd:" << a.getFóðurGiviðSeinast() << endl;

		if (dagur % 7 == true)
		{
			os << dagur << " " << a.getFiskur().getBiomassi() << endl;
			system("pause");
			//double fodur;
			//std::cin >> fodur;

			//a.setFóðurPrDag(fodur);
		}

		if (a.getFiskur().getBiomassi() <= 0) {
			cout << "Fiskurin minkadi til onki :(" << endl;
			break;
		}

		dagur++;
	}
	std::cout << "Fiskur vigar tls:" << a.getFiskur().getBiomassi() << std::endl << "SLUT\n";
	os.close();
	system("pause");
	
	return 0;
}

int TestFasur::hóttanTest()
{
	Umhvørvið á;
	Aliring aliring;

	ifstream is("Hóttanar.txt",ifstream::in);
	string temp;
	getline(is,temp); // Fyrsta linja vísir hvat dataini eru...
	while (getline(is,temp))
	{
		HóttanDetail einHóttan;
		einHóttan = temp;

		if(einHóttan.getNavn() != "")
			á.addaHóttanSumKannKoma(shared_ptr<HóttanDetail>(new HóttanDetail(einHóttan)));
	}

	cout << á.vísAllarHóttanirViðNavni() << endl;

	list<shared_ptr<HóttanDetail>>::iterator start = á.getBeginHóttan(), stop = á.getEndHóttan();
	// List::iterator hevur allar hóttanir, sum kunnu koma inn á aliringin.

	while (true)
	{
	for_each(start, stop, [&aliring](shared_ptr<HóttanDetail> h) {
		int mongdKomið = 0;
		mongdKomið = mongdKomið + aliring.getAliringÁvirkanir().hóttanKemur(h, aliring.getFiskur().getFiskaMongd(), aliring.getFiskur().getBiomassi()/aliring.getFiskur().getFiskaMongd(), 0);
		mongdKomið = mongdKomið + aliring.risikeraHóttan(h, 0);
		if(aliring.getAliringÁvirkanir().hevurHóttan(h))
		{
		 cout << mongdKomið << " av " << h->getNavn() << " er komid afturat i aliringinum: "
			 << aliring.getNavn() << ".\nMongdin er nu: " << aliring.getAliringÁvirkanir()
			 .getMongdAvHóttan(h->getNavn()) << endl;
		}
		else
		{
			cout << h->getNavn() << " finst ikki longur." << endl;
		}
	});

	cout << aliring.getNavn() << " sa stress: " << aliring.getFiskur().getStrongd() << endl;
	cout << "Fiskamongd: " << aliring.getFiskur().getFiskaMongd() << " biomassi: " << aliring.getFiskur().getBiomassi() << endl;

	system("pause");
	}

	return 0;
}

int TestFasur::testProgram1()
{
	ifstream isH("HóttanListTilTestFasa1.txt", ifstream::in);
	string temp;
	getline(isH, temp); // Fyrsta linja vísir hvat dataini eru...
	while (getline(isH, temp))
	{
		HóttanDetail einHóttan;
		einHóttan = temp;

		if (einHóttan.getNavn() != "")
			umhvørvið.addaHóttanSumKannKoma(shared_ptr<HóttanDetail>(new HóttanDetail(einHóttan)));
	}
	cout << "Hottaninar i spaelinum eru: " << umhvørvið.vísAllarHóttanirViðNavni() << endl;
	//--------------------------------------------------
	ifstream isM("Mótstandar.txt", ifstream::in);
	getline(isM, temp); // Fyrsta linja vísir hvat dataini eru...
	while (getline(isM, temp))
	{
		MótstøðaDetail einMótstøða;
		einMótstøða = temp;

		if (einMótstøða.getMótstøðaNavn() != "")
			umhvørvið.addaMótstøðaSumKannKoma(shared_ptr<MótstøðaDetail>(new MótstøðaDetail(einMótstøða)));
	}
	cout << "Motstodurnar i spaelinum eru: " << umhvørvið.vísAllarMótstøðurnarViðNavni() << endl;
	//--------------------------------------------------
	cout << "Fiskurin verdur seldur aftana 400 dagar." << endl;

/*		cout << "\x1 \x2 \x3 \x4 \x5 \x6 \x7 \x8 \x9 \x10" << endl;
		cout << "\x11 \x12 \x13 \x14 \x15 \x16 \x17 \x18 \x19 \x20" << endl;
		cout << "\x21 \x22 \x23 \x24 \x25 \x26 \x27 \x28 \x29 \x30" << endl;
		cout << "\x31 \x32 \x33 \x34 \x35 \x36 \x37 \x38 \x39 \x40" << endl;
		cout << "\x41 \x42 \x43 \x44 \x45 \x46 \x47 \x48 \x49 \x50" << endl;
		cout << "\x51 \x52 \x53 \x54 \x55 \x56 \x57 \x58 \x59 \x60" << endl;
		cout << "\x61 \x62 \x63 \x64 \x65 \x66 \x67 \x68 \x69 \x70" << endl;
		cout << "\x71 \x72 \x73 \x74 \x75 \x76 \x77 \x78 \x79 \x80" << endl;
		cout << "\x81 \x82 \x83 \x84 \x85 \x86 \x87 \x88 \x89 \x90" << endl;
		cout << "\x91 \x92 \x93 \x94 \x95 \x96 \x97 \x98 \x99" << endl; */

	int dagur = 0;
	char avgerð = 'a';
	system("pause");
	while (avgerð != '0')
	{
		system("cls");
		cout << "Dagur: " << dagur << endl;

		cout << "Laksa mongdin er:      " << aliring.getFiskur().getFiskaMongd() << endl;
		cout << "Har Biomassin er:     " << aliring.getFiskur().getBiomassi() << " kg." << endl;
		cout << "Tvs. at midalvektin er: " << aliring.getFiskur().getMiðalVekt() << " kg." << endl;
		cout << "Strongd er uppi a " << 100 * aliring.getFiskur().getStrongd()/aliring.getFiskur().getMaxStrongd() << "%" << endl << endl;

		if (aliring.getFiskur().getBiomassi() <= 0)
		{
			cout << "Ongin fiskur er eftir :(" << endl;
			system("pause");
			break;
		}

		if (dagur >= 400)
		{
			cout << "Laksurin er nu soluklarur og tu hevur fingid " << (int)aliring.getFiskur().getBiomassi() * 60 << " kr\nvid einum kiloprisi a 60 kr" << endl;
			cout << "Tryst a '0' fyri at enda." << endl;
			while (avgerð != '0')
			{
				avgerð = _getche();
			}
			break;
		}

		cout << "Hatturin at fodra er ";

		if(aliring.getAutomatiskFóðring())
		{
			cout << "automatisk.";
		}
		else
		{
			cout << "manuel.";
		}

		cout << endl << endl;

		cout << "1: Naesta Dag" << endl;
		cout << "2: Aliring Status" << endl;
		cout << "3: Keypa Silo" << endl;
		cout << "4: Keypa Fodur" << endl;
		cout << "5: Vis Siloir" << endl;
		cout << "6: Keypa motstodur" << endl;
		cout << "7: Skifta hatt at fodra" << endl;
		cout << "0: Exit (Geva upp)" << endl;

		avgerð = _getche();
		cout << endl;

		fTypa typa;
		shared_ptr<MótstøðaDetail> md;
		switch (avgerð)
		{
		case '1':
			// Næsta dag
			aliring.getAliringÁvirkanir().mótstøðurÁvirka();
			aliring.fiskaVøkstur(0,alistøð,dagur);
			aliring.addaStrongd(-aliring.getFiskur().getStrongd() * 50/100);
			aliring.allarHóttanirKoma(umhvørvið);
			aliring.risikeraAllarHóttanir(0);

			dagur++;
			aliring.getAliringÁvirkanir().mótstøðurGangaÚt(dagur);

			cout << "Tu fodradi " << aliring.getFóðurGiviðSeinast() << " kg" << endl;
			if (aliring.getFóðurTilSpillisSeinast() >= 0)
				cout << "Har " << aliring.getFóðurTilSpillisSeinast() << " kg var yvirfodra." << endl;
			else
				cout << "Har " << -aliring.getFóðurTilSpillisSeinast() << " kg var undirfodra." << endl;
			break;
		case '2':
			// Vísa detaljur
			cout << "Tin aliringur: " << aliring.getNavn() << endl;
			cout << "Laksa mongd: " << aliring.getFiskur().getFiskaMongd() << endl;
			cout << "Biomassin: " << aliring.getFiskur().getBiomassi() << endl << endl;
			cout << "Mongd av lus: " << aliring.getAliringÁvirkanir().getMongdAvHóttan("lus") << endl << endl;
			if (aliring.getAliringÁvirkanir().getMótstøðurÍAliringinum().begin() != aliring.getAliringÁvirkanir().getMótstøðurÍAliringinum().end())
			{
				cout << "Motstodur: " << endl;

				for_each(aliring.getAliringÁvirkanir().getMótstøðurÍAliringinum().begin(), aliring.getAliringÁvirkanir().getMótstøðurÍAliringinum().end(), [dagur](unique_ptr<Mótstøða>& m) {
					cout << m->getMótstøðaDetail()->getMótstøðaNavn() << ": " << m->getMótstøðaDetail()->getDetail() << endl;
					cout << "Livitid eftir: " << m->livitíðEftir(dagur) << endl;
				});
			}
			else
			{
				cout << "Ongar motstodur eru knyttar at aliringinum";
			}
			cout << endl;
			break;
		case '3':
			// Keypa Silo
			cout << "Her kemur tu at velja hvat fyri eitt fodur slag tu vilt, at siloin skal goyma." << endl;
			typa = velFTypa(aliring);
			if(typa != mmNULL)
				alistøð.keypaSilo(typa,10000);
			break;
		case '4':
			// Keypa 1000 kg Fodur
			cout << "Her kemur tu at velja fodur typuna, sum tu vilt keypa inn." << endl;
			typa = velFTypa(aliring);
			if (typa != mmNULL)
				alistøð.keypaFóðurInn(1000,typa);
			break;
		case '5':
			// Vísa Silo
			for (list<Bing>::iterator it = alistøð.getFóðurGoymsla().begin(); it != alistøð.getFóðurGoymsla().end(); it++)
			{
				cout << *it << endl;
			}
			break;
		case '6':
			// Keypa motstodur
			md = keypaMótstøðu();
			if(md != nullptr)
			{
				aliring.getAliringÁvirkanir().addaMótstøða(md, dagur);
			}
			break;
		case '7':
			aliring.setAutomatisktFóður(velFóðurMetoda());
			break;
		case '0':
			// exit
			cout << "Takk fyri at tu spaeldi :)" << endl;
			break;
		default:
			cout << "Ikki ein moguleiki..\x7" << endl;
			break;
		}
		system("pause");
	}

	return 0;
}

fTypa TestFasur::velFTypa(Aliring& a)
{
	fTypa t = mmNULL;

	cout << "Midalvektin a laksinum er nu: " << a.getFiskur().getMiðalVekt() << " kg" << endl;

	cout << "Hvat fyri eitt fodur slag?" << endl;
	cout << "1. 3mm  - til laks millum 0.040-0.150  kg" << endl;
	cout << "2. 4mm  - til laks millum 0.150-0.300  kg" << endl;
	cout << "3. 6mm  - til laks millum 0.300-0.800  kg" << endl;
	cout << "4. 9mm  - til laks millum 0.800-2.500  kg" << endl;
	cout << "5. 12mm - til laks millum 2.500-10.000 kg" << endl;
	cout << "0. Ikki keypa." << endl;

	
	bool gott = false;
	while (!gott)
	{
		char a = _getche();
		cout << endl;
		switch (a)
		{
		case '1':
			t = mm3;
			gott = true;
			break;
		case '2':
			t = mm4;
			gott = true;
			break;
		case '3':
			t = mm6;
			gott = true;
			break;
		case '4':
			t = mm9;
			gott = true;
			break;
		case '5':
			t = mm12;
			gott = true;
			break;
		case '0':
			gott = true;
			break;
		default:
			cout << "Vel eitt tall millum 1-5." << endl;
			break;
		}
	}
	return t;
}

shared_ptr<MótstøðaDetail> TestFasur::keypaMótstøðu()
{
	cout << "Skriva inn hvorja motstodu tu vilt hava." << endl;
	cout << "Moguleikarnir eru: ";
	for_each(umhvørvið.getBeginMótstøða(), umhvørvið.getEndMótstøða(), [](shared_ptr<MótstøðaDetail> md) { 
		cout << md->getMótstøðaNavn() << ", ";
	});
	cout << "og '0' til at angra." << endl;

	while (true)
	{
		string brúkaraVal;
		std::cin >> brúkaraVal;

		if(brúkaraVal == "0")
		{
			return nullptr;
		}

		for (list<shared_ptr<MótstøðaDetail>>::iterator it = umhvørvið.getBeginMótstøða(); it != umhvørvið.getEndMótstøða(); it++)
		{
			if (brúkaraVal == it->get()->getMótstøðaNavn())
			{
				return *it;
			}
		}
		cout << "Skriva inn 'bokstavarætt' motstoduna.." << endl;
	}
}

bool TestFasur::velFóðurMetoda()
{	
	while (true)
	{
		cout << "1. Vel automatisk fodring" << endl;
		cout << "2. Vel manuel fodring" << endl;
		char val = _getche();
		double num = 0;
		switch (val)
		{
		case '1':
			return true;
			break;
		case '2':
				while (std::cout << "\nSkriva inn fodur mongd i kg pr dag: " && !(std::cin >> num)) {
					std::cin.clear(); //clear bad input flag
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
					std::cout << "Skeivt ikast; skriva inn aftur.\n";
				}
				aliring.setFóðurPrDag(num);
				return false;
			break;
		default:
			cout << "Moguleikarnir eru 1 og 2." << endl << endl;
		}
	}
}

int main()
{
	srand(time(nullptr));

	TestFasur t;
	//t.hóttanTest();
	//t.testAvVøkstur();
	t.testProgram1();
	return 0;
}