/*
    Created By: Phillip Wood
    Date: 11/28/2024
    https://github.com/Philmyrage/AirGead-Banking-App-Proj-2
*/
#include "UserInputOutput.h"
#include "CompoundInvestmentModel.h"

#include <iostream>
#include <format>
#include <sstream>
#include <limits>

std::unique_ptr<UserInput> UserInputOutput::getUserInput()
{
    auto userInput = std::unique_ptr<UserInput>(new UserInput);
    std::string input = "";
    std::cout << std::format("{:*>{}}", "", 100) << std::endl << std::endl;
    std::cout << std::format("{:*^{}}", " Data Input ", 100) << std::endl << std::endl;

    do
    {
        printMessage("Initial Investment Amount: ");
        std::getline(std::cin, input);
        removeCharsFromInput(input);

    } while(!validNumericInput(input, userInput->iniInvestAmount, 1.0, std::numeric_limits<double>::infinity()));
    
    std::cout << "\n";

    do
    {
        printMessage("Monthly Deposit: ");
        std::getline(std::cin, input);
        removeCharsFromInput(input);

    }while(!validNumericInput(input, userInput->monthlyDeposit, 0.0, std::numeric_limits<double>::infinity()));

    std::cout << "\n";

    do
    {
        printMessage("Rate (Example: 5.5)(min 1, max 12): ");
        std::getline(std::cin, input);
        removeCharsFromInput(input);

    }while(!validNumericInput(input, userInput->annualIntrestRate, 1, 12));

    std::cout << "\n";

    do
    {
        printMessage("Length of Investment (months, min 12(1yr), max 120(10yr)): ");
        std::getline(std::cin, input);
        removeCharsFromInput(input);

    }while(!validNumericInput(input, userInput->months, 12, 120));

    std::cout << "\n";

    return std::move(userInput);
}

void UserInputOutput::printInvestmentReport(std::unique_ptr<CompoundInvestmentModel>& investmentModel)
{
    const int numOfYears = investmentModel->getNumOfYears();
    
    std::vector<double> closingBalancesNoDepo = investmentModel->getClosingBalancesNoDeposits();
    std::vector<double> yrEndBalanceWOutDepo = investmentModel->getEndBalanceWithoutDeposits();
    std::vector<double> yrEndInterestWOutDepo = investmentModel->getEndEarnedInterestAmtWoutDeposits();
    printTable(" Balance and Interest Without Additional Monthly Deposits ");
    printReport(yrEndBalanceWOutDepo, yrEndInterestWOutDepo, closingBalancesNoDepo, numOfYears);

    std::vector<double> closingBalancesWithDepo = investmentModel->getClosingBalancesWithdeposits();
    std::vector<double> yrEndBalanceWithDepo = investmentModel->getYearEndBalanceAmounts();
    std::vector<double> yrEndInterestWithDepo = investmentModel->getEarnedIntrestAmounts();
    printTable(" Balance and Interest With Additional Monthly Deposits ");
    printReport(yrEndBalanceWithDepo, yrEndInterestWithDepo, closingBalancesWithDepo, numOfYears);


}

const bool UserInputOutput::runAgain()
{
    char response = 'f';
    std::cout << "Run another model? y/n:	";
    std::cin >> response;
    return response == 'y';
}

template<typename Input, typename Value>
inline bool UserInputOutput::validNumericInput(const std::string& input, Input& OUTInput, Value min, Value max)
{
    //if the user only entered punctuation and the string is empty return false...
    if (input.size() == 0)
    {
        printMessage("Invalid, Try Again!\n");
        return false;
    }

    char t;
    std::string v = "";
    std::stringstream stream(input);

    while (stream >> t)
    {
        if (isdigit(t) || t == '.' || t == '-')
        {
            v += t;
        }
        else
        {
            printMessage("Invalid, Try Again!\n");
            return false;
        }
    }
    Value temp = std::stod(v);
    if (rangeCheck(temp, min, max))
    {
        OUTInput = std::stod(v);
        return true;
    }
    else
    {
        printMessage("Invalid(Out of Range), Try Again!\n");
        return false;
    }
}

void UserInputOutput::removeCharsFromInput(std::string& input)
{
    //for every non digit character remove it from the input...
    for (size_t i = 0, len = input.size(); i < len; ++i)
    {
        if (ispunct(input[i]) && (input[i] != '.') && (input[i] != '-'))
        {
            input.erase(i--, 1);
            len = input.size();
        }
    }
}

const void UserInputOutput::printTable(const std::string& tableName)
{
    //" Balance and Interest Without Additional Monthly Deposits "
    std::cout << "\n";
    std::cout << std::format("{:=^{}}", tableName, 100) << std::endl;
    std::cout << std::format("{:=>{}}", "", 100) << std::endl;

    //These lines are dividing the default space of 100 between them since they are on the same line...
    std::cout << std::format("{: <{}}", "Year", 25);
    std::cout << std::format("{: ^{}}", "Year End Balance", 25);
    std::cout << std::format("{: ^{}}", "Year End Earned Interest", 25);
    std::cout << std::format("{: >{}}", "Closing Balance", 25) << std::endl;
    std::cout << std::format("{:->{}}", "", 100) << std::endl << std::endl;
}

const void UserInputOutput::printReport(const std::vector<double>& yearEndBalances, const std::vector<double>& yearEndInterest, const std::vector<double>& closingBalances, int numOfYears)
{
    //Loop the number of years adding rows with the associated data...
    for (int i = 0; i < numOfYears; i++)
    {

        //Year
        std::cout << std::format("{: <{}}", i + 1, 25);

        //Year End Balance
        std::cout << std::format("{: ^{}}", std::format("{}{:.2f}", "$", yearEndBalances.at(i)), 25);

        //Year End Earned Interest
        std::cout << std::format("{: ^{}}", std::format("{}{:.2f}", "$", yearEndInterest.at(i)), 25);

        //Year Closing Balance
        std::cout << std::format("{: >{}}", std::format("{}{:.2f}", "$", closingBalances.at(i)), 25) << std::endl;

        //once row is complete start new row.
        std::cout << std::format("{:->{}}", "", 100);
        std::cout << std::endl;
    }

    std::cout << std::format("{:=>{}}", "", 100) << std::endl;
}

const void UserInputOutput::printMessage(const std::string& message)
{
    std::cout << message;
}