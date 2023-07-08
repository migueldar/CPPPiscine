#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ): _accountIndex(Account::_nbAccounts), _amount(initial_deposit) {
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount" << this->_amount << ";created" << std::endl;
}

Account::~Account( void ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount" << this->_amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount;
	std::cout << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

std::string truncateNumber(int i) {
	if (i > 9)
		return std::to_string(i);
	std::string zero = "0";
	return zero.append(std::to_string(i));
}

void Account::_displayTimestamp( void ) {
	std::time_t raw_time = std::time(nullptr);
	std::tm *time = std::localtime(&raw_time);
	std::cout << '[' << time->tm_year + 1900 << truncateNumber(time->tm_mon + 1) << truncateNumber(time->tm_mday) << '_';
	std::cout << truncateNumber(time->tm_hour) << truncateNumber(time->tm_min) << truncateNumber(time->tm_sec) << "] ";
}