#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	cout << "Welcome to Employee wage computation" << endl;
   srand(time(NULL));

	int empRatePerHour = 20;
	int numOfWorkingDays = 20;
	int partTime = 1;
	int fullTime = 2;
   int empStatus, empWage, empHrs, totalEmpWage = 0;

for (int day = 1; day <= numOfWorkingDays; day++) {
   empStatus = rand() % 3;
	switch (empStatus) {
   case 1:
      cout <<"DAY" <<day <<" : Employee is full time present" <<endl;
		empHrs = 8;
		break;
	case 2:
		cout <<"DAY" <<day <<" : Employee is part time present" <<endl;
		empHrs = 4;
		break;
   default:
      cout <<"DAY" <<day <<" : Employee is absent"<<endl;
		empHrs = 0;
		break;
   }
	empWage = empHrs * empRatePerHour;
	totalEmpWage += empWage;
	}
	cout << "Total employee wage is " <<totalEmpWage <<endl;
   return 0;
}
