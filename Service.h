#pragma once
#include <string>
#include "Repo.h"
class Service
{
    private:
        Repo<Booking> repo;
    public:
        void addBooking(std::string name, int FlightId, int seatNumber);
        void setRepo(Repo<Booking> repo);
        int getNoOfBookings();
        bool bookingExists( std::string name );
        void update(Booking oldBooking, Booking newBooking);
        void del(std::string name);
        Booking& search( std::string name );
        std::list<Booking> getAll();
};
