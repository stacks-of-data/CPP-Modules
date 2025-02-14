/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:03:07 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/15 00:07:16 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : val(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(const int iVal) : val(iVal << this->fractBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fVal) : val(roundf(fVal * (1 << this->fractBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

int	Fixed::toInt() const
{
	return (this->val >> this->fractBits);
}

float	Fixed::toFloat() const
{
	return (static_cast<float>(this->val) / (1 << this->fractBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->val);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->val = raw;
}

Fixed& Fixed::operator= (const Fixed& obj) {
	this->val = obj.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

std::ostream& operator<< (std::ostream &os, const Fixed& obj) {
	os << obj.toFloat();
	return (os);
}