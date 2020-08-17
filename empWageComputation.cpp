#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	cout << "Welcome to Employee wage computation" << endl;
   srand(time(NULL));

   int empStatus;
   empStatus = rand() % 2;

   if (empStatus == 1) {
      cout << "Employee is present" <<endl;
   } else {
      cout << "Employee is absent" <<endl;
   }
   return 0;
}
