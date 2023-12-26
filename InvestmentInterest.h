#ifndef INVESTMENT_INTEREST
#define INVESTMENT_INTEREST

#include <string>
#include <iomanip>

class InvestmentInterest { // create class
private: // declare private access specifier

	// declare private attributes
	double m_initialInvestment = 0;
	double m_monthlyDeposit = 0;
	double m_interestRate = 0;
	int m_numYears = 0;

public: // declare public access specifier

	// declare public attributes
	void displayChar(char a, int b);
	void dataMenu();
	double earnedInterest();
	void yearEndBalanceWithDeposits();
	void yearEndBalanceNoDeposits();
	void displayBalanceNoDeposits();
	void displayBalanceWithDeposits();

	double setInitialInvestment(double t_initialInvestment);
	double getInitialInvestment();
	double setMonthlyDeposit(double t_monthlyDeposit);
	double getMonthlyDeposit();
	double setInterestRate(double t_interestRate);
	double getInterestRate(double t_interestRate);
	int setNumYears(int t_numYears);
	int getNumYears();
};

#endif