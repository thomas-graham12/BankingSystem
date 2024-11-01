#pragma once
#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class UserList
{
private:
	std::unordered_map<std::string, std::string> listOfUserInfo;
	std::string user;
	std::string pass;

public:
	UserList();
	void CreateAccount();
	bool AccountLogin(bool &bHasAccess);
	void ForgotPassword();
	void GetUserList();
	void WriteUserToFile();
	void ReadUserFromFile();

	// Getters
	std::string GetUser() { return user; }

};