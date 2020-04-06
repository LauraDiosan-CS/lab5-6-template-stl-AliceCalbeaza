#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "Booking.h"
#include "TestFlight.h"
#include "stdlib.h"
#include "Repository.h"
#include "TestRepository.h"
#include "Service.h"
#include "TestService.h"
#include "UI.h"


int main() {
	testRepo();
	testRepo2();
	testRepo3();
	TestService ts;
	ts.runTests();
	Service serv;
	showUI(serv);
	cout << "succes";
	return 0;

	
	
}
