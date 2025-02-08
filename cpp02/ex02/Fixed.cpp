/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:03:07 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/09 01:12:22 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : val(0) {}

Fixed::Fixed(const Fixed &obj) {
	*this = obj;
}

Fixed::Fixed(const int iVal) : val(iVal << this->fractBits) {}

Fixed::Fixed(const float fVal) : val(roundf(fVal * (1 << this->fractBits))) {}

int Fixed::toInt() const {
	return (this->val >> this->fractBits);
}

float Fixed::toFloat() const {
	return (static_cast<float>(this->val) / (1 << this->fractBits));
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
	return (this->val);
}

void Fixed::setRawBits(const int raw) {
	this->val = raw;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	this->val = obj.val;
	return (*this);
}

bool Fixed::operator>(const Fixed &obj) const {
	return (this->val > obj.getRawBits());
}

bool Fixed::operator<(const Fixed &obj) const {
	return (this->val < obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj) const {
	return (this->val >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj) const {
	return (this->val <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj) const {
	return (this->val == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj) const {
	return (this->val != obj.getRawBits());
}

Fixed Fixed::operator+(const Fixed &obj) const {
	Fixed newObj;
	newObj.setRawBits(this->val + obj.getRawBits());
	return (newObj);
}

Fixed Fixed::operator-(const Fixed &obj) const {
	Fixed newObj;
	newObj.setRawBits(this->val - obj.getRawBits());
	return (newObj);
}

Fixed Fixed::operator*(const Fixed &obj) const {
	long long newVal = static_cast<long long>(this->val) * obj.getRawBits();
	newVal >>= this->fractBits;
	Fixed newObj;
	newObj.setRawBits(static_cast<int>(newVal));
	return (newObj);
}


Fixed Fixed::operator/(const Fixed &obj) const {
	Fixed newObj;
	if (!obj.getRawBits() || !this->val)
	{
		newObj.setRawBits(0);
		return (newObj);
	}
	newObj.setRawBits((this->val << this->fractBits) / obj.getRawBits());
	return (newObj);
}

Fixed& Fixed::operator++() {
	this->val++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed newObj = *this;
	operator++();
	return (newObj);
}

Fixed& Fixed::operator--() {
	this->val--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed newObj = *this;
	operator--();
	return (newObj);
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}