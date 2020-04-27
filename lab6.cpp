#include <iostream>
#include "Repo.h"
#include <list>
#include "Booking.h"
#include "Tests.h"
#include "Service.h"
#include "UI.h"
int main() {
    std::cout << "Lab 6" << std::endl;
    tests();
    Repo<Booking> repo;
    Service service;
    service.setRepo(repo);
    UI ui;
    ui.setService(service);
    ui.show();
}
