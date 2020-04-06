#include "UI.h"
#include <iostream>
using namespace std;

void addRez(Service& serv) {
	Rezervare re;
	cout << "Dati Rezervarea:";
	cin >> re;
	serv.addRezervare(re);
	cout << "Rezervarea a fost adaugata cu succes!" << endl;
}


void findStud(Service& serv) {
	Rezervare re;
	cout << "Dati Rezervarea:";
	cin >> re;
    __int64_t rez = serv.findOne(re);
	cout << "Pozitia rezervarii este:" << rez;
}
	


void delRez(Service& serv) {
	Rezervare re;
	cout << "Dati Rezervarea:" << endl;
	cin >> re;
	serv.delRezervare(re);
	cout << "Rezervare stearsa" << endl;
}

void showAll(Service& serv) {
	list<Rezervare> re = serv.getAll();
	for (Rezervare r : re)
		cout << r;
}

void UpdateRezervare(Service& serv) {
	Rezervare re;
	cout << "Dati Rezervarea de modificat:" << endl;
	cin >> re;
	char* newnume = new char[25];
	cout << "Noul nume:" << endl;
	cin >> newnume;
	int newnr1;
	cout << "Noul numar de zbor:" << endl;
	cin >> newnr1;
	int newnr2;
	cout << "Noua numar al locului:" << endl;
	cin >> newnr2;
	Rezervare rex =serv.update(re,Rezervare(newnume,newnr1,newnr2));
	cout << "Rezervarea in cazul existentei acesteia a fost modificata!" << endl;


}


void Proprietate1(Service& serv) {
	char* n = new char[10];
	int v;
	cout << "Dati subsirul cautat in nume: ";
	cin >> n;
	cout << "Dati nr de zbor minimal:";
	cin >> v;

	list<Rezervare> re = serv.filtreazaDupaNumeSiNr1(n, v);
	for (Rezervare r : re)
		cout << r;
	delete[] n;

}


void Proprietate2(Service& serv) {

	list<Rezervare> rez = serv.sortByNrZbor();
	for (Rezervare r : rez)
		cout << r;

}

void Proprietate3(Service& serv) {

	list<Rezervare> rez = serv.sortByNrLoc();
	for (Rezervare r : rez)
		cout << r;

}


void Proprietate4(Service& serv) {
	char* nume_zbor = new char[25];
	cout << " Introduceti numele:";
	cin >> nume_zbor;
	//int bonus = 0;
	list<Rezervare> re = serv.Avanseaza(nume_zbor);
	for (Rezervare r : re)
		cout << r;
	delete[] nume_zbor;
}

void Proprietate5(Service& serv) {
	char* nume_zbor = new char[25];
	cout << " Introduceti numele:";
	cin >> nume_zbor;
	//int bonus = 0;
	list<Rezervare> re = serv.NrZborEgalCuPozLista(nume_zbor);
	for (Rezervare r : re)
		cout << r;
	delete[] nume_zbor;
}

void Proprietate6(Service& serv) {
	list<Rezervare> rez = serv.sortByNameCresc();
	for (Rezervare r : rez)
		cout << r;
}

void Proprietate7(Service& serv) {
	list<Rezervare> rez = serv.sortByNameDescrs();
	for (Rezervare r : rez)
		cout << r;
}






 




void NumarDeRezervari(Service& serv) {
	list<Rezervare> re = serv.getAll();
	cout <<"Numarul de rezervari:"<< re.size();
	cout << endl;
	
}



void showUI(Service& serv)
{
	bool gata = false;
	while (!gata) {
		cout << endl;
		cout << "OPTIUNI: " << endl;
		cout << "	1. Adauga rezervare " << endl;
		cout << "	2. Cauta rezervare " << endl;
		cout << "	3. Sterge rezervare " << endl;
		cout << "	4. Afiseaza toate rezervariile " << endl;
		cout << "	5. Modifica rezervare " << endl;
		cout << "	6. 1st Property " << endl;
		cout << "	7. 2nd Property " << endl;
		cout << "	8. 3rd Property" << endl;
		cout << "	9. 4th Property" << endl;
		cout << "	10. 5th Property " << endl;
		cout << "	11. 6th Property" << endl;
		cout << "	12. 7th Property" << endl;
		cout << "	13. Numarul de Rezervari" << endl;
		cout << "	0. Exit!" << endl;
		cout << "Introduceti optiunea: " ;
		int opt;
		cin >> opt;
		switch (opt) {
		case 1: {addRez(serv); break; }
		case 2: {findStud(serv); break; }
		case 3: {delRez(serv); break; }
		case 4: {showAll(serv); break; }
		case 5: {UpdateRezervare(serv);break;}
		case 6: {Proprietate1(serv);break;}
		case 7: {Proprietate2(serv);break;}
		case 8: {Proprietate3(serv);break;}
		case 9: {Proprietate4(serv);break;}
		case 10:{Proprietate5(serv);break;}
		case 11: {Proprietate6(serv);break;}
		case 12: {Proprietate7(serv);break;}
    
		case 13: {NumarDeRezervari(serv);break;}
		case 0: {gata = true; cout << "Goodbye! Have a nice day! :-D" << endl; }
		}
	}
}
