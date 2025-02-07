#include "Fixed.hpp"

int main(void)
{
	Fixed x(-8388608);
	std::cout << x.getRawBits() << "\n";
	std::cout << "x is " << x.toInt() << "\n";
	return (0);
}