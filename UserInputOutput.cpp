#include "UserInputOutput.h"
#include "CompoundInvestmentModel.h"

#include <iostream>
#include <format>
#include <map>
#include <string>

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

const void UserInputOutput::PrintInvestmentReport(CompoundInvestmentModel* const investmentModel)
{
    std::cout << "\n";
    std::cout << std::format("{:=^{}}", " Balance and Interest Without Additional Monthly Deposits ", 100) << std::endl;
    std::cout << std::format("{:=>{}}", "", 100) << std::endl;

    //These lines are dividing the default space of 100 between them since they are on the same line...
    std::cout << std::format("{: <{}}","Year", 33);
    std::cout << std::format("{: ^{}}", "Year End Balance", 33);
    std::cout << std::format("{: >{}}", "Year End Earned Interest", 34) << std::endl;
    std::cout << std::format("{:->{}}", "", 100) << std::endl << std::endl;



    //Loop the number of years adding rows with the associated data...
    for (int i = 1; i <= investmentModel->getNumOfYears(); i++)
    {
        std::cout << std::format("{: <{}}", i, 33);

        //once row is complete start new row.
        std::cout << std::endl << std::endl;
    }
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
