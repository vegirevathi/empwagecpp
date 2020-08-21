#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <unistd.h>
using namespace std;

struct Company
{
	string companyName;
	int numOfWorkingDays;
	int maxHrsInMonth;
	int empRatePerHrs;
	int numOfEmployees;
	int numOfMonths;


public:
	void setCompanyDetails(string companyName, int numOfWorkingDays, int maxHrsInMonth, int empRatePerHrs, int numOfEmployees, int numOfMonths)
	{
			this -> companyName = companyName;
			this -> numOfWorkingDays = numOfWorkingDays;
			this -> maxHrsInMonth = maxHrsInMonth;
			this -> empRatePerHrs = empRatePerHrs;
			this -> numOfEmployees = numOfEmployees;
			this -> numOfMonths = numOfMonths;
	}
};

void write(vector <int>, int, int, int, string);

struct EmployeeWageBuilder
{
	int getWorkingHours(Company);
	void queryTotalWage(Company, string);

	int computeEmpWage(Company company)
	{
		return getWorkingHours(company) * company.empRatePerHrs;
	}
};

void EmployeeWageBuilder::queryTotalWage(Company company, string searchCompany)
{
	int totalCompanyWage = 0;
	int result = searchCompany.compare(company.companyName);
	if (result == 0) {
	for(int employee = 1; employee <= company.numOfEmployees; employee++)
	{
		for(int month = 1; month <= company.numOfMonths; month++)
		{
			for(int day = 1; day <= company.numOfWorkingDays; day++)
			{
				int dailyWage = getWorkingHours(company) * company.empRatePerHrs;
				totalCompanyWage += dailyWage;
			}
		}
	}
	cout <<"Total Company Wage is : " << totalCompanyWage;
	}
	else
	{
		cout << "No company found" <<endl;
	}
}



int EmployeeWageBuilder::getWorkingHours(Company company)
{
	int numOfWorkingDays = company.numOfWorkingDays;
	int maxHrsInMonth = company.maxHrsInMonth;

	const int FULL_TIME = 1;
	const int PART_TIME = 2;
   int empStatus, empHrs=0, totalEmpHrs = 0, totalWorkingDays = 0;

   srand(time(NULL));
while (totalEmpHrs <= maxHrsInMonth && totalWorkingDays <= numOfWorkingDays) {
	totalWorkingDays++;
   empStatus = rand() % 3;

	switch (empStatus) {
   case FULL_TIME:
				empHrs = 8;
				break;

	case PART_TIME:
				empHrs = 4;
				break;

   default:
				empHrs = 0;
				break;
	   }
	}
	return empHrs;
}

void computeEmpWage(struct Company company)
{
	struct EmployeeWageBuilder employeeWageBuilder;
	int totalMonthlyWage = 0;
	vector <int> wages;

	for(int id = 1; id <= company.numOfEmployees; id++)
	{
		for(int month = 1; month <= company.numOfMonths; month++)
		{
			for (int day = 1; day <= company.numOfWorkingDays; day++)
			{
				int dailyEmpWage = employeeWageBuilder.computeEmpWage(company);
				wages.push_back(dailyEmpWage);

				totalMonthlyWage += dailyEmpWage;
				sleep(2);

				cout << company.companyName << " -- Employee ID : " << id << "    Day : " << day << "    Month : " << month <<"   daily Salary : " << dailyEmpWage <<"   monthly salary: " <<totalMonthlyWage <<endl;
			}
			totalMonthlyWage = 0;
		}

		write(wages, id, company.numOfWorkingDays, company.numOfMonths, company.companyName);
	}
}

void write(vector <int> wages, int employeeID, int numOfWorkingDays, int numOfMonths, string companyName)
{
	fstream myfile;
	myfile.open("Wages.csv", ios::out | ios::app);
	myfile.seekg(0, ios::end);

	if (myfile.is_open())
	{
		if(myfile.tellp() ==0)
		{
			myfile << "Company, Employee, month, Day, dailyWage, monthlyWage" <<endl;
		}

		myfile.seekg(0, ios::beg);
		for(int month = 1; month <= numOfMonths; month++)
		{
			for(int day = 1; day <= numOfWorkingDays; day++)
			{
				wages[month] += wages[day];
				myfile << companyName << ", Employee_" << employeeID << ", " << month << ", " << day << ", " << wages[day] << ", " << wages[month] <<endl;
			}
			wages[month] = 0;
		}
	}
	myfile.close();
}

int main()
{
	cout << "Welcome to Employee wage computation" << endl;

	struct Company company;
	string searchName;
	struct EmployeeWageBuilder employeeWageBuilder;

	company.setCompanyDetails("DMART", 4, 100, 20, 3, 3);
	computeEmpWage(company);
	company.setCompanyDetails("Reliance", 5, 80, 40, 2, 3);
	computeEmpWage(company);

	cout<<"Enter the company name you want to search" <<endl;
	cin >> searchName;
	employeeWageBuilder.queryTotalWage(company, searchName);

	return 0;
}
