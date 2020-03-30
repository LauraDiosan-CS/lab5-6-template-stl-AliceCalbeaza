#include <iostream>
#include <sstream>
#include "Flight.h"
#include <string>
Flight::Flight(unsigned int id, unsigned int seatNumber, std::string passanger_name) {
    this->id = id;
    this->seatNumber = seatNumber;
    this->passanger_name = passanger_name;
}
unsigned int Flight::getId(){
    return this->id;
}
unsigned int Flight::getSeatNumber(){
    return this->seatNumber;
}
std::string Flight::getPassangerName(){
    return this->passanger_name;
}
std::ostream& operator<<(std::ostream& os, Flight flight) {
	os << "Numarul zborului:" << flight.getId() << std::endl;
	os << "Numarul locului:" << flight.getSeatNumber() << std::endl;
	os << "Nume pasager:" << flight.getPassangerName() << std::endl;
	return os;
}
