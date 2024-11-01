#include "UserList.h"

UserList::UserList()
{
	
}

void UserList::CreateAccount()
{
	std::cout << "Enter a username: ";
	std::cin >> user;

	std::cout << "Enter a password: ";
	std::cin >> pass;

	std::cout << "Successfully created account\n";
	listOfUserInfo[user] = pass;

	std::ofstream file;
	std::string fileName = "C:/Users/User/source/repos/2024/NormalPeopleProjects/BankingSystem/BankingSystem/BankUsers/" + user + ".txt";
	file.open(fileName);
	file.close();
	WriteUserToFile();
	ReadUserFromFile();
}

bool UserList::AccountLogin(bool& bHasAccess)
{
	std::cout << "Enter a username: ";
	std::cin >> user;

	std::cout << "Enter a password: ";
	std::cin >> pass;

	// Scans map for the user (stops when found it.) and checks to see if pass is right
	if (listOfUserInfo.find(user) != listOfUserInfo.end() && listOfUserInfo[user] == pass)
	{
		std::cout << "Logged in successfully\n";
		return bHasAccess = true;
	}
	else
	{
		std::cout << "Wrong username or password\n";
		return bHasAccess = false;
	}
}

void UserList::ForgotPassword()
{
	std::cout << "What is your username: ";
	std::cin >> user;
	if (listOfUserInfo.find(user) != listOfUserInfo.end())
	{
		std::cout << "Please enter a new password: ";
		std::cin >> pass;
		listOfUserInfo[user] = pass;
	}
}

void UserList::GetUserList()
{
	for (auto i = listOfUserInfo.begin(); i != listOfUserInfo.end(); i++)
	{
		std::cout << i->first << " : " << i->second << '\n';
	}
}

void UserList::WriteUserToFile()
{
	// Open a file in write mode
	std::ofstream outfile("C:/Users/User/source/repos/2024/NormalPeopleProjects/BankingSystem/BankingSystem/BankUsers/userdata.txt");

	if (outfile.is_open())
	{
		// Write each key-value pair to the file.
		for (const auto& pair : listOfUserInfo)
		{
			outfile << pair.first << " " << pair.second << '\n';
		}
		outfile.close();
		std::cout << "Data written to file\n\n";
	}
	else
	{
		std::cerr << "Unable to open file\n\n";
	}
}

void UserList::ReadUserFromFile()
{
	// Open file in read mode
	std::ifstream infile("C:/Users/User/source/repos/2024/NormalPeopleProjects/BankingSystem/BankingSystem/BankUsers/userdata.txt");

	if (infile.is_open())
	{
		std::string line;
		while (std::getline(infile, line))
		{
			// Create istringstream to parse the lines
			std::istringstream iss(line); 
			std::string username;
			std::string password;

			// Extract usernames and passwords. ">>" means seperated by whitespace
			if (iss >> username >> password)
			{
				// Add to map
				listOfUserInfo[username] = password;
			}
		}
		// Close to prevent memory leaks
		infile.close();
		std::cout << "Data loaded successfully.\n\n";
	}
	else
	{
		std::cerr << "Unable to open file.\n";
	}
}
