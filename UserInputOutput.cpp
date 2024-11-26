#include "UserInputOutput.h"
#include <iostream>

UserInput* UserInputOutput::GetUserInput()
{
    UserInput* userInput = new UserInput;


    printMessage("Initial Investment Amount:  ");
    std::cin >> userInput->iniInvestAmount;
    printMessage("Monthly Deposit:  ");
    std::cin >> userInput->monthlyDeposit;
    printMessage("Annual Interest:  ");
    std::cin >> userInput->annualIntrestRate;
    printMessage("Number of years:  ");
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

const void UserInputOutput::printMessage(const std::string& message)
{
    std::cout << message;
}
