#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <unistd.h>
using namespace std;

vector <int> employeeID;

int computeEmpWage() {
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
	cout << "Total employee wage is " << totalEmpWage <<endl;

	return totalEmpWage;
}

void write(string fileName) {
	fstream myfile;
	myfile.open(fileName, ios::out | ios::trunc);

	if (myfile.is_open()) {
		myfile << "Employee ID, Monthly Wage\n";

		for (int i = 0; i < employeeID.size(); i++)
		{
			myfile << (i + 1) << ", " << (employeeID[i]) <<endl;
		}
	}
	myfile.close();
}

int main() {
	int totalEmployees;

	cout << "Enter no of employees : " <<endl;
	cin >> totalEmployees;

	for (int i = 0; i < totalEmployees; i++)
	{
		int empWage = computeEmpWage();
		employeeID.push_back(empWage);
	}
	write("wages.txt");
}
