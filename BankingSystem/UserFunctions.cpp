#include "UserFunctions.h"

UserFunctions::UserFunctions()
{
	savingsAccWorth = 0;
	debitCardWorth = 0;
	amountToTransfer = 0;
}

void UserFunctions::DisplayMoney(const std::string& username)
{
	std::string fileName = username + ".txt";
	std::ifstream txt;
	
	txt.open("C:/Users/User/source/repos/2024/NormalPeopleProjects/BankingSystem/BankingSystem/BankUsers/" + fileName);

	if (!txt.is_open())
	{
		std::cerr << "Error: Could not open " << fileName << '\n';
	}

	txt >> firstName >> lastName >> savingsAccWorth >> debitCardWorth;

	fullName = firstName + " " + lastName;
	std::cout << "Name: " << fullName << '\n';
	std::cout << "Savings: $" << savingsAccWorth << '\n';
	std::cout << "Debit Card: $" << debitCardWorth << '\n';

	txt.close();
}

void UserFunctions::DepositToSavings(const std::string& username)
{
	std::cout << "How much would you like to deposit: ";
	std::cin >> amountToTransfer;

	if (amountToTransfer < debitCardWorth && amountToTransfer > 0)
	{
		debitCardWorth -= amountToTransfer;
		savingsAccWorth += amountToTransfer;
		std::cout << "$" << amountToTransfer << " has been transferred to your savings account.\n";
	}
	else if (amountToTransfer > debitCardWorth)
	{
		std::cout << "Not enough money in to transfer.\n";
	}
	else if (amountToTransfer < debitCardWorth)
	{
		std::cout << "Money to transfer must be more than you have.\n";
	}
	else
	{
		std::cout << "Not a valid amount.\n";
	}

	// WRITING TO FILE
	std::string fileName = username + ".txt";
	std::ofstream outfile;
	// Open a file in write mode
	outfile.open("C:/Users/User/source/repos/2024/NormalPeopleProjects/BankingSystem/BankingSystem/BankUsers/" + fileName);

	if (outfile.is_open())
	{
		outfile << firstName << " " << lastName << " " << savingsAccWorth << " " << debitCardWorth;
		outfile.close();
	}
	else
	{
		std::cerr << "Unable to open file\n\n";
	}
}

void UserFunctions::WithdrawToCard(const std::string& username)
{
	std::cout << "How much would you like to withdraw: ";
	std::cin >> amountToTransfer;

	if (amountToTransfer < savingsAccWorth && amountToTransfer > 0)
	{
		savingsAccWorth -= amountToTransfer;
		debitCardWorth += amountToTransfer;
		std::cout << "$" << amountToTransfer << " has been transferred to your debit card.\n";
	}
	else if (amountToTransfer > savingsAccWorth)
	{
		std::cout << "Not enough money to transfer.\n";
	}
	else if (amountToTransfer < savingsAccWorth)
	{
		std::cout << "Money to transfer must be more than you have.\n";
	}
	else
	{
		std::cout << "Not a valid amount.\n";
	}

	// WRITING TO FILE
	std::string fileName = username + ".txt";
	std::ofstream outfile;
	// Open a file in write mode
	outfile.open("C:/Users/User/source/repos/2024/NormalPeopleProjects/BankingSystem/BankingSystem/BankUsers/" + fileName);

	if (outfile.is_open())
	{
		outfile << firstName << " " << lastName << " " << savingsAccWorth << " " << debitCardWorth;
		outfile.close();
	}
	else
	{
		std::cerr << "Unable to open file\n\n";
	}
}

void UserFunctions::Logout(bool& bHasAccess)
{
	std::cout << "Now logging you out...\n\n";
	bHasAccess = false;
}