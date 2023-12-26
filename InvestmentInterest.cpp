#include <iostream>
#include <iomanip>
#include <string>
#include "InvestmentInterest.h"
using namespace std;

// accessors and mutators
double InvestmentInterest::setInitialInvestment(double t_initialInvestment) { // t_ prefix for function parameters
	m_initialInvestment = t_initialInvestment;
	return m_initialInvestment; // m_ prefix for private "member" data
}

double InvestmentInterest::getInitialInvestment() {
	return m_initialInvestment;
}

double InvestmentInterest::setMonthlyDeposit(double t_monthlyDeposit) {
	m_monthlyDeposit = t_monthlyDeposit;
	return m_monthlyDeposit;
}

double InvestmentInterest::getMonthlyDeposit() {
	return m_monthlyDeposit;
}

double InvestmentInterest::setInterestRate(double t_interestRate) {
	m_interestRate = t_interestRate;
	return m_interestRate;
}

double InvestmentInterest::getInterestRate(double t_interestRate) {
	return t_interestRate;
}

int InvestmentInterest::setNumYears(int t_numYears) {
	m_numYears = t_numYears;
	return m_numYears;
}

int InvestmentInterest::getNumYears() {
	return m_numYears;
}

// function for menu display characters
void InvestmentInterest::displayChar(char a, int b) {
	cout << string(a, b) << endl;
}

// function for user input, output in display menu
void InvestmentInterest::dataMenu() {
	displayChar(34, '*');
	cout << "************DATA INPUT************" << endl;
	cout << "Initial Investment Amount: $" << m_initialInvestment << endl;
	cout << "Monthly Deposit: $" << m_monthlyDeposit << endl;
	cout << "Annual Interest: %" << m_interestRate << endl;
	cout << "Number of Years: " << m_numYears << endl;
}

// function for earned interest calculation
double InvestmentInterest::earnedInterest() {
	double earnedInterest = 0;
	double newBalance = m_initialInvestment;

	for (int i = 1; i <= m_numYears; ++i) {
		for (int month = 1; month <= 12; ++month) {
			newBalance += m_monthlyDeposit;
			double monthlyInterest = newBalance * (m_interestRate / 100.0) / 12.0;
			newBalance += monthlyInterest;
		}
		earnedInterest += newBalance - (m_initialInvestment + (m_monthlyDeposit * 12));
	}
	return earnedInterest;
}

// function for year end balance with additional deposits calculation
void InvestmentInterest::yearEndBalanceWithDeposits() {
	const int COMPOUNDFREQ = 12;
	double annualInterestRate = (m_interestRate / 100.0);
	double currentBalance = m_initialInvestment;

	for (int year = 1; year <= m_numYears; ++year) {
		double totalInterest = 0.0;
		for (int month = 1; month <= COMPOUNDFREQ; ++month) {
			double monthlyInterest = (currentBalance + m_monthlyDeposit) * (annualInterestRate / COMPOUNDFREQ);
			totalInterest += monthlyInterest;
			currentBalance += m_monthlyDeposit + monthlyInterest;
		}
		// set precision to set output to two decimal places
		cout << fixed << setprecision(2) << "   " << year << "                  " << currentBalance << "                      " << currentBalance - m_initialInvestment << endl;
	}
}

// function for year end balance without additional deposits calculation
void InvestmentInterest::yearEndBalanceNoDeposits() {
	const int COMPOUNDFREQ = 12;
	double annualInterestRate = (m_interestRate / 100.0);
	double currentBalance = m_initialInvestment;

	for (int year = 1; year <= m_numYears; ++year) {
		double totalInterest = 0.0;
		for (int month = 1; month <= COMPOUNDFREQ; ++month) {
			double monthlyInterest = (currentBalance) * (annualInterestRate / COMPOUNDFREQ);
			totalInterest += monthlyInterest;
			currentBalance += monthlyInterest;
		}
		// set precision to set output to two decimal places
		cout << fixed << setprecision(2) << "   " << year << "                    " << currentBalance << "                      " << currentBalance - m_initialInvestment << endl;
	}
}

// function to display result of calculation for year end balance with additional deposits
void InvestmentInterest::displayBalanceWithDeposits() {
	cout << "    Balance and Interest With Additional Monthly Deposits" << endl;
	displayChar(65, '=');
	displayChar(65, '-');
	cout << "  Year" << "         " << "Year End Balance" << "         " << "Year End Earned Interest" << endl;
	yearEndBalanceWithDeposits();
	cout << endl;
}

// function to display result of calculation for year end balance without additional deposits
void InvestmentInterest::displayBalanceNoDeposits() {
	cout << "    Balance and Interest Without Additional Monthly Deposits" << endl;
	displayChar(65, '=');
	displayChar(65, '-');
	cout << "  Year" << "         " << "Year End Balance" << "         " << "Year End Earned Interest" << endl;
	yearEndBalanceNoDeposits();
	cout << endl;
}