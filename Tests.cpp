#include <iostream>
#include "Tests.h"
#include "Booking.h"
#include "Repo.h"
#include "assert.h"
#include <list>
void tests(){
    Repo<Booking> repo;
    Booking* booking;
    booking = new Booking(1, 100, "florin");
    repo.addItem(*booking);
    booking = new Booking(2, 200, "adrian");
    repo.addItem(*booking);
    std::list<Booking> bookings = repo.getAll();
    assert(2 == bookings.size());
    std::cout << "Tests ok" << std::endl;
}
