#pragma once
#include <sstream>
#include <string>
class Flight {
    private:
        unsigned int id;
        unsigned int seatNumber ;
        std::string passanger_name;
    public:
        Flight(unsigned int id, unsigned int seatNumber, std::string passanger_name);
        unsigned int getId();
        unsigned int getSeatNumber();
        std::string getPassangerName();
        friend std::ostream& operator<<(std::ostream& os, Flight flight);
};
