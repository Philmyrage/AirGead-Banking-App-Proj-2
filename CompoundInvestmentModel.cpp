/*
	Created By: Phillip Wood
	Date: 11/28/2024
	https://github.com/Philmyrage/AirGead-Banking-App-Proj-2
*/
#include "CompoundInvestmentModel.h"

#include <iostream>
#include <cmath>

void CompoundInvestmentModel::calculateInvestment()
{
	calculateWithDeposit();
	calculateWithoutDeposit();
}

void CompoundInvestmentModel::calculateWithDeposit()
{
	int count = 1;
	double total = iniInvestAmount;
	double interestForMonth = 0.0;
	
	double yrEndEarnedInterest = 0.0;

	if (getNumOfYears() <= 0) return;

	for (int i = 1; i <= getNumOfYears(); ++i)
	{
		for (int k = 1; k <= 12; k++)
		{
			total += monthlyDeposit;
			interestForMonth = total * monthlyRate;
			total += interestForMonth;
			yrEndEarnedInterest += interestForMonth;
		}
		yearEndBalanceAmounts.at(i - 1) = total;
		endEarnedInterestAmounts.at(i - 1) = yrEndEarnedInterest;
		yrEndEarnedInterest = 0.0;
	}
}

void CompoundInvestmentModel::calculateWithoutDeposit()
{
	int count = 0;
	double total = iniInvestAmount;
	double interest = 0.0;
	double yrEndEarnedInterest = 0.0;
	
	double closingBalance = 0.0;
	
	//for every month we add the deposit and calculate the interest.
	for (int i = 1; i <= months; ++i)
	{
		interest = (total * monthlyRate);
		yrEndEarnedInterest += interest;
		closingBalance = (total + interest);

		//for every year we add those values to a vector to print to our user.
		if (i % 12 == 0)
		{
			//if its not the first year get the previous years balance.
			double t = (count == 0) ? iniInvestAmount : total - yrEndEarnedInterest;
			yearEndBalanceWithOutDeposits.at(count) = t;
			endEarnedInterestAmtWoutDeposits.at(count) = yrEndEarnedInterest;
			yrEndEarnedInterest = 0.0;
			count++;
		}
		//The total is equal to that of the previous year.
		total = closingBalance;
	}
	
}

