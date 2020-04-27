#include "Service.h"
#include <iostream>
#include "Booking.h"
#include <limits>
void Service::addBooking(std::string name, int flightId, int seatNumber)
{
    char tmp;
    Booking booking(flightId, seatNumber, name);
    repo.addItem(booking);
}

void Service::setRepo(Repo<Booking> repo)
{
    this->repo = repo;
}

std::list<Booking> Service::getAll()
{
    return this->repo.getAll();
}
Booking& Service::search( std::string name )
{
    std::list<Booking> bookings = this->repo.getAll();
    std::string tmpName;
    Booking b;
    for (Booking & booking : bookings) {
        tmpName = booking.getPassangerName();
        if ( name == tmpName ) {
            return booking;
        }
    }
    return b;
}
bool Service::bookingExists( std::string name )
{
    bool exists = false;
    std::list<Booking> bookings = this->repo.getAll();
    std::string tmpName;
    for (Booking & booking : bookings) {
        tmpName = booking.getPassangerName();
        if ( name == tmpName ) {
            exists = true;
            break;
        }
    }
    return exists;
}
int Service::getNoOfBookings()
{
    return this->repo.getSize();
}

void Service::update(Booking oldBooking, Booking newBooking)
{

    this->repo.update(oldBooking, newBooking);
}

void Service::del(std::string name)
{
    Booking booking = this->search(name);
    this->repo.del(booking);
}
