#pragma once
#include <string>
#include <iostream>

class Account {
public:
	Account() = default;
	Account(std::string owner, double amount) : owner(owner), amount(amount) {}
	void calculate() { amount += amount * interestRate; }
	double getAmount() { return amount; }
	static double rate() { return interestRate; }
	static void rate(double r) { interestRate = r; }
private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate() { return 0.05; }
};

double Account::interestRate = initRate();