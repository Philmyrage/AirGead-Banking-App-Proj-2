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
	
	//prints a simple message instead of having to use the necessary input output syntax every time.
	const void printMessage(const std::string& message);
	
	//Prints the Investment Report with help of the private healper functions.
	void printInvestmentReport(std::unique_ptr<class CompoundInvestmentModel>& investmentModel);

	//returns true if the user enters 'y' false for anything else.
	const bool runAgain();
protected:


private:
	//validates that the input string is a numeric value within a given range...
	template<typename Input, typename Value>
	bool validNumericInput(const std::string& input, Input& OUTInput, Value min, Value max);
	
	//checks a value within a given range.
	template<typename Value>
	inline bool rangeCheck(Value value, Value min, Value max){ return (value >= min) && (value <= max); }

	//removes punctuation characters from the input string, so the user can enter $,%, etc and it will be ignored.
	//However, it does not remove negative or periods.
	void removeCharsFromInput(std::string & input);

	//prints a table heading with a given name.
	const void printTable(const std::string& tableName);

	//prints the rows of the table with the given data.
	const void printReport(const std::vector<double>& yearEndBalances, const std::vector<double>& yearEndInterest, const std::vector<double>& closingBalances, int numOfYears);
};

