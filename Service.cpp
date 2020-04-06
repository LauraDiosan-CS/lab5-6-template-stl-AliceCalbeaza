#include "Service.h"
#include <algorithm> 

Service::Service()
{
}

Service::Service(const Repo<Rezervare>& r)
{
	repo = r;
}

void Service::setRepo(const Repo<Rezervare>& r)
{
	repo = r;
}



void Service::addRezervare(Rezervare& r)
{
	repo.addElem(r);
}

void Service::delRezervare(Rezervare& r)
{
	repo.del(r);
}

list<Rezervare> Service::getAll()
{
	return repo.GetAll();
}

vector<Rezervare> Service::getAll2()
{
	list<Rezervare> rez = repo.GetAll();
	vector<Rezervare> v(rez.begin(), rez.end());
	return v;
}

Rezervare Service::update(Rezervare r, Rezervare r1)
{
	repo.updateElem(r, r1);
	return r;
}


__int64_t Service::findOne(Rezervare r)
{
	return repo.findElem(r);
}

__int64_t Service::getSize()
{
	return this->repo.getSize();
}

list<Rezervare>Service::filtreazaDupaNumeSiNr1(const char* n, int a) {

	list<Rezervare> rez;
    for (__int64_t i = 0;i < repo.getSize();i++)
	{
		Rezervare crt = repo.get(i) ;
		if (strstr(crt.getNume(), n) && crt.getNrZbor() >= a) {
			rez.push_back(crt);
		}
	}
	return rez;
}


	
bool myNrZborCompare(Rezervare x, Rezervare y){
if (x.getNrZbor() == y.getNrZbor()) {
	return x < y;
}
	return x.getNrZbor() < y.getNrZbor();

}


list<Rezervare> Service::sortByNrZbor()
{

	list<Rezervare> all = repo.GetAll();
	all.sort(myNrZborCompare);
	return all;
}

bool myNrLocCompare(Rezervare x, Rezervare y) {
	if (x.getNrLoc() == y.getNrLoc()) {
		return x > y;
	}
	return x.getNrZbor() > y.getNrZbor();

}

list<Rezervare> Service::sortByNrLoc()
{
	list<Rezervare> all = repo.GetAll();
	all.sort(myNrLocCompare);
	return all;
}

vector<Rezervare> Service::sorteazaDupaLoc()
{
	list<Rezervare> all = repo.GetAll();
	all.sort(myNrLocCompare);
	vector<Rezervare> rez(all.begin(), all.end());
	return rez;
}

bool myNameCompareCresc(Rezervare x, Rezervare y) {

	
	if (strcmp(x.getNume(),y.getNume()) == 0) {
		return x < y;
	}
	return strcmp(x.getNume(), y.getNume()) < 0;

}

list<Rezervare> Service::sortByNameCresc()
{
	list<Rezervare> all = repo.GetAll();
	all.sort(myNameCompareCresc);
	return all;
}
bool myNameCompareDescresc(Rezervare x, Rezervare y) {


	if (strcmp(x.getNume(), y.getNume()) == 0) {
		return x > y;
	}
	return strcmp(x.getNume(), y.getNume()) > 0;

}


list<Rezervare> Service::sortByNameDescrs()
{
	list<Rezervare> all = repo.GetAll();
	all.sort(myNameCompareDescresc);
	return all;
}

list<Rezervare> Service::Avanseaza(const char* name)
{
	list<Rezervare> RezervareFilter;
	int first = 0;
    for (__int64_t i = 0; i < repo.getSize(); i++) {
		Rezervare& re = repo.get(i);
		
		if (strcmp(re.getNume(), name) == 0) {
			first++; 
			re.setNrZbor(first);
			RezervareFilter.push_back(re);
			
		}
		
	}

	return RezervareFilter;

}

list<Rezervare> Service::NrZborEgalCuPozLista(const char* name)
{
	list<Rezervare> RezervareFilter;
	int first = 0;
    for (__int64_t i = 0; i < repo.getSize(); i++) {
		Rezervare& re = repo.get(i);
		first++;
		if (strcmp(re.getNume(), name) == 0) {
			re.setNrZbor(first);
			RezervareFilter.push_back(re);

		}

	}

	return RezervareFilter;
}





Service::~Service()
{
}
