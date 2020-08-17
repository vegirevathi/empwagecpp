#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	cout << "Welcome to Employee wage computation" << endl;
   srand(time(NULL));

	int empRatePerHour = 20, empWage, empHrs;
   int empStatus;
   empStatus = rand() % 2;

   if (empStatus == 1) {
      cout << "Employee is present" <<endl;
		empHrs = 8;
   } else {
      cout << "Employee is absent" <<endl;
		empHrs = 0;
   }
	empWage = empHrs * empRatePerHour;
	cout << "Employee wage is " <<empWage <<endl;
   return 0;
}
