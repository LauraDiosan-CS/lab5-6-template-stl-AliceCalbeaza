#include <iostream>
#include "Repo.h"
#include <list>
#include "Flight.h"
#include "Tests.h"
int main() {
    std::cout << "Lab 6" << std::endl;
    tests();
    Repo repo;
    Flight* flight;
    flight = new Flight(1, 100, "Alice");
    repo.addFlight(*flight);
    flight = new Flight(2, 200, "Cristian");
    repo.addFlight(*flight);
    std::list<Flight> flights = repo.getAll();
    for( Flight flight : flights )
        std::cout << flight << std::endl;
}
