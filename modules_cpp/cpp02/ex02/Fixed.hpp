
#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int	value;
		static const int bits = 8;
	public:
		/* --- Constructor --- */
		Fixed();							// Default constructor
		~Fixed();							// Destructor
		Fixed(const int int_number);		// Int onstructor
		Fixed(const float float_number);	// Float constructor
		Fixed(const Fixed&);				// Copy constructor
		Fixed &operator=(const Fixed&);		// Copy assignement constructor

		/* --- Overload operator --- */
		Fixed operator+(const Fixed&);
		Fixed operator-(const Fixed&);
		Fixed operator*(const Fixed&);
		Fixed operator/(const Fixed&);
		Fixed operator>(const Fixed&);
		Fixed operator<(const Fixed&);
		Fixed operator>=(const Fixed&);
		Fixed operator<=(const Fixed&);
		Fixed operator==(const Fixed&);
		Fixed operator!=(const Fixed&);
		Fixed operator++(void);				// Pre-incrementation overload
		Fixed operator++(int);				// Post-incrementation overload
		Fixed operator--(void);				// Pre-decrementation overload
		Fixed operator--(int);				// Post-decrementation overload

		/* --- Method --- */
		static Fixed	&min(Fixed &ref1, Fixed &ref2);
		static Fixed	&max(Fixed &ref1, Fixed &ref2);
		static const Fixed	&min(const Fixed &ref1, const Fixed &ref2);
		static const Fixed	&max(const Fixed &ref1, const Fixed &ref2);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream& os, const Fixed& fixed);

#endif
