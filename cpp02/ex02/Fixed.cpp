/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:03:07 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/08 19:32:38 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	this->val = 0;
}

Fixed::Fixed(const Fixed& obj)
{
	*this = obj;
}

Fixed::Fixed(const int iVal)
{
	this->val = iVal << this->fractBits;
}

Fixed::Fixed(const float fVal)
{
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
}

int	Fixed::getRawBits(void) const
{
	return (this->val);
}

void	Fixed::setRawBits(const int raw)
{
	this->val = raw;
}

Fixed& Fixed::operator= (const Fixed& obj) {
	this->val = obj.val;
	return (*this);
}

std::ostream& operator<< (std::ostream &os, const Fixed& obj) {
	os << obj.toFloat();
	return (os);
}