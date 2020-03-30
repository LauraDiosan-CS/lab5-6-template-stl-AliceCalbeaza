#include <iostream>
#include "Repo.h"
#include <list>
#include "Flight.h"
void Repo::addFlight(Flight flight){
    this->flights.push_back( flight );
}
std::list<Flight> Repo::getAll() {
    return this->flights;
}
