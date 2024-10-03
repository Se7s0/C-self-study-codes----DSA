#pragma once

#include <string>
using namespace std;

class Employee {

	public:
		Employee(string firstName, string lastName, int monthlySalary)
			: firstName{ firstName }, lastName{ lastName }
		{
			if (monthlySalary > 0) {
				this->monthlySalary = monthlySalary;
			}
		}

		void setFirstName(string firstName) {
			this->firstName = firstName;
		}

		void setLastName(string lastName) {
			this->lastName = lastName;
		}

		void setMonthlySalary(int monthlySalary) {
			this->monthlySalary = monthlySalary;
		}

		string getFirstName() {
			return firstName;
		}	

		string getLastName() {
			return lastName;
		}	

		int getMonthlySalary() {
			return monthlySalary;
		}
	
	private:
		string firstName;
		string lastName;
		int monthlySalary{ 0 };

};