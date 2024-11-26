#include "UserInputOutput.h"
#include <iostream>
#include <format>

UserInput* UserInputOutput::GetUserInput()
{
    UserInput* userInput = new UserInput;

    printMessage("***********************************\n");
    printMessage("************ Data Input ***********\n\n");

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
    //Find the max character length of all the values so we can set the spacing in our formatted table.
    int maxValueLength = 5;


}

const bool UserInputOutput::runAgain()
{
    char response = 'f';
    std::cout << "Run another model? y/n:	";
    std::cin >> response;
    return response == 'y';
}

const void UserInputOutput::printMessage(const std::string& message)
{
    std::cout << message;
}
