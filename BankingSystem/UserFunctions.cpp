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
	std::ifstream txt("C:/Users/User/source/repos/2024/NormalPeopleProjects/BankingSystem/BankingSystem/BankUsers/");

	while (txt >> firstName >> lastName >> savingsAccWorth >> debitCardWorth)
	{
		fullName = firstName + " " + lastName;
		std::cout << fullName << '\n';
		std::cout << "Savings: $" << savingsAccWorth << '\n';
		std::cout << "Debit Card: $" << debitCardWorth << '\n';
	}
}

void UserFunctions::DepositToSavings()
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
}

void UserFunctions::WithdrawToCard()
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
}

void UserFunctions::Logout()
{
	// TODO!
}