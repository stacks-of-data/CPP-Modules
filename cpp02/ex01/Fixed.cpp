/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:03:07 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/08 19:29:57 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->val = 0;
}

Fixed::Fixed(const Fixed& obj)
{
	std::cout << "Copy constructor called\n";
	*this = obj;
}

Fixed::Fixed(const int iVal)
{
	std::cout << "Int constructor called\n";
	this->val = iVal << this->fractBits;
}

Fixed::Fixed(const float fVal)
{
	std::cout << "Float constructor called\n";
	this->val = roundf(fVal * (1 << this->fractBits));
}

int	Fixed::toInt() const
{
	return (this->val >> this->fractBits);
}

float	Fixed::toFloat() const
{
	return ((float)this->val / (1 << this->fractBits));
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

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called\n";
	this->val = raw;
}

Fixed& Fixed::operator= (const Fixed& obj) {
	std::cout << "Copy assignment operator called\n";
	this->val = obj.val;
	return (*this);
}

std::ostream& operator<< (std::ostream &os, const Fixed& obj) {
	os << obj.toFloat();
	return (os);
}