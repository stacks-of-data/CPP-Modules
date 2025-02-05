#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->val = 0;
}

Fixed::Fixed(Fixed& obj)
{
	std::cout << "Copy constructor called\n";
	*this = obj;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->val);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->val = raw;
}

Fixed& Fixed::operator= (Fixed& obj) {
	std::cout << "Copy assignment operator called\n";
	this->val = obj.getRawBits();
	return (*this);
}