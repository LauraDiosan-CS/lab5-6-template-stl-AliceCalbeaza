#include <ostream>
#include <string>
#include <stdlib.h>
#include <istream>
#include <iostream>
using namespace std;


#ifndef ZBOR_H
#define ZBOR_H
class Rezervare {
private:
	char* nume;
	int nr_zbor;
	int nr_loc;

public:
	Rezervare();
	Rezervare(const char*, int, int);
	Rezervare(const Rezervare&);
	Rezervare(string);
	char* getNume();
	int getNrZbor();
	int getNrLoc();
	void setNume(const char*);
	void setNrZbor(int);
	void setNrLoc(int);
	~Rezervare();
	Rezervare& operator=(const Rezervare&);
	bool operator==(const Rezervare& e);
	bool operator!=(const Rezervare& e);
	bool compare(Rezervare& e);
	bool operator<(const Rezervare&);
	bool operator>(const Rezervare&);
	char* toString();
	friend ostream& operator<<(ostream&, Rezervare&);
	friend istream& operator>>(istream&, Rezervare&);
};

#endif
