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

    std::vector<double> yrEndBalanceWOutDeposit = investmentModel->getEndBalanceWithoutDeposits();
    std::vector<double> endEarnedInterestWOutDepoist = investmentModel->getEndEarnedInterestAmtWoutDeposits();
    

    //Loop the number of years adding rows with the associated data...
    for (int i = 0; i < investmentModel->getNumOfYears(); i++)
    {
 
        //Year
        std::cout << std::format("{: <{}}", i + 1, 33);

        //Year End Balance
        std::cout << std::format("{: ^{}}", std::format("{}{:.2f}", "$", yrEndBalanceWOutDeposit.at(i)), 33);

        //Year End Earned Interest
        std::cout << std::format("{: >{}}", std::format("{}{:.2f}","$", endEarnedInterestWOutDepoist.at(i)), 34);
        
        //once row is complete start new row.
        std::cout << std::endl << std::endl;
    }

    std::cout << "\n";
    std::cout << std::format("{:=^{}}", " Balance and Interest With Additional Monthly Deposits ", 100) << std::endl;
    std::cout << std::format("{:=>{}}", "", 100) << std::endl;

    //These lines are dividing the default space of 100 between them since they are on the same line...
    std::cout << std::format("{: <{}}", "Year", 33);
    std::cout << std::format("{: ^{}}", "Year End Balance", 33);
    std::cout << std::format("{: >{}}", "Year End Earned Interest", 34) << std::endl;
    std::cout << std::format("{:->{}}", "", 100) << std::endl << std::endl;

    std::vector<double> yrEndBalanceWithDepo = investmentModel->getYearEndBalanceAmounts();
    std::vector<double> yrEndInterestWithDepo = investmentModel->getEarnedIntrestAmounts();

    //Loop the number of years adding rows with the associated data...
    for (int i = 0; i < investmentModel->getNumOfYears(); i++)
    {

        //Year
        std::cout << std::format("{: <{}}", i + 1, 33);

        //Year End Balance
        std::cout << std::format("{: ^{}}", std::format("{}{:.2f}", "$", yrEndBalanceWithDepo.at(i)), 33);

        //Year End Earned Interest
        std::cout << std::format("{: >{}}", std::format("{}{:.2f}", "$", yrEndInterestWithDepo.at(i)), 34);

        //once row is complete start new row.
        std::cout << std::endl << std::endl;
    }

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

const void UserInputOutput::printMessage(const std::string& message)
{
    std::cout << message;
}
