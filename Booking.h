#pragma once
#include <sstream>
#include <string>
class Booking {
    private:
        unsigned int flightId;
        unsigned int seatNumber ;
        std::string passanger_name;
    public:
        Booking();
        bool operator==(const Booking & e);
        Booking(unsigned int flightId, unsigned int seatNumber, std::string passanger_name);
        unsigned int getFlightId();
        unsigned int getSeatNumber();
        std::string getPassangerName();
        void setFlightId( unsigned int flightId );
        void setSeatNumber( unsigned int seatNumber );
        void setPassangerName( std::string name );
        friend std::ostream& operator<<(std::ostream& os, Booking flight);
};
