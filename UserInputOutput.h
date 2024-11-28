#pragma once
#include<string>

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
	
	UserInput* GetUserInput();
	
	const void PrintInvestmentReport(class CompoundInvestmentModel* const investmentModel);

	//returns true if the user enters 'y' false for anything else.
	const bool runAgain();
protected:


private:
	
	const void PrintTable(const std::string& tableName);

};

