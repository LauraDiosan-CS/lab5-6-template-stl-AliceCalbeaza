#include <iostream>
#include <sstream>
#include "Booking.h"
#include <string.h>
Booking::Booking(unsigned int id, unsigned int seatNumber, std::string passanger_name) {
    this->flightId = id;
    this->seatNumber = seatNumber;
    this->passanger_name = passanger_name;
}
unsigned int Booking::getFlightId(){
    return this->flightId;
}
unsigned int Booking::getSeatNumber(){
    return this->seatNumber;
}
std::string Booking::getPassangerName(){
    return this->passanger_name;
}

void Booking::setFlightId( unsigned int flightId )
{
    this->flightId = flightId;
}
void Booking::setSeatNumber( unsigned int seatNumber )
{
    this->seatNumber = seatNumber;
}
void Booking::setPassangerName( std::string name )
{
    this->passanger_name = name;
}
Booking::Booking()
{

}
bool Booking:: operator==(const Booking & e)
{
    return this->passanger_name== e.passanger_name
        && this->flightId == e.flightId
        && this->seatNumber == e.seatNumber;
}
std::ostream& operator<<(std::ostream& os, Booking flight) {
	os << "Numarul zborului:" << flight.getFlightId() << std::endl;
	os << "Numarul locului:" << flight.getSeatNumber() << std::endl;
	os << "Nume pasager:" << flight.getPassangerName() << std::endl;
	return os;
}
