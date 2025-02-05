#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed& obj)
{
	std::cout << "Default constructor called\n";
	this->val = obj.val;
	this->setRawBits(obj.getRawBits());
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}