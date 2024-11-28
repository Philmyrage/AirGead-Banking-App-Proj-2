/*
	Created By: Phillip Wood
	Date: 11/28/2024
	https://github.com/Philmyrage/AirGead-Banking-App-Proj-2
*/
#pragma once

#include "UserInput.h"
#include <memory>
#include<string>
#include<vector>

class UserInputOutput
{
public:

	UserInputOutput()
	{

	};
	
	std::unique_ptr<UserInput> getUserInput();
	
	const void printMessage(const std::string& message);
	
	void printInvestmentReport(std::unique_ptr<class CompoundInvestmentModel>& investmentModel);

	//returns true if the user enters 'y' false for anything else.
	const bool runAgain();
protected:


private:
	
	const bool validInput(const std::string& input);

	const void printTable(const std::string& tableName);

	const void printReport(const std::vector<double>& yearEndBalances, const std::vector<double>& yearEndInterest, const std::vector<double>& closingBalances, int numOfYears);
};

