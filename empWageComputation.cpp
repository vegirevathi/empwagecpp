#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

void write(int);

int main() {
	cout << "Welcome to Employee wage computation" << endl;
   srand(time(NULL));

	int empRatePerHour = 20;
	int numOfWorkingDays = 20;
	int maxHrsInMonth = 100;
	int partTime = 1;
	int fullTime = 2;
   int empStatus, empWage, empHrs, totalEmpWage = 0, totalEmpHrs = 0, totalWorkingDays = 0;

while (totalEmpHrs <= maxHrsInMonth && totalWorkingDays <= numOfWorkingDays) {
	totalWorkingDays++;
   empStatus = rand() % 3;
	switch (empStatus) {
   case 1:
      cout <<"DAY" <<totalWorkingDays <<" : Employee is full time present" <<endl;
		empHrs = 8;
		break;
	case 2:
		cout <<"DAY" <<totalWorkingDays <<" : Employee is part time present" <<endl;
		empHrs = 4;
		break;
   default:
      cout <<"DAY" <<totalWorkingDays <<" : Employee is absent"<<endl;
		empHrs = 0;
		break;
   }
	totalEmpHrs += empHrs;
	}
	totalEmpWage = totalEmpHrs * empRatePerHour;
	cout << "Total employee wage is " <<totalEmpWage <<endl;

	write(totalEmpWage);
   return 0;
}

void write(int totalEmpWage) {
	ofstream myfile ("wages.txt");
	if (myfile.is_open()) {
		myfile <<"Total employee wage for the month is " <<totalEmpWage;
		myfile.close();
	}
}
