/*
	Created By: Phillip Wood
	Date: 11/28/2024
	https://github.com/Philmyrage/AirGead-Banking-App-Proj-2
*/
#include "CompoundInvestmentModel.h"

#include <iostream>

void CompoundInvestmentModel::calculateInvestment()
{
	calculateWithDeposit();
	calculateWithoutDeposit();
}

void CompoundInvestmentModel::calculateWithDeposit()
{
	int count = 0;
	double total = iniInvestAmount;
	double interest = 0.0;
	double yrEndEarnedInterest = 0.0;
	double closingBalance = 0.0;

	//for every month we add the deposit and calculate the interest.
	for (int i = 1; i <= months; ++i)
	{
		// add the deposit
		total = (total + monthlyDeposit);
		//calculate the interest
		interest = (total * annualIntrestRate);
		yrEndEarnedInterest += interest;

		//add the total and interest
		closingBalance = total + interest;
		//for every year we add those values to a vector to print to our user.
		if (i % 12 == 0)
		{
			yearEndBalanceAmounts.at(count) = total;
			endEarnedInterestAmounts.at(count) = yrEndEarnedInterest;
			yearlyClosingBalancesWithDeposits.at(count) = closingBalance;
			yrEndEarnedInterest = 0.0;
			count++;
		}

		//total is equal to closing balance of the previous year....
		total = closingBalance;
	}

	////for every month we add the deposit and calculate the interest.
	//for (int i = 1; i <= months; ++i)
	//{
	//	total = (total + monthlyDeposit) + (total * annualIntrestRate);
	//	interest = (total * annualIntrestRate);
	//	yrEndEarnedInterest += interest;
	//	//for every year we add those values to a vector to print to our user.
	//	if (i % 12 == 0)
	//	{ 
	//		yearEndBalanceAmounts.at(count) = total + interest;
	//		endEarnedInterestAmounts.at(count) = yrEndEarnedInterest;
	//		yrEndEarnedInterest = 0.0;
	//		count++;
	//	}
	//}
}

void CompoundInvestmentModel::calculateWithoutDeposit()
{
	int count = 0;
	double total = iniInvestAmount;
	double interest = 0.0;
	double yrEndEarnedInterest = 0.0;
	
	double closingTotal = 0.0;
	
	//for every month we add the deposit and calculate the interest.
	for (int i = 1; i <= months; ++i)
	{
		closingTotal += (total * annualIntrestRate);
		interest = (closingTotal * annualIntrestRate);
		yrEndEarnedInterest += interest;
		//for every year we add those values to a vector to print to our user.
		if (i % 12 == 0)
		{
			
			yearEndBalanceWithOutDeposits.at(count) = total;
			endEarnedInterestAmtWoutDeposits.at(count) = yrEndEarnedInterest;
			yrEndEarnedInterest = 0.0;
			count++;
		}
	}
	
}

void CompoundInvestmentModel::calculateClosingBalance()
{
	
}
