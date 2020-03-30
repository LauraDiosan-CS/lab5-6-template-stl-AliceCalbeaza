#include <iostream>
#include "Tests.h"
#include "Flight.h"
#include "Repo.h"
#include "assert.h"
#include <list>
void tests(){
    Repo repo;
    Flight* flight;
    flight = new Flight(1, 100, "Alice");
    repo.addFlight(*flight);
    flight = new Flight(2, 200, "Cristian");
    repo.addFlight(*flight);
    std::list<Flight> flights = repo.getAll();
    assert(2 == flights.size());
    std::cout << "Tests ok" << std::endl;
}
