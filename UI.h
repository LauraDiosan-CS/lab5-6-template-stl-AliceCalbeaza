#pragma once
#include "Service.h"
#include "list"
class UI
{
    private:
        Service service;
    public:
        void show();
        void addBooking();
        void setService(Service service);
        void listBookings();
        void viewBooking();
        void editBooking();
        void deleteBooking();
};
