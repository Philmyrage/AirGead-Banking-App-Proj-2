/*
    Created By: Phillip Wood
    Date: 11/28/2024
    https://github.com/Philmyrage/AirGead-Banking-App-Proj-2
*/
#include "UserInputOutput.h"
#include "CompoundInvestmentModel.h"

#include <iostream>
#include <format>

UserInput* const UserInputOutput::getUserInput()
{
    UserInput* userInput = new UserInput;

    std::cout << std::format("{:*>{}}", "", 50) << std::endl << std::endl;
    std::cout << std::format("{:*^{}}", " Data Input ", 50) << std::endl << std::endl;

    printMessage("Initial Investment Amount:  ");
    std::cin >> userInput->iniInvestAmount;
    printMessage("Monthly Deposit:  ");
    std::cin >> userInput->monthlyDeposit;
    printMessage("Annual Interest:  ");
    std::cin >> userInput->annualIntrestRate;
    printMessage("Number of years in (months):  ");
    std::cin >> userInput->months;

    return userInput;
}

const void UserInputOutput::printInvestmentReport(CompoundInvestmentModel* const investmentModel)
{
    const int numOfYears = investmentModel->getNumOfYears();

    std::vector<double> yrEndBalanceWOutDepo = investmentModel->getEndBalanceWithoutDeposits();
    std::vector<double> yrEndInterestWOutDepo = investmentModel->getEndEarnedInterestAmtWoutDeposits();
    printTable(" Balance and Interest Without Additional Monthly Deposits ");
    printReport(yrEndBalanceWOutDepo, yrEndInterestWOutDepo, numOfYears);
    
    std::vector<double> yrEndBalanceWithDepo = investmentModel->getYearEndBalanceAmounts();
    std::vector<double> yrEndInterestWithDepo = investmentModel->getEarnedIntrestAmounts();
    printTable(" Balance and Interest With Additional Monthly Deposits ");
    printReport(yrEndBalanceWithDepo, yrEndInterestWithDepo, numOfYears);

    std::cout << std::format("{:->{}}", "", 100) << std::endl;
    std::cout << std::format("{: ^{}}", "Closing Balance: " + std::to_string(100), 100) << std::endl;
}

const bool UserInputOutput::runAgain()
{
    char response = 'f';
    std::cout << "Run another model? y/n:	";
    std::cin >> response;
    return response == 'y';
}

const void UserInputOutput::printTable(const std::string& tableName)
{
    //" Balance and Interest Without Additional Monthly Deposits "
    std::cout << "\n";
    std::cout << std::format("{:=^{}}", tableName, 100) << std::endl;
    std::cout << std::format("{:=>{}}", "", 100) << std::endl;

    //These lines are dividing the default space of 100 between them since they are on the same line...
    std::cout << std::format("{: <{}}", "Year", 33);
    std::cout << std::format("{: ^{}}", "Year End Balance", 33);
    std::cout << std::format("{: >{}}", "Year End Earned Interest", 34) << std::endl;
    std::cout << std::format("{:->{}}", "", 100) << std::endl << std::endl;
}

const void UserInputOutput::printReport(const std::vector<double>& yearEndBalances, const std::vector<double>& yearEndInterest, int numOfYears)
{
    //Loop the number of years adding rows with the associated data...
    for (int i = 0; i < numOfYears; i++)
    {

        //Year
        std::cout << std::format("{: <{}}", i + 1, 33);

        //Year End Balance
        std::cout << std::format("{: ^{}}", std::format("{}{:.2f}", "$", yearEndBalances.at(i)), 33);

        //Year End Earned Interest
        std::cout << std::format("{: >{}}", std::format("{}{:.2f}", "$", yearEndInterest.at(i)), 34);

        //once row is complete start new row.
        std::cout << std::endl << std::endl;
    }
}

const void UserInputOutput::printMessage(const std::string& message)
{
    std::cout << message;
}
