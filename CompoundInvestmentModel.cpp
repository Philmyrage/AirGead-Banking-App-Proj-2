#include "CompoundInvestmentModel.h"

#include <cmath>

void CompoundInvestmentModel::calculateInvestment()
{
	for (int i = 1; i <= getNumOfYears(); i++)
	{
		//if its the first iteration calculate on the initial amount otherwise use the previous year.
		double amount = (i == 1) ? iniInvestAmount : yearEndBalanceWithOutDeposits.at(i - 2);


		yearEndBalanceWithOutDeposits.at(i - 1) = calculateYearEndBalanceWithoutDeposit(amount, i);
		endEarnedInterestAmtWoutDeposits.at(i - 1) = calculateCompoundInterest(amount);
	}
}

double CompoundInvestmentModel::calculateYearEndBalance(double amount)
{
	return amount + monthlyDeposit + calculateEndEarnedInterest(amount, true);
}

double CompoundInvestmentModel::calculateYearEndBalanceWithoutDeposit(double amount, int lengthOfTime)
{
	return amount * pow((1.0 + ((annualIntrestRate / 100.0) / 12.0)), (12.0 * 1));
}

double CompoundInvestmentModel::calculateEndEarnedInterest(double amount, bool withDeposit)
{
	return (withDeposit) ? (amount + monthlyDeposit) * ((annualIntrestRate / 100) / 12) : 
	amount * ((annualIntrestRate / 100) / 12);
}

double CompoundInvestmentModel::calculateClosingBalance()
{
	//TODO: Use the compound intrest formula...
	return 0.0;
}

double CompoundInvestmentModel::calculateCompoundInterest(double amount, int lengthOfInvestment, bool withoutDepoist)
{
	return  amount * (pow((1.0 + ((annualIntrestRate / 100.0) / 12.0)), (12.0 * lengthOfInvestment)) - 1);
}
