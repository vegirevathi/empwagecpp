#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <unistd.h>
using namespace std;

struct Company {
	string companyName;
	int numOfWorkingDays;
	int maxHrsInMonth;
	int empRatePerHrs;
public:
	void setCompanyDetails(string companyName, int numOfWorkingDays, int maxHrsInMonth, int empRatePerHrs) {
			this -> companyName = companyName;
			this -> numOfWorkingDays = numOfWorkingDays;
			this -> maxHrsInMonth = maxHrsInMonth;
			this -> empRatePerHrs = empRatePerHrs;
	}
};

void write(vector <int>, int, int, string);

int getWorkingHours(struct Company company) {
   srand(time(NULL));

	int numOfWorkingDays = company.numOfWorkingDays;
	int maxHrsInMonth = company.maxHrsInMonth;

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
	return totalEmpHrs;
}

void computeEmpWage(struct Company company, int numOfEmployees, int numOfMonths) {
	int empRatePerHour = company.empRatePerHrs;
	for(int i = 1; i <= numOfEmployees; i++) {
		vector <int> monthlyWage;
		for(int j = 1; j <= numOfMonths; j++) {

			int totalEmpWage = getWorkingHours(company) * empRatePerHour;
			monthlyWage.push_back(totalEmpWage);
			cout << "Employee ID : " << i << " Month : " << j <<" Salary : " << totalEmpWage <<endl;
		}

	write(monthlyWage, i, numOfMonths, company.companyName);
	}
}

void write(vector <int> wages, int employeeID, int numOfMonths, string companyName) {
	fstream myfile;
	myfile.open("Wages.csv", ios::out | ios::app);
	myfile.seekg(0, ios::end);

	if (myfile.is_open())
	{
		if(myfile.tellp() ==0)
		{
			myfile << "Company, Employee";
			for (int month = 1; month <= 12; month++)
			{
				myfile << ", Month " << month;
			}
		}

		myfile.seekg(0, ios::beg);
		myfile << "\n" << companyName << ", Employee " << employeeID;
		for(int month = 0; month < numOfMonths; month++)
		{
			myfile << ", " << wages[month];
		}
	}

	myfile.close();
}

int main() {
	cout << "Welcome to Employee wage computation" << endl;

	struct Company company;
	company.setCompanyDetails("DMART", 20, 100, 20);
	computeEmpWage(company, 3, 12);
	company.setCompanyDetails("Reliance", 25, 80, 40);
	computeEmpWage(company, 2, 12);

	return 0;

}
