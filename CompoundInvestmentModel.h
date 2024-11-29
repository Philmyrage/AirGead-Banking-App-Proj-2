/*
	Created By: Phillip Wood
	Date: 11/28/2024
	https://github.com/Philmyrage/AirGead-Banking-App-Proj-2
*/
#pragma once

#include "UserInput.h"

#include <memory>
#include <vector>

class CompoundInvestmentModel
{
public:
	//Constructors
	CompoundInvestmentModel()
	{
		iniInvestAmount = 0;
		monthlyDeposit = 0;
		monthlyRate = 0;
		months = 0;
	}
	CompoundInvestmentModel(double iniInvestAmount, double monthlyDeposit, double annualIntrestRate, int months)
	{
		this->monthlyRate = annualIntrestRate / 12.0 / 100.0;
		this->iniInvestAmount = iniInvestAmount;
		this->monthlyDeposit = monthlyDeposit;
		this->months = months;
		
		yearEndBalanceAmounts.resize(months / 12);
		endEarnedInterestAmounts.resize(months / 12);
		endEarnedInterestAmtWoutDeposits.resize(months / 12);
		yearEndBalanceWithOutDeposits.resize(months / 12);
		yearlyClosingBalancesWithDeposits.resize(months / 12);
		yearlyClosingBalancesWithoutDeposits.resize(months / 12);
	}
	CompoundInvestmentModel(std::unique_ptr<UserInput> input): input(std::move(input))
	{
		this->monthlyRate = this->input->monthlyRate / 12.0 / 100.0;
		this->iniInvestAmount = this->input->iniInvestAmount;
		this->monthlyDeposit = this->input->monthlyDeposit;
		this->months = this->input->months;

		yearEndBalanceAmounts.resize(months / 12);
		endEarnedInterestAmounts.resize(months / 12);
		endEarnedInterestAmtWoutDeposits.resize(months / 12);
		yearEndBalanceWithOutDeposits.resize(months / 12);
		yearlyClosingBalancesWithDeposits.resize(months / 12);
		yearlyClosingBalancesWithoutDeposits.resize(months / 12);
	}

	//Getters/Setters
	inline const double getIniinvestAmount(){return iniInvestAmount;}
	inline const double getMonthlyDepost(){return monthlyDeposit;}
	inline const double getAnnualIntrestRate(){return monthlyRate;}
	inline const int getNumOfYears(){return months / 12;}

	inline const double getEndYearBalance(int year){return yearEndBalanceAmounts.at(year) + endEarnedInterestAmounts.at(year);}

	inline const std::vector<double> getYearEndBalanceAmounts(){return yearEndBalanceAmounts;}
	inline const std::vector<double> getEarnedIntrestAmounts(){return endEarnedInterestAmounts;}
	inline const std::vector<double> getEndBalanceWithoutDeposits(){return yearEndBalanceWithOutDeposits;}
	inline const std::vector<double> getEndEarnedInterestAmtWoutDeposits(){return endEarnedInterestAmtWoutDeposits;}
	inline const std::vector<double> getClosingBalancesNoDeposits(){return yearlyClosingBalancesWithoutDeposits;}
	inline const std::vector<double> getClosingBalancesWithdeposits(){return yearlyClosingBalancesWithDeposits;}

	inline void setIniInvestAmount(double amount){iniInvestAmount = amount;}
	inline void setMonthlyDeposit(double amount){monthlyDeposit = amount;}
	inline void setAnnualIntrestRate(double amount){monthlyRate = amount;}
	inline void setNumOfYears(unsigned amount){months = amount;}

	//this function performs the necessary calculations for the investment model.
	void calculateInvestment();


protected:

private:

	//User Input Variables.
	double iniInvestAmount;
	double monthlyDeposit;
	double monthlyRate;
	int months;

	std::unique_ptr<UserInput> input = nullptr;

	//Calculated Amounts
	std::vector<double> yearEndBalanceAmounts;
	std::vector<double> endEarnedInterestAmounts;
	std::vector<double> endEarnedInterestAmtWoutDeposits;
	std::vector<double> yearEndBalanceWithOutDeposits;
	std::vector<double> yearlyClosingBalancesWithoutDeposits;
	std::vector<double> yearlyClosingBalancesWithDeposits;

	//Calculation helper Functions
	void calculateWithDeposit();

	void calculateWithoutDeposit();

	void calculateClosingBalance();

	void calculateWithDepositTest();
};

