#include "UserFunctions.h"

UserFunctions::UserFunctions()
{
	savingsAccWorth = 0;
	debitCardWorth = 0;
	amountToTransfer = 0;
}

void UserFunctions::DisplayUserInfo(const std::string& username)
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
	std::cout << "Debit Card: $" << debitCardWorth << "\n\n\n";

	txt.close();
}

void UserFunctions::DepositToSavings(const std::string& username)
{
	std::cout << "How much would you like to deposit: ";
	std::cin >> amountToTransfer;

	TransferMoney(debitCardWorth, savingsAccWorth);

	UpdateMoney(username);

}

void UserFunctions::WithdrawToCard(const std::string& username)
{
	std::cout << "How much would you like to withdraw: ";
	std::cin >> amountToTransfer;

	TransferMoney(savingsAccWorth, debitCardWorth);

	UpdateMoney(username);
}

void UserFunctions::Logout(bool& bHasAccess)
{
	std::cout << "Now logging you out...\n\n\n\n\n\n";
	bHasAccess = false;
}

void UserFunctions::TransferMoney(float& takenFromAccount, float& givenToAccount)
{
	if (amountToTransfer < takenFromAccount && amountToTransfer > 0)
	{
		takenFromAccount -= amountToTransfer;
		givenToAccount += amountToTransfer;
		std::cout << "$" << amountToTransfer << " has been transferred\n\n\n\n\n\n";
	}
	else if (amountToTransfer > takenFromAccount)
	{
		std::cout << "Not enough money to transfer.\n\n\n\n\n\n";
	}
	else if (amountToTransfer < takenFromAccount)
	{
		std::cout << "Money to transfer must be more than you have.\n\n\n\n\n\n";
	}
	else
	{
		std::cout << "Not a valid amount.\n\n\n\n\n\n";
	}
}

void UserFunctions::UpdateMoney(const std::string& username)
{
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
		std::cerr << "Unable to open file\n\n\n\n\n\n";
	}
}