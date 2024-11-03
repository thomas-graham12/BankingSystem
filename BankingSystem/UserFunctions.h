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
	void DisplayUserInfo(const std::string& username);
	void DepositToSavings(const std::string& username);
	void WithdrawToCard(const std::string& username);
	void Logout(bool &bHasAccess);
	void TransferMoney(float& account, float& givenToAccount);
	void UpdateMoney(const std::string& username);
};