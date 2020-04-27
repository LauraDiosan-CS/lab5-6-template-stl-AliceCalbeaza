#include "UI.h"
#include <iostream>
#include <string>
#include <list>
#include <limits>
void pause()
{

    std::cout << "Tastati <enter> pentru a continua";
    std::cin.get();
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void UI::show()
{
    std::cout << "Show UI" << std::endl;
    char option;
    bool run=true;
    while(run) {
        std::cout << std::endl;
        std::cout << "Optiuni:" << std::endl;
        std::cout << "1) Listare rezervari" << std::endl;
        std::cout << "2) Adauga rezervare" << std::endl;
        std::cout << "3) Afisare rezervare" << std::endl;
        std::cout << "4) Editare rezervare" << std::endl;
        std::cout << "5) Stergere rezervare" << std::endl;
        std::cout << "x) Exit" << std::endl;
        std::cin >> option;
        switch (option ) {
            case '1':
                this->listBookings();
                break;
            case '2':
                this->addBooking();
                break;
            case '3':
                this->viewBooking();
                break;
            case '4':
                this->editBooking();
                break;
            case '5':
                this->deleteBooking();
                break;
            case 'x':
                run = false;
                std::cout << "Bye." << std::endl;
                break;
            default:
                std::cout << "Optiune invalida" << std::endl;
                break;
        }
    }
}
void UI::setService(Service service)
{
    this->service = service;
}
void UI::listBookings()
{
    std::list<Booking> bookings;
    bookings = this->service.getAll();
    int size = this->service.getNoOfBookings();
    if ( size == 0 ) {
        std::cout << "Nu exista rezervari" << std::endl;
        pause();
    } else {
        for (const Booking & booking : bookings) {
            std::cout << booking << std::endl;
        }
        pause();
    }
}
void UI::addBooking()
{
    std::string name; 
    int flightId;
    int seatNumber;
    std::cout << "Introduceti numele pasagerului" << std::endl;
    std::cin >> name;
    std::cout << "Id zbor:" << std::endl;
    std::cin >> flightId;
    std::cout << "Numarul locului:" << std::endl;
    std::cin >> seatNumber;
    std::cout << "Numarul locului" << seatNumber << std::endl;
    this->service.addBooking(name, flightId, seatNumber);
    std::cout << "Rezervarea a fost efectuata" << std::endl;
    pause();
}

void UI::viewBooking()
{
    std::string name;
    std::cout << "Introduceti numele: " << std::endl;
    std::cin >> name;
    if ( this->service.bookingExists(name) ) {
        Booking booking=this->service.search(name);
        std::cout << booking;
    } else {
        std::cout << "Nu exista nici o rezervare penru pasagerul " << name << std::endl;
    }
    pause();
}

void UI::editBooking()
{
    std::string name;
    std::cout << "Introduceti numele: " << std::endl;
    std::cin >> name;
    if ( this->service.bookingExists(name) ) {
        Booking oldBooking=this->service.search(name);
        Booking newBooking;
        std::string  name;
        int flightId;
        int seatNumber;
        std::cout << "Introduceti numele pasagerului ( actual: " << oldBooking.getPassangerName() << "):";
        std::cin >> name;
        newBooking.setPassangerName(name);
        std::cout << "Introduceti numarul zborului ( actual: " << oldBooking.getFlightId() << "):";
        std::cin >> flightId;
        newBooking.setFlightId(flightId);
        std::cout << "Introduceti numarul locului ( actual: " << oldBooking.getSeatNumber() << "):";
        std::cin >> seatNumber;
        newBooking.setSeatNumber(seatNumber);
        this->service.update(oldBooking, newBooking);
    } else {
        std::cout << "Nu exista nici o rezervare penru pasagerul " << name << std::endl;
    }
    pause();
}

void UI::deleteBooking()
{
    std::string name;
    std::cout << "Introduceti numele: " << std::endl;
    std::cin >> name;
    if(this->service.bookingExists(name)) {
        this->service.del(name);
    }else{
        std::cout << "Nu exista nici o rezervare penru pasagerul " << name << std::endl;
    }
}
