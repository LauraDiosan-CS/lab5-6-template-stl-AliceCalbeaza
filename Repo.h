#pragma once
#include <list>
#include "Flight.h"


class Repo {
    std::list <Flight> flights;
    public:
        void addFlight(Flight flight);
        std::list<Flight> getAll();
};
