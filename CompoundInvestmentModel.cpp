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
	for (int i = 1; i <= months; ++i)
	{
		total = (total + monthlyDeposit) + (total * annualIntrestRate);
		interest = (total * annualIntrestRate);
		yrEndEarnedInterest += interest;
		if (i % 12 == 0)
		{ 
			yearEndBalanceAmounts.at(count) = total + interest;
			endEarnedInterestAmounts.at(count) = yrEndEarnedInterest;
			yrEndEarnedInterest = 0.0;
			count++;
		}
	}
}

void CompoundInvestmentModel::calculateWithoutDeposit()
{
	int count = 0;
	double total = iniInvestAmount;
	double interest = 0.0;
	double yrEndEarnedInterest = 0.0;
	
	for (int i = 1; i <= months; ++i)
	{
		total += (total * annualIntrestRate);
		interest = (total * annualIntrestRate);
		yrEndEarnedInterest += interest;
		if (i % 12 == 0)
		{
			
			yearEndBalanceWithOutDeposits.at(count) = total;
			endEarnedInterestAmtWoutDeposits.at(count) = yrEndEarnedInterest;
			yrEndEarnedInterest = 0.0;
			count++;
		}
	}
	
}

double CompoundInvestmentModel::calculateClosingBalance()
{
	//TODO: Use the compound intrest formula...
	return 0.0;
}
