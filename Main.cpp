/* Developer: Valerie Meiners
 * Date: July 24, 2023
 * Program: Airgead Banking App
 */

#include <iostream>
#include <string>
#include <iomanip>
#include "InvestmentInterest.h"
using namespace std;

int main() {
	InvestmentInterest newInvestment; // object of InvestmentInterest class

	// initialize variables
	double initialInvestment{ 0 }; 
	double monthlyDeposit{ 0 };
	double interestRate{ 0 };
	int numYears{ 0 };
	string userInput; 

	// do-while loop to prompt for user input
	do {
		cout << "Enter initial investment amount: " << endl;
		cin >> initialInvestment;
		newInvestment.setInitialInvestment(initialInvestment);

		cout << "Enter monthly deposit: " << endl;
		cin >> monthlyDeposit;
		newInvestment.setMonthlyDeposit(monthlyDeposit);

		cout << "Enter interest rate: " << endl;
		cin >> interestRate;
		newInvestment.setInterestRate(interestRate);

		cout << "Enter number of years: " << endl;
		cin >> numYears;
		newInvestment.setNumYears(numYears);

		// display data input
		newInvestment.dataMenu();

		// prompt user to calculate balances
		cout << "Press any key to continue..." << endl;
		cout << endl;

		// display balance with additional deposits and without additional deposits
		newInvestment.displayBalanceWithDeposits();
		newInvestment.displayBalanceNoDeposits();

		// prompt user to calculate another investment
		cout << "Calculate another investment? y/n?" << endl;
		cin >> userInput;

	} while (userInput != "n"); // exit loop and close program

	return 0;
}
