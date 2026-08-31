
#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
	private:
		int	value;
		static const int bits = 8;
	public:
		/* --- Constructor --- */
		Fixed();							// Default constructor
		~Fixed();							// Destructor
		Fixed(const Fixed&);				// Copy constructor
		Fixed &operator=(const Fixed&);		// Copy assignement constructor

		/* --- Method --- */
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
