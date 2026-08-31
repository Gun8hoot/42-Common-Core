
#ifndef FIXED_H
# define FIXED_H

class Fixed
{
	private:
		int value;
		static const int bits;
	public:
		Fixed(int value);						// CONSTRUCTOR
		Fixed(const Fixed& value);				// COPY-CONSTRUCTOR
		Fixed& operator=(const Fixed& value);	// COPY-ASSIGNEMENTS
		~Fixed();								// DESTRUCTOR
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
