#pragma once
#include <iostream>
#include <string>
#include <fstream>

class UserFunctions
{
private:
	std::string firstName;
	std::string lastName;
	std::string fullName;

	float savingsAccWorth;
	float debitCardWorth;
	float amountToTransfer;

public:
	UserFunctions();
	void DisplayMoney(const std::string& username);
	void DepositToSavings();
	void WithdrawToCard();
	void Logout(bool &bHasAccess);
};