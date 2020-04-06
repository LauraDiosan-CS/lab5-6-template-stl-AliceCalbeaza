#pragma once
#pragma once
#include "Repository.h"
#include "Booking.h"
#include <vector>
#include <list>
using namespace std;
class Service
{
private: 
	
	Repo<Rezervare> repo;
public:
	  Service();
	  Service(const Repo<Rezervare>&);
	  void setRepo(const Repo<Rezervare>&);
	  void addRezervare(Rezervare&);
	  void delRezervare(Rezervare&);
	  list<Rezervare> getAll();
	  vector<Rezervare> getAll2();
	  Rezervare update(Rezervare,Rezervare);
    __int64_t findOne(Rezervare);
    __int64_t getSize();
	  list<Rezervare> filtreazaDupaNumeSiNr1(const char*, int);
	  list<Rezervare> sortByNrZbor();
	  list<Rezervare> sortByNrLoc();
	  vector<Rezervare> sorteazaDupaLoc();
	  list<Rezervare> sortByNameCresc();
	  list<Rezervare> sortByNameDescrs();
	  list<Rezervare> Avanseaza(const char*);
	  list<Rezervare> NrZborEgalCuPozLista(const char*);
    __int64_t getSizeCost();
	  ~Service();
};

