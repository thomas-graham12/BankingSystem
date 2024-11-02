#include <iostream>
#include <unordered_map>
#include "UserList.h"
#include "UserFunctions.h"

//////////////////
/*
	TODO:
	Work on functionality for when logged in.
	Look at refactoring UserFunctions Withdraw and Deposit functions.
	Start commenting some important lines.


	Will update as time goes on.
*/


int main()
{
	bool bHasAccess = false;
	UserList userList;
	UserFunctions userFunctions;
	bool bIsOpen = false;
	int choice = 0;

	std::cout << "*****************************\n" <<
		"*                           *\n" <<
		"*          Welcome          *\n" <<
		"*   Please choose an option *\n" <<
		"*                           *\n" <<
		"*                           *\n" <<
		"*****************************\n\n";
	userList.ReadUserFromFile();
	while (!bIsOpen)
	{

		std::cout << "1. Create an account\n2. Login to an account\n3. Forgot password\n4. Exit\n";

		std::cin >> choice;

		switch (choice)
		{
		case 1:
			userList.CreateAccount();
			break;
		case 2:
			userList.AccountLogin(bHasAccess);
			break;
		case 3:
			userList.ForgotPassword();
			break;
		case 4:
			bIsOpen = false;
			break;
		case 5:
			userList.GetUserList();
			break;
		default:
			break;
		}

		if (bHasAccess)
		{
			int choice = 0;


			while (choice != 3)
			{

				userFunctions.DisplayMoney(userList.GetUser());

				std::cout << "\n\nWhat would you like to do?\n1. Depost Money\n2. Withdraw Money\n3. Logout\n";
				std::cin >> choice;
				switch (choice)
				{
				case 1:
					userFunctions.DepositToSavings(userList.GetUser());
					break;
				case 2:
					userFunctions.WithdrawToCard(userList.GetUser());
					break;
				case 3:
					userFunctions.Logout(bHasAccess);
					break;
				default:
					break;
				}
			}
		}
		else
		{
			continue;
		}
	}

	return 0;
}



// Basic way of making a new file and then adding text and closing to prevent mem leaks
/*filesPath /= "newfile.txt";
std::ofstream ofs(filesPath);
ofs << "This is some text\nThis is some more text.\nThis is even more text.\n";
ofs.close();*/


// Using filesystem to specify a path and read files from that directory
/*
	std::filesystem::path filesPath("C:/Users/User/source/repos/2024/NormalPeopleProjects/BankingSystem/BankingSystem/BankUsers/");
	std::vector<std::string> fileNames;

	for (const auto& entry : std::filesystem::directory_iterator(filesPath))
	{
		fileNames.emplace_back(entry.path().filename().string());
	}

	for (const auto file : fileNames)
	{
		std::cout << file << " ";
	}
*/


// Checks the map for the user and if it doesn't go to the end. As well as if the user has the correct value. Quite important I would say!
/*

else
{
	std::cout << "does not contain the right value";
}

if (bHasAccess)
{
	std::cout << "You are seeing this\n";
}
else
{
	std::cout << "No access\n";
}s
*/


// Way to read numbers into variables from text files.
/*
	std::ifstream txt("C:/Users/User/source/repos/2024/NormalPeopleProjects/BankingSystem/BankingSystem/BankUsers/john.txt");

	std::string firstName;
	std::string lastName;
	std::string fullName;
	int savingsAccWorth = 0;
	int debitCardWorth = 0;

	while (txt >> firstName >> lastName >> savingsAccWorth >> debitCardWorth)
	{
		fullName = firstName + " " + lastName;
		std::cout << fullName << '\n';
		std::cout << "Savings: $" << savingsAccWorth << '\n';
		std::cout << "Debit Card: $" << debitCardWorth << '\n';
	}
*/