
#include "whatever.hpp"
#include <iostream>

int main(void)
{
	int a = 1;
	int b = 444;

	std::cout << "// SWAP \\\\" << std::endl;
	std::cout	<< "a = " << a << std::endl
				<< "b = " << b << std::endl;

	swap(a, b);
	std::cout << std::endl;

	std::cout	<< "a = " << a << std::endl
				<< "b = " << b << std::endl << std::endl;

	std::cout << "// MINIMAL \\\\" << std::endl;
	std::cout	<< "a = " << a << std::endl
				<< "b = " << b << std::endl
				<< min(a, b) << " is the lowest value" << std::endl << std::endl;
	std::cout << "// MAXIMAL \\\\" << std::endl;
	std::cout	<< "a = " << a << std::endl
				<< "b = " << b << std::endl
				<< max(a, b) << " is the highest value" << std::endl;
}

// int main( void ) {
// 	int a = 2;
// 	int b = 3;
// 	::swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// 	return 0;
// }
