#include "TestRepository.h"
#include <list>
#include<cassert>
#include<iostream>
#include<string.h>
#include "Repository.h"
#include "Booking.h"
using namespace std;

void testRepo()
{
	Repo<Rezervare> r;
	list<Rezervare> rez;
	rez = r.GetAll();
	assert(rez.size() == 0);
	char* aux = new char[5];
	strcpy(aux, "corn");
	Rezervare p = Rezervare(aux, 11, 25);
	r.addElem(p);
	rez.push_back(p);
	Rezervare p1 = Rezervare(aux, 11, 11);
	r.addElem(p1);
	rez.push_back(p1);
	Rezervare p2 = Rezervare(aux, 22, 22);
	r.addElem(p2);
	rez.push_back(p2);
	assert(r.findElem(p1) == 1);
	assert(r.getSize() == 3);
	assert(rez.size() == 3);
	cout << "Teste Repository" << endl;
}
	
void testRepo2() {
	Repo<Rezervare> r2;
	char* auxx = new char[6];
	strcpy(auxx, "cornx");
	Rezervare x = Rezervare(auxx, 11, 25);
	r2.addElem(x);
	assert(r2.getSize() == 1);
	Rezervare x1 = Rezervare(auxx, 11, 11);
	r2.addElem(x1);
	assert(r2.getSize() == 2);
	Rezervare x2 = Rezervare(auxx, 22, 22);
	r2.addElem(x2);
	assert(r2.getSize() == 3);
	r2.del(x1);
	list<Rezervare> rezx;
	rezx = r2.GetAll();
	assert(rezx.size() == 2);
	r2.del(x);
	list<Rezervare> rezxx;
	rezxx = r2.GetAll();
	assert(rezxx.size() == 1);
	r2.del(x2);
	list<Rezervare> rexxx;
	rexxx = r2.GetAll();
	assert(rexxx.size() == 0);
	


	cout << "Testul 1 pentru Repository rulează" << endl;


}

void testRepo3()
{
	Repo<Rezervare> r3;
	char* auxx = new char[7];
	strcpy(auxx, "Darius");
	Rezervare x = Rezervare(auxx, 20, 20);
	assert(x.getNrZbor() == 20);
	assert(x.getNrLoc() == 20);
	r3.addElem(x);
	assert(r3.getSize() == 1);
	assert(r3.findElem(x) == 0);
	Rezervare y = Rezervare(auxx, 30, 40);
	assert(r3.getSize() == 1);
	assert(r3.findElem(y) == 1323);
	assert(r3.findElem(Rezervare("Darius", 20, 20)) == 0);
	assert(r3.findElem(Rezervare("Marian", 21, 23)) == 1323);
	r3.updateElem(x, Rezervare("Marian", 21, 23));
	assert(r3.findElem(Rezervare("Marian", 21, 23)) == 0);
	list<Rezervare> rev;
	rev = r3.GetAll();
	assert(rev.size() == 1);
	cout << "Testul 2 pentru Repository rulează" << endl;
}

	



	








