#include "CompoundInvestmentModel.h"

#include <cmath>

void CompoundInvestmentModel::calculateInvestment()
{
	for (int i = 0; i < getNumOfYears(); i++)
	{
		//if its the first iteration calculate on the initial amount otherwise use the previous year.
		int amount = (i == 0) ? iniInvestAmount : yearEndBalanceAmounts.at(i - 1);

		yearEndBalanceAmounts.at(i) = calculateYearEndBalance(amount);
		yearEndBalanceWithOutDeposits.at(i) = calculateYearEndBalanceWithoutDeposit(amount);
		endEarnedInterestAmounts.at(i) = calculateEndEarnedInterest(amount, true);
		endEarnedInterestAmtWoutDeposits.at(i) = calculateEndEarnedInterest(amount, false);
	}
}

double CompoundInvestmentModel::calculateYearEndBalance(double amount)
{
	return amount + monthlyDeposit + calculateEndEarnedInterest(amount, true);
}

double CompoundInvestmentModel::calculateYearEndBalanceWithoutDeposit(double amount)
{
	return amount + calculateEndEarnedInterest(amount, false);
}

double CompoundInvestmentModel::calculateEndEarnedInterest(double amount, bool withDeposit)
{
	return (withDeposit) ? (amount + monthlyDeposit) * ((annualIntrestRate / 100) / 12) : 
	amount * ((annualIntrestRate / 100) / 12);
}
