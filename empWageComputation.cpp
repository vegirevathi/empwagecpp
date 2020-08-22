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
		cout <<"Total Company Wage is : " << totalCompanyWage << endl;
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

void bubbleSort(int *, int);
void display(int *, int);

void computeEmpWage(struct Company company)
{
	struct EmployeeWageBuilder employeeWageBuilder;
	int totalMonthlyWage = 0;
	vector <int> wages;

   int n = company.numOfMonths * company.numOfEmployees;
   int a = 0;
   int array[n];

 int nDay = company.numOfMonths * company.numOfEmployees * company.numOfWorkingDays;
   int b = 0;
   int arrayDay[nDay];


	for(int id = 1; id <= company.numOfEmployees; id++)
	{
		for(int month = 1; month <= company.numOfMonths; month++)
		{
			for (int day = 1; day <= company.numOfWorkingDays; day++)
			{
				int dailyEmpWage = employeeWageBuilder.computeEmpWage(company);
				wages.push_back(dailyEmpWage);
				arrayDay[b] = dailyEmpWage;
				b++;

				totalMonthlyWage += dailyEmpWage;
				sleep(2);

				cout << company.companyName << " -- Employee ID : " << id << "    Day : " << day << "    Month : " << month <<"   daily Salary : " << dailyEmpWage <<"   monthly salary: " <<totalMonthlyWage <<endl;
			}
			cout << "=============================";
			cout << "monthly wages :" << totalMonthlyWage << endl;
			array[a] = totalMonthlyWage;
			a++;
			totalMonthlyWage = 0;
		}

		write(wages, id, company.numOfWorkingDays, company.numOfMonths, company.companyName);
	}
	cout << endl;
	cout << "All the monthly wages data for " << company.companyName << "are : " << endl;

	display(array, n);
	bubbleSort(array, n);

   cout << "Array after sorting " << endl;
   display(array, n);

	cout << endl;
	cout << endl;

	cout << "All the daily wage data for " << company.companyName << " are : " << endl;
	display(arrayDay, n);

	bubbleSort(arrayDay, n);
	cout << "daily wages data after sorting " << endl;
	display(arrayDay, n);
}

void bubbleSort(int *array, int n) {
   int i, j, temp, pass = 0;
   for (i = 0; i < n; i++) {
      for (j = i+1; j < n; j++) {
         if (array[i] > array[j]) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
         }
      }
   }
}

void display(int *array, int n) {
   for (int i = 0; i < n; i++)
      cout << array[i] << " ";
   cout << endl;
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
	int option;
	struct EmployeeWageBuilder employeeWageBuilder;
	while(int choice = 1)
	{
		cout << "Enter 1 to display the company data" << endl;
		cout << "Enter 2 to calculate company total wage" << endl;
		cout << "Enter 3 to sort by monthly wage" << endl;

		cin >> option;
		switch(option) {
			case 1:
				company.setCompanyDetails("DMART", 3, 100, 20, 3, 3);
				computeEmpWage(company);
				company.setCompanyDetails("Reliance", 3, 80, 40, 3, 3);
				computeEmpWage(company);
				break;
			case 2:
				cout<<"Enter the company name you want to search" <<endl;
				cin >> searchName;
				employeeWageBuilder.queryTotalWage(company, searchName);
				break;
			default :
				cout << "Enter correct option" << endl;
				break;
		}
	}

	return 0;
}
