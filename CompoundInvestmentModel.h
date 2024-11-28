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
		months = 0;
	}
	CompoundInvestmentModel(double iniInvestAmount, double monthlyDeposit, double annualIntrestRate, int months)
	{
		this->annualIntrestRate = (annualIntrestRate / 100) / 12;
		this->iniInvestAmount = iniInvestAmount;
		this->monthlyDeposit = monthlyDeposit;
		this->months = months;
		
		//TODO: change this for when i Handle months in input...
		yearEndBalanceAmounts.resize(months / 12);
		endEarnedInterestAmounts.resize(months / 12);
		endEarnedInterestAmtWoutDeposits.resize(months / 12);
		yearEndBalanceWithOutDeposits.resize(months / 12);
	}

	//Getters/Setters
	inline double getIniinvestAmount(){return iniInvestAmount;}
	inline double getMonthlyDepost(){return monthlyDeposit;}
	inline double getAnnualIntrestRate(){return annualIntrestRate;}
	inline unsigned getNumOfYears(){return months / 12;}

	inline double getEndYearBalance(int year){return yearEndBalanceAmounts.at(year) + endEarnedInterestAmounts.at(year);}
	inline double getClosingBalance(){return closingBalance;}

	inline std::vector<double> getYearEndBalanceAmounts(){return yearEndBalanceAmounts;}
	inline std::vector<double> getEarnedIntrestAmounts(){return endEarnedInterestAmounts;}
	inline std::vector<double> getEndBalanceWithoutDeposits(){return yearEndBalanceWithOutDeposits;}
	inline std::vector<double> getEndEarnedInterestAmtWoutDeposits(){return endEarnedInterestAmtWoutDeposits;}

	inline void setIniInvestAmount(double amount){iniInvestAmount = amount;}
	inline void setMonthlyDeposit(double amount){monthlyDeposit = amount;}
	inline void setAnnualIntrestRate(double amount){annualIntrestRate = amount;}
	inline void setNumOfYears(unsigned amount){months = amount;}

	//Calculation Function for interest and balance.

	//this function performs the necessary calculations for the investment model.
	void calculateInvestment();


protected:

private:

	//User Input Variables.
	double iniInvestAmount;
	double monthlyDeposit;
	double annualIntrestRate;
	int months;

	//Calculated Amounts

	double closingBalance = 0.0;

	std::vector<double> yearEndBalanceAmounts;
	std::vector<double> endEarnedInterestAmounts;
	std::vector<double> endEarnedInterestAmtWoutDeposits;
	std::vector<double> yearEndBalanceWithOutDeposits;

	//Calculation helper Functions for interest and balance.

	//This function takes the previous years amount and calculates the next years end balance.
	void calculateWithDeposit();

	void calculateWithoutDeposit();

	double calculateYearEndBalanceWithoutDeposit(double amount, int lengthOfTime);

	//this function returns the Earned compounded interest of the amount given.
	double calculateEndEarnedInterest(double amount, bool withDeposit);

	double calculateClosingBalance();

	double calculateCompoundInterest(double amount, bool withoutDeposit, int lengthOfInvestment = 1);
};

