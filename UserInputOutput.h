/*
	Created By: Phillip Wood
	Date: 11/28/2024
	https://github.com/Philmyrage/AirGead-Banking-App-Proj-2
*/
#pragma once

#include "UserInput.h"

#include<string>
#include<vector>

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

