#pragma once
#include<string>
#include<vector>

struct UserInput
{
	double iniInvestAmount = 0.0;
	double monthlyDeposit = 0.0;
	double annualIntrestRate = 0.0;
	int numOfYears = 0;
};

class UserInputOutput
{
public:
	
	const void printMessage(const std::string& message);
	
	UserInput* const getUserInput();
	
	const void printInvestmentReport(class CompoundInvestmentModel* const investmentModel);

	//returns true if the user enters 'y' false for anything else.
	const bool runAgain();
protected:


private:
	
	const void printTable(const std::string& tableName);

	const void printReport(const std::vector<double>& yearEndBalances, const std::vector<double>& yearEndInterest, int numOfYears);
};

