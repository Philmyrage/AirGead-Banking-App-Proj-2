#pragma once

#include <vector>

class CompoundInvestmentModel
{
public:
	//Constructors
	CompoundInvestmentModel()
	{
		iniInvestAmount = 0;
		monthlyDeposit = 0;
		annualIntrestRate = 0;
		numOfYears = 0;
	}
	CompoundInvestmentModel(double iniInvestAmount, double monthlyDeposit, double annualIntrestRate, unsigned numOfYears)
	{
		this->annualIntrestRate = annualIntrestRate;
		this->iniInvestAmount = iniInvestAmount;
		this->monthlyDeposit = monthlyDeposit;
		this->numOfYears = numOfYears;
		
		//TODO: change this for when i Handle months in input...
		yearEndBalanceAmounts.resize(numOfYears);
		endEarnedInterestAmounts.resize(numOfYears);
		endEarnedInterestAmtWoutDeposits.resize(numOfYears);
		yearEndBalanceWithOutDeposits.resize(numOfYears);
	}

	//Getters/Setters
	inline double getIniinvestAmount(){return iniInvestAmount;}
	inline double getMonthlyDepost(){return monthlyDeposit;}
	inline double getAnnualIntrestRate(){return annualIntrestRate;}
	inline unsigned getNumOfYears(){return numOfYears;}

	inline std::vector<double> getYearEndBalanceAmounts(){return yearEndBalanceAmounts;}
	inline std::vector<double> getEarnedIntrestAmounts(){return endEarnedInterestAmounts;}
	inline std::vector<double> getEndBalanceWithoutDeposits(){return yearEndBalanceWithOutDeposits;}
	inline std::vector<double> getEndEarnedInterestAmtWoutDeposits(){return endEarnedInterestAmtWoutDeposits;}

	inline void setIniInvestAmount(double amount){iniInvestAmount = amount;}
	inline void setMonthlyDeposit(double amount){monthlyDeposit = amount;}
	inline void setAnnualIntrestRate(double amount){annualIntrestRate = amount;}
	inline void setNumOfYears(unsigned amount){numOfYears = amount;}

	//Calculation Function for interest and balance.

	//this function performs the necessary calculations for the investment model.
	void calculateInvestment();


protected:

private:

	//User Input Variables.
	double iniInvestAmount;
	double monthlyDeposit;
	double annualIntrestRate;
	unsigned numOfYears;

	//Calculated Amounts
	std::vector<double> yearEndBalanceAmounts;
	std::vector<double> endEarnedInterestAmounts;
	std::vector<double> endEarnedInterestAmtWoutDeposits;
	std::vector<double> yearEndBalanceWithOutDeposits;

	//Calculation helper Functions for interest and balance.

	//This function takes the previous years amount and calculates the next years end balance.
	double calculateYearEndBalance(double amount);

	double calculateYearEndBalanceWithoutDeposit(double amount);

	//this function returns the Earned compounded interest of the amount given.
	double calculateEndEarnedInterest(double amount, bool withDeposit);
};

