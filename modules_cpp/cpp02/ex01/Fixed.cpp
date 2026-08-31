#include "Fixed.hpp"

/* --- CONSTRUCTOR --- */
Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	this->value = 0;
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &cpy)
		*this = cpy;
}

Fixed &Fixed::operator=(const Fixed& cpy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &cpy)
		this->value = cpy.getRawBits();
	return (*this);
}

Fixed::Fixed(const int int_number)
{
	value = int_number << bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_number)
{
	this->value = static_cast<int>(roundf(float_number * (1 << bits)));
	std::cout << "Float constructor called" << std::endl;
}

/* --- Method --- */
int Fixed::getRawBits() const
{
	return (this->value);
}

void Fixed::setRawBits(const int raw)
{
	this->value = raw;
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->value) / (1 << bits));
}


int Fixed::toInt( void ) const
{
	return (this->value >> bits);
}

/* --- Overload Operator --- */
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
