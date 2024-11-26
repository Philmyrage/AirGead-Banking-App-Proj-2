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
	inline unsigned getIniinvestAmount(){return iniInvestAmount;}
	inline unsigned getMonthlyDepost(){return monthlyDeposit;}
	inline unsigned getAnnualIntrestRate(){return annualIntrestRate;}
	inline short getNumOfYears(){return numOfYears;}

	inline void setIniInvestAmount(unsigned amount){iniInvestAmount = amount;}
	inline void setMonthlyDeposit(unsigned amount){monthlyDeposit = amount;}
	inline void setAnnualIntrestRate(unsigned amount){annualIntrestRate = amount;}
	inline void setNumOfYears(unsigned short amount){numOfYears = amount;}


protected:

private:
	unsigned iniInvestAmount;
	unsigned monthlyDeposit;
	unsigned annualIntrestRate;
	unsigned short numOfYears;
};

