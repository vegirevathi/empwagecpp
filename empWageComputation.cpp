#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <unistd.h>
using namespace std;

void write(string, string, string, int);

int computeEmpWage(string employeeID, string month) {
   srand(time(NULL));

	int empRatePerHour = 20;
	int numOfWorkingDays = 20;
	int maxHrsInMonth = 100;
	int partTime = 1;
	int fullTime = 2;
   int empStatus, empWage, empHrs=0, totalEmpWage=0, totalEmpHrs = 0, totalWorkingDays = 0;

while (totalEmpHrs <= maxHrsInMonth && totalWorkingDays <= numOfWorkingDays) {
	totalWorkingDays++;
   empStatus = rand() % 3;

	switch (empStatus) {
   case 1:
		//cout <<"DAY" <<totalWorkingDays <<" : Employee is full time present" <<endl;
		empHrs = 8;
		break;

	case 2:
		//cout <<"DAY" <<totalWorkingDays <<" : Employee is part time present" <<endl;
		empHrs = 4;
		break;

   default:
      //cout <<"DAY" <<totalWorkingDays <<" : Employee is absent"<<endl;
		empHrs = 0;
		break;
	   }

	totalEmpHrs += empHrs;
	}

	totalEmpWage = totalEmpHrs * empRatePerHour;
	cout << "Employee ID : " << employeeID << "Month : " << month <<" Salary : " << totalEmpWage <<endl;

	return totalEmpWage;
	write("wages.txt", employeeID, month, totalEmpWage);
}

void write(string filename, string employeeID, string month, int totalEmpWage) {
	fstream myfile;
	myfile.open(filename, ios::out | ios::trunc);

	if (myfile.is_open()) {
		myfile << employeeID << "-----" << month << "-----" << totalEmpWage << endl;
	}

	myfile.close();
}

int main() {
	cout << "Welcome to Employee wage computation" << endl;

	string month[3] = { "Jan", "Feb", "Mar"};
	string employeeNames[4] = { "001", "002", "003", "004" };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3 ; j++)
		{
			string monthName = month[j];
			string employeeID = employeeNames[i];

			computeEmpWage(employeeID, monthName);
		}
	}
}
