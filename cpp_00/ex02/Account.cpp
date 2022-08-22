#include "Account.hpp"
#include <iostream>
#include <ctime>

// init private static variable;
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// public method;
Account::Account(int initial_deposit) {
	this->_displayTimestamp();
	this->_accountIndex = (this->_nbAccounts)++;
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";amount:";
	std::cout << this->_amount;
	std::cout << ";created" << std::endl;
}

Account::~Account() {
	this->_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";amount:";
	std::cout << this->_amount;
	std::cout << ";closed" << std::endl;
}

int	Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:";
	std::cout << Account::getNbAccounts();
	std::cout << ";total:";
	std::cout << Account::getTotalAmount();
	std::cout << ";deposits:";
	std::cout << Account::getNbDeposits();
	std::cout << ";withdrawals:";
	std::cout << Account::getNbWithdrawals() << std::endl;
}


void	Account::makeDeposit(int deposit) {
	this->_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";p_amount:";
	std::cout << this->_amount;
	std::cout << ";deposit:";
	std::cout << deposit;
	this->_amount += deposit;
	this->_totalAmount += deposit;
	(this->_nbDeposits)++;
	(this->_totalNbDeposits)++;
	std::cout << ";amount:";
	std::cout << this->_amount;
	std::cout << ";nb_deposits:";
	std::cout << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawl) {
	this->_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";p_amount:";
	std::cout << this->_amount;
	std::cout << ";withdrawal:";
	if (this->_amount < withdrawl) {
		std::cout << "refused" << std::endl;
		return false;
	}
	else {
		std::cout << withdrawl;
		this->_amount -= withdrawl;
		this->_totalAmount -= withdrawl;
		(this->_nbWithdrawals)++;
		(this->_totalNbWithdrawals)++;
	}
	std::cout << ";amount:";
	std::cout << this->_amount;
	std::cout << ";nb_withdrawals:";
	std::cout << this->_nbWithdrawals << std::endl;
	return true;
}

int	Account::checkAmount() const {
	return this->_amount;
}

void	Account::displayStatus() const {
	this->_displayTimestamp();
	std::cout << "index:";
	std::cout << this->_accountIndex;
	std::cout << ";amount:";
	std::cout << this->checkAmount();
	std::cout << ";deposits:";
	std::cout << this->_nbDeposits;
	std::cout << ";withdrawals:";
	std::cout << this->_nbWithdrawals << std::endl;
}

// private method;
void	Account::_displayTimestamp() {
	time_t	r_time;
	struct tm * timeinfo;
	char	buffer[19];

	time(&r_time);
	timeinfo = localtime(&r_time);
	strftime(buffer, 19, "[%Y%m%d_%H%M%S] ", timeinfo);
	std::cout << buffer;
}

Account::Account() {
}
