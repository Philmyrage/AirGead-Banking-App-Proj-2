/*
	Created By: Phillip Wood
	Date: 11/28/2024
	https://github.com/Philmyrage/AirGead-Banking-App-Proj-2
*/
#pragma once

#include "UserInput.h"

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
		
		yearEndBalanceAmounts.resize(months / 12);
		endEarnedInterestAmounts.resize(months / 12);
		endEarnedInterestAmtWoutDeposits.resize(months / 12);
		yearEndBalanceWithOutDeposits.resize(months / 12);
	}
	CompoundInvestmentModel(UserInput* input) : input(input)
	{
		this->annualIntrestRate = (input->annualIntrestRate / 100) / 12;
		this->iniInvestAmount = input->iniInvestAmount;
		this->monthlyDeposit = input->monthlyDeposit;
		this->months = input->months;

		yearEndBalanceAmounts.resize(months / 12);
		endEarnedInterestAmounts.resize(months / 12);
		endEarnedInterestAmtWoutDeposits.resize(months / 12);
		yearEndBalanceWithOutDeposits.resize(months / 12);
	}

	//Getters/Setters
	inline const double getIniinvestAmount(){return iniInvestAmount;}
	inline const double getMonthlyDepost(){return monthlyDeposit;}
	inline const double getAnnualIntrestRate(){return annualIntrestRate;}
	inline const int getNumOfYears(){return months / 12;}

	inline const double getEndYearBalance(int year){return yearEndBalanceAmounts.at(year) + endEarnedInterestAmounts.at(year);}
	inline const double getClosingBalance(){return closingBalance;}

	inline const std::vector<double> getYearEndBalanceAmounts(){return yearEndBalanceAmounts;}
	inline const std::vector<double> getEarnedIntrestAmounts(){return endEarnedInterestAmounts;}
	inline const std::vector<double> getEndBalanceWithoutDeposits(){return yearEndBalanceWithOutDeposits;}
	inline const std::vector<double> getEndEarnedInterestAmtWoutDeposits(){return endEarnedInterestAmtWoutDeposits;}

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

	UserInput* input = nullptr;

	//Calculated Amounts

	double closingBalance = 0.0;

	std::vector<double> yearEndBalanceAmounts;
	std::vector<double> endEarnedInterestAmounts;
	std::vector<double> endEarnedInterestAmtWoutDeposits;
	std::vector<double> yearEndBalanceWithOutDeposits;

	//Calculation helper Functions
	void calculateWithDeposit();

	void calculateWithoutDeposit();

	void calculateClosingBalance();

};

