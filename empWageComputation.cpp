#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	cout << "Welcome to Employee wage computation" << endl;
   srand(time(NULL));

	int empRatePerHour = 20, partTime = 1, fullTime = 2;
   int empStatus, empWage, empHrs;
   empStatus = rand() % 3;

   if (empStatus == fullTime) {
      cout << "Employee is full time present" <<endl;
		empHrs = 8;
	} else if (empStatus == partTime) {
		cout << "Employee is part time present" <<endl;
		empHrs = 4;
   } else {
      cout << "Employee is absent" <<endl;
		empHrs = 0;
   }
	empWage = empHrs * empRatePerHour;
	cout << "Employee wage is " <<empWage <<endl;
   return 0;
}
