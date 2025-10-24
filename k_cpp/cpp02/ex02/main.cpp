#include "Fixed.hpp"

#include <iostream>


#include "Fixed.hpp"
#include <iostream>

int main() {
	std::cout << "=== Constructor Tests ===" << std::endl;
	Fixed a;                    // Default constructor
	Fixed b(5.5f);              // Float constructor
	Fixed c(3);                 // Int constructor
	Fixed d(b);                // Copy constructor

	std::cout << "\na = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	std::cout << "\n=== Assignment Test ===" << std::endl;
	a = c;
	std::cout << "a (after assignment) = " << a << std::endl;

	std::cout << "\n=== Comparison Operators ===" << std::endl;
	std::cout << "b > c  = " << (b > c) << std::endl;
	std::cout << "b < c  = " << (b < c) << std::endl;
	std::cout << "b >= d = " << (b >= d) << std::endl;
	std::cout << "b <= d = " << (b <= d) << std::endl;
	std::cout << "b == d = " << (b == d) << std::endl;
	std::cout << "b != d = " << (b != d) << std::endl;

	std::cout << "\n=== Arithmetic Operators ===" << std::endl;
	std::cout << "b + c = " << (b + c) << std::endl;
	std::cout << "b - c = " << (b - c) << std::endl;
	std::cout << "b * c = " << (b * c) << std::endl;
	std::cout << "b / c = " << (b / c) << std::endl;

	std::cout << "\n=== Increment/Decrement Operators ===" << std::endl;
	Fixed e;
	std::cout << "e = " << e << std::endl;
	std::cout << "++e = " << ++e << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "e++ = " << e++ << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "--e = " << --e << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "e-- = " << e-- << std::endl;
	std::cout << "e = " << e << std::endl;

	std::cout << "\n=== Min/Max Tests ===" << std::endl;
	Fixed& minRef = Fixed::min(a, b);
	const Fixed& minConst = Fixed::min(c, d);
	std::cout << "min(a, b) = " << minRef << std::endl;
	std::cout << "min(c, d) = " << minConst << std::endl;

	Fixed& maxRef = Fixed::max(a, b);
	const Fixed& maxConst = Fixed::max(c, d);
	std::cout << "max(a, b) = " << maxRef << std::endl;
	std::cout << "max(c, d) = " << maxConst << std::endl;

	std::cout << "\n=== Conversion Functions ===" << std::endl;
	std::cout << "b.toInt() = " << b.toInt() << std::endl;
	std::cout << "c.toFloat() = " << c.toFloat() << std::endl;

	return 0;
}
