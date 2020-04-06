#pragma once
#include <list>
#include <iostream>
#include "Booking.h"
#include <vector>
#include <fstream>
#include <string>
using namespace std;


template <class Elem>
class Repo
{
protected:
	list<Elem> elemente;
public:
	Repo();
	~Repo();
	void addElem(Elem&);
	list<Elem>& GetAll();
    __int64_t getSize();
	void del(Elem&);
    __int64_t findElem(Elem);
	Elem& get(size_t _i);
	void updateElem(Elem&,Elem);
};


template <class Elem>
Repo<Elem>::Repo()
{

}

template<class Elem>
Repo<Elem>::~Repo()
{
}

template<class Elem>
void Repo<Elem>::addElem(Elem& elem)
{
	
	elemente.push_back(elem);
}

template<class Elem>
list<Elem>& Repo<Elem>::GetAll()
{
	return this->elemente;
}

template<class Elem>
__int64_t Repo<Elem>::getSize()
{
	return  elemente.size();
}


template<class Elem>
__int64_t Repo<Elem>::findElem(Elem elem)
{
	typename list<Elem>::iterator it;
	it = find(elemente.begin(), elemente.end(), elem);
	if (it != elemente.end()) {
		return distance(elemente.begin(), it);
	}
	return 1323;
}

template<class Elem>
Elem& Repo<Elem>::get(size_t _i)
{
	typename list<Elem>::iterator it = elemente.begin();
	for (size_t i = 0; i < _i; i++) {
		++it;
	}
	return *it;
}



 template<class Elem>
 void Repo<Elem>::updateElem(Elem& elem, Elem newElem)
 {
	 typename list<Elem>::iterator it;
	 it = find(elemente.begin(), elemente.end(), elem);
	 *it = newElem;
 }


template<class Elem>
void Repo<Elem>::del(Elem& elem)
{
	
	typename list<Elem>::iterator it;
	it = find(elemente.begin(), elemente.end(), elem);
	if (it != elemente.end()) {
		elemente.erase(it);
		
	}
	
	
}
