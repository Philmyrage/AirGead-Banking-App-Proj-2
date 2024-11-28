/*
	Created By: Phillip Wood
	Date: 11/28/2024
	https://github.com/Philmyrage/AirGead-Banking-App-Proj-2
*/

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
		 input = InputOutput->getUserInput();

		 CompoundInvestmentModel* investmentModel = new CompoundInvestmentModel(input);

		 investmentModel->calculateInvestment();

		 //Print user feedback and wait for any input... Windows Only!
		 InputOutput->printMessage("Press any key to continue. . .\n");
		 _getch();


		 InputOutput->printInvestmentReport(investmentModel);

		 //Ask to run again
		runAgain = InputOutput->runAgain();
	}


	delete InputOutput;
	delete input;

	return 0;
}