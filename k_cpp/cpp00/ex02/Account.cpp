#include "Account.hpp"

#include <iostream>
#include <ctime>

Account::Account(void) {}

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout	<< "index:"	<< this->_accountIndex	<< ';'
				<< "amount:"<< this->_amount		<< ';'
				<< "created"						<< std::endl;
}

Account::~Account(void)
{
	Account::_nbAccounts--;

	_displayTimestamp();
	std::cout	<< "index:"	<< this->_accountIndex	<< ';'
				<< "amount:"<< this->_amount		<< ';'
				<< "closed"							<< std::endl;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout	<< "accounts:"		<< getNbAccounts()		<< ';'
				<< "total:"			<< getTotalAmount()		<< ';'
				<< "deposits:"		<< getNbDeposits()		<< ';'
				<< "withdrawals:"	<< getNbWithdrawals()	<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount;

	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	p_amount = this->_amount;
	this->_amount += deposit;

	_displayTimestamp();

	std::cout	<< "index:"			<< this->_accountIndex	<< ';'
				<< "p_amount:"		<< p_amount				<< ';'
				<< "deposit:"		<< deposit				<< ';'
				<< "amount:"		<< this->_amount		<< ';'
				<< "nb_deposits:"	<< this->_nbDeposits	<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount;

	p_amount = this->_amount;

	_displayTimestamp();

	if (this->_amount - withdrawal >= 0) {
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;

		std::cout	<< "index:"				<< this->_accountIndex		<< ';'
					<< "p_amount:"			<< p_amount					<< ';'
					<< "withdrawal:"		<< withdrawal				<< ';'
					<< "amount:"			<< this->_amount			<< ';'
					<< "nb_withdrawals:"	<< this->_nbWithdrawals		<< std::endl;
		return (true);
	}
	else {
		std::cout	<< "index:"		<< this->_accountIndex	<< ';'
					<< "p_amount:"	<< p_amount				<< ';'
					<< "withdrawal:"<< "refused"			<< std::endl;
		return (false);
	}
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout	<< "index:"			<< this->_accountIndex	<< ';'
				<< "amount:"		<< this->_amount		<< ';'
				<< "deposits:"		<< this->_nbDeposits	<< ';'
				<< "withdrawals:"	<< this->_nbWithdrawals	<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	t;

	t = std::time(nullptr);

	char	timestr[sizeof("[yyyymmdd_hhmmss] ")];
	if (std::strftime(timestr, sizeof(timestr), "[%Y%m%d_%H%M%S] ", std::localtime(&t)))
		std::cout << timestr << std::flush;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
