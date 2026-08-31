#include "Fixed.hpp"

/* --- CONSTRUCTOR --- */
Fixed::Fixed()
{
	this->value = 0;
}

Fixed::~Fixed()
{
	this->value = 0;
}

Fixed::Fixed(const Fixed& cpy)
{
	if (this != &cpy)
		*this = cpy;
}

Fixed &Fixed::operator=(const Fixed& cpy)
{
	if (this != &cpy)
		this->value = cpy.getRawBits();
	return (*this);
}

Fixed::Fixed(const int int_number)
{
	value = int_number << bits;
}

Fixed::Fixed(const float float_number)
{
	this->value = static_cast<int>(lround(float_number * (1 << bits)));
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
Fixed Fixed::operator+(const Fixed &n)
{
	Fixed	tmp;

	tmp.value = (this->toInt()<< this->getRawBits()) + (n.toInt() << getRawBits());
	return (tmp);
}

Fixed Fixed::operator-(const Fixed &n)
{
	Fixed	tmp;

	tmp.value = (this->toInt()<< this->getRawBits()) - (n.toInt() << getRawBits());
	return (tmp);
}

Fixed Fixed::operator*(const Fixed &n)
{
	Fixed	tmp;

	tmp.value = (this->value * n.getRawBits()) / 256;
	return (tmp);
}

Fixed Fixed::operator/(const Fixed &n)
{
	Fixed	tmp;


	if (n.value == 0)
		tmp.value = 0;
	else
		tmp.value = (this->value * 256) / n.getRawBits();
	return (tmp);
}

Fixed Fixed::operator>(const Fixed& n)
{
	if (this->toFloat() > n.toFloat())
		return (true);
	else
		return (false);
}

Fixed Fixed::operator<(const Fixed& n)
{
	if (this->toFloat() < n.toFloat())
		return (true);
	else
		return (false);
}

Fixed Fixed::operator>=(const Fixed& n)
{
	if (this->toFloat() >= n.toFloat())
		return (true);
	else
		return (false);
}

Fixed Fixed::operator<=(const Fixed& n)
{
	if (this->toFloat() <= n.toFloat())
		return (true);
	else
		return (false);
}

Fixed Fixed::operator==(const Fixed& n)
{
	if (this->toFloat() == n.toFloat())
		return (true);
	else
		return (false);
}

Fixed Fixed::operator!=(const Fixed& n)
{
	if (this->toFloat() != n.toFloat())
		return (true);
	else
		return (false);
}

Fixed &Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1.toFloat() < ref2.toFloat())
		return (ref1);
	else
		return (ref2);
}

const Fixed &Fixed::min(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1.toFloat() < ref2.toFloat())
		return (ref1);
	else
		return (ref2);
}

Fixed &Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1.toFloat() > ref2.toFloat())
		return (ref1);
	else
		return (ref2);
}

const Fixed &Fixed::max(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1.toFloat() > ref2.toFloat())
		return (ref1);
	else
		return (ref2);
}

Fixed	Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	this->value++;
	return (tmp);
}

Fixed	Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	this->value--;
	return (tmp);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

int main(void)
{
	Fixed	a;
	Fixed	b(3.14f);
	Fixed	c(23);

	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "c : " << c << std::endl << std::endl;
	std::cout << "++a : " << ++a << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "a++ : " << a++ << std::endl;
	std::cout << "b + 3 : " << b + 3 << std::endl;
	std::cout << "b * 0.33 : " << b * 0.3f << std::endl;
	std::cout << "b / 0.33 : " << b / 0.3f << std::endl;
	std::cout << "b - 0.33 : " << b - 0.3f << std::endl;
	std::cout << "--c : " << --c << std::endl;
	std::cout << "c-- : " << c-- << std::endl;
	std::cout << "c : " << c << std::endl << std::endl ;
	std::cout << "b (" << b << ") < c (" << c << ") : " << (b < c) << std::endl;
	std::cout << "b (" << b << ") > c (" << c << ") : " << (b > c) << std::endl;
	std::cout << "b (" << b << ") == c (" << c << ") : " << (b == c) << std::endl;
	std::cout << "b (" << b << ") != c (" << c << ") : " << (b != c) << std::endl;
}
