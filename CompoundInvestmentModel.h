#pragma once
class CompoundInvestmentModel
{
public:
	//Constructors
	CompoundInvestmentModel()
	{
		iniInvestAmount = 0;
		monthlyDeposit = 0;
		annualIntrestRate = 0;
		numOfYears = 0;
	}
	CompoundInvestmentModel(unsigned iniInvestAmount, unsigned monthlyDeposit, unsigned annualIntrestRate, unsigned short numOfYears)
	{
		this->annualIntrestRate = annualIntrestRate;
		this->iniInvestAmount = iniInvestAmount;
		this->monthlyDeposit = monthlyDeposit;
		this->numOfYears = numOfYears;
	}

	//Getters/Setters
	inline double getIniinvestAmount(){return iniInvestAmount;}
	inline double getMonthlyDepost(){return monthlyDeposit;}
	inline double getAnnualIntrestRate(){return annualIntrestRate;}
	inline short getNumOfYears(){return numOfYears;}

	inline void setIniInvestAmount(double amount){iniInvestAmount = amount;}
	inline void setMonthlyDeposit(double amount){monthlyDeposit = amount;}
	inline void setAnnualIntrestRate(double amount){annualIntrestRate = amount;}
	inline void setNumOfYears(unsigned short amount){numOfYears = amount;}


protected:

private:
	double iniInvestAmount;
	double monthlyDeposit;
	double annualIntrestRate;
	unsigned short numOfYears;
};

