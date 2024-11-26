#include<iostream>
#include<conio.h>

#include "CompoundInvestmentModel.h"
#include "UserInputOutput.h"

int main()
{

	UserInputOutput* InputOutput = new UserInputOutput;
	UserInput* input = nullptr;
	bool runAgain = true;

	while (runAgain)
	{
		 input = InputOutput->GetUserInput();

		 const CompoundInvestmentModel* investmentModel = new CompoundInvestmentModel(input->iniInvestAmount,
													   input->monthlyDeposit,
											           input->annualIntrestRate,
													   input->numOfYears);

		 InputOutput->printMessage("Press any key to continue. . .\n");
		 _getch();

		 InputOutput->PrintInvestmentReport(investmentModel);

		 //Ask to run again
		runAgain = InputOutput->runAgain();
	}


	delete InputOutput;
	delete input;

	return 0;
}