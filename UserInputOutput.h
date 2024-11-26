#pragma once
#include<string>

struct UserInput
{
	unsigned iniInvestAmount = 0;
	unsigned monthlyDeposit = 0;
	unsigned annualIntrestRate = 0;
	unsigned short numOfYears = 0;
};

class UserInputOutput
{
public:
	
	const void printMessage(const std::string& message);
	
	UserInput* GetUserInput();
	
	const void PrintInvestmentReport(const class CompoundInvestmentModel* const investmentModel);

	//returns true if the user enters 'y' false for anything else.
	const bool runAgain();
protected:


private:

};

