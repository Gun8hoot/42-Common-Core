#include "Account.hpp"

int Account::_nbAccounts       = 0;
int Account::_totalAmount      = 0;
int Account::_totalNbDeposits  = 0;
int Account::_totalNbWithdrawals = 0;

/* ----- PUBLIC ----- */
int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";amount:" <<  this->_amount
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}


void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout	<< " account:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = getNbAccounts();
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";created" << std::endl;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this->_nbDeposits++;
	_totalNbDeposits++;
	this->_displayTimestamp();
	std::cout	<< " index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount
				<< ";amount:" << this->_amount + deposit
				<< ";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount = this->_amount + deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_displayTimestamp();
	if (this->_amount < withdrawal)
	{
		std::cout	<< " index:" << this->_accountIndex
					<< ";p_amount:" << this->_amount
					<< ";withdrawals:refused" << std::endl;
		return (false);
	}
	else
	{
 		_nbWithdrawals++;
   		_totalNbWithdrawals++;
		std::cout	<< " index:" << this->_accountIndex
					<< ";p_amount:" << this->_amount
					<< ";withdrawals:" << withdrawal
					<< ";amount:" << this->_amount - withdrawal
					<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
 		this->_amount = this->_amount - withdrawal;
 		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}


/* ----- PRIVATE ----- */

void Account::_displayTimestamp(void)
{
	std::time_t time = std::time(0);
	std::tm *time_vars = std::localtime(&time);

	std::cout << "[";
	std::cout << std::setfill('0');
	std::cout << (time_vars->tm_year + 1900)
	          << std::setw(2) << (time_vars->tm_mon + 1)
	          << std::setw(2) << time_vars->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << time_vars->tm_hour
	          << std::setw(2) << time_vars->tm_min
	          << std::setw(2) << time_vars->tm_sec;
	std::cout << "]";
}
