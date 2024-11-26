#include<iostream>
#include<conio.h>

#include "CompoundInvestmentModel.h"
#include "UserInputOutput.h"

int main()
{

	UserInputOutput* InputOutput = new UserInputOutput;
	UserInput* input = nullptr;
	CompoundInvestmentModel* investmentModel = nullptr;
	bool runAgain = true;

	while (runAgain)
	{
		 input = InputOutput->GetUserInput();

		 investmentModel = new CompoundInvestmentModel(input->iniInvestAmount, 
													   input->monthlyDeposit,
											           input->annualIntrestRate,
													   input->numOfYears);

		 InputOutput->PrintMessage("Press any key to contiune. . .\n");
		 _getch();

		 //Ask to run again
		 char response = 'f';
		 std::cout << "Run another model? y/n:	";
		 std::cin >> response;
		 if(response != 'y') runAgain = false;
	}


	delete InputOutput;
	delete input;

	return 0;
}