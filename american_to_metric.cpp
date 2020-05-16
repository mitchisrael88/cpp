#include <iostream>
using namespace std;
//convert feet to meters

int main()
{
	std::cout << "Mitchell Israel\nHomework_1\nProf. Croker\nCIS 9310";
	
	//initiate feet
	double X{ 0 };

	//obtain data from user
	std::cout << "\n\nWhat is the in feet that is to be converted to meters?\n";
	std::cin >> X;

	//intiate meters
	double Y{ 0 };
	
	//convert feet to meters
	Y = X * 3.2808;

	//output results 
	std::cout << X << " feet is equal to " << Y << " meters" << std::endl;

	//terminate program
	return 0;
}