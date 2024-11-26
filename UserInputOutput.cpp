#include "UserInputOutput.h"
#include <iostream>

UserInput* UserInputOutput::GetUserInput()
{
    UserInput* userInput = new UserInput;

    PrintMessage("Initial Investment Amount:  ");
    std::cin >> userInput->iniInvestAmount;
    PrintMessage("Monthly Deposit:  ");
    std::cin >> userInput->monthlyDeposit;
    PrintMessage("Annual Interest:  ");
    std::cin >> userInput->annualIntrestRate;
    PrintMessage("Number of years:  ");
    std::cin >> userInput->numOfYears;

    return userInput;
}

const void UserInputOutput::PrintInvestmentReport(const CompoundInvestementModel* const investmentModel)
{
    
}

const bool UserInputOutput::runAgain()
{
    char response = 'f';
    std::cout << "Run another model? y/n:	";
    std::cin >> response;
    return response != 'y';
}

const void UserInputOutput::PrintMessage(const std::string& message)
{
    std::cout << message;
}
