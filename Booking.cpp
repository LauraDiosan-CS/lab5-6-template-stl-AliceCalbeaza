#include "Booking.h"
#include <string.h>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>



using namespace std;
Rezervare::Rezervare() {
	this->nume = NULL;
	this->nr_zbor = 0;
	this->nr_loc = 0;
}
Rezervare::Rezervare(const char* nume, int nr_zbor, int nr_loc) {
	this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
	this->nr_zbor = nr_zbor;
	this->nr_loc = nr_loc;
}

Rezervare::Rezervare(const Rezervare& e) {
	this->nume = new char[strlen(e.nume) + 1];
    strcpy(this->nume, e.nume);
	this->nr_zbor = e.nr_zbor;
	this->nr_loc = e.nr_loc;
}

Rezervare::Rezervare(string linie)
{
	std::istringstream iss(linie);
	string tok1, tok2,tok3;
	iss >> tok1 >> tok2 >> tok3;
	nume = new char[tok1.length() + 1];
    strcpy(nume, tok1.c_str());
	nr_zbor = stoi(tok2);
	nr_loc = stoi(tok3);
}

//Geteri


char* Rezervare::getNume() {
	return this->nume;
}

int Rezervare::getNrZbor() {
	return this->nr_zbor;
}

int Rezervare::getNrLoc() {
	return this->nr_loc;
}

//Seteri


void Rezervare::setNume(const char* nume) {
	if (this->nume != NULL) {
		delete[] this->nume;
	}
	this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);

}

void Rezervare::setNrZbor(int nr_zbor) {
	this->nr_zbor = nr_zbor;
}

void Rezervare::setNrLoc(int nr_loc) {
	this->nr_loc = nr_loc;
}
char* Rezervare::toString() {
	if (this->nume != NULL) {
		size_t noChars = strlen(this->nume) + 13;
		char* s = new char[noChars];
		char* aux = new char[5];
		char* aux2 = new char[5];
		strcpy(s, this->nume);
		strcat(s, " ");
		strcat(s, aux2);
		strcat(s, " ");
		strcat(s, aux);
		if (aux) {
			delete[] aux;
			aux = NULL;
		}
		strcat(s, " ");
		return s;
	}
	else
	{
		char* x = new char[1];
		strcpy(x, "");
		return x;
	}
}


Rezervare& Rezervare::operator=(const Rezervare& e) {
	this->setNume(e.nume);
	this->setNrZbor(e.nr_zbor);
	this->setNrLoc(e.nr_loc);
	return *this;
}


Rezervare::~Rezervare() {
	if (this->nume != NULL) {
		delete[] this->nume;
		this->nume = NULL;
	}
	this->nr_zbor = 0;
	this->nr_loc = 0;
}
bool  Rezervare::compare(Rezervare& e) {
	return ((this->nr_zbor == e.nr_zbor) && (strcmp(this->nume, e.nume) == 0) && (this->nr_loc == e.nr_loc));
}

bool Rezervare::operator<(const Rezervare& e)
{
	return ((strcmp(this->nume, e.nume) < 0) && (this->nr_zbor < e.nr_zbor) && (this->nr_loc < e.nr_loc));

}

bool Rezervare::operator>(const Rezervare& e)
{
	return ((strcmp(this->nume, e.nume) > 0) && (this->nr_zbor > e.nr_zbor) && (this->nr_loc > e.nr_loc));
}



bool Rezervare:: operator==(const Rezervare& e) {
	return strcmp(this->nume, e.nume) == 0 && this->nr_zbor == e.nr_zbor && this->nr_loc == e.nr_loc;
}

bool Rezervare:: operator!=(const Rezervare& e) {

	return strcmp(this->nume, e.nume) == 0 && this->nr_zbor == e.nr_zbor && this->nr_loc != e.nr_loc;

}

ostream& operator<<(ostream& os, Rezervare& e) {
	os << e.nume << " " << e.nr_zbor << " " << e.nr_loc << endl;
	return os;
	
}

istream& operator>>(istream& is, Rezervare& e)
{
	cout << "Dati numele: ";
	char* nume = new char[20];
	cin >> nume;
	cout << "Dati nr_zbor: ";
	int nr_zbor;
	cin >> nr_zbor;
	cout << "Dati nr_loc:";
	int nr_loc;
	cin >> nr_loc;
	e.setNume(nume);
	e.setNrZbor(nr_zbor);
	e.setNrLoc(nr_loc);
	delete[] nume;
	return is;
}
