/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:03:18 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/09 16:20:33 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
	int	val;
	static const int fractBits = 8;
	public:
	Fixed();
	Fixed(const Fixed& obj);
	Fixed(const int iVal);
	Fixed(const float fVal);
	~Fixed();
	int	getRawBits(void) const;
	void	setRawBits(const int raw);
	int	toInt() const;
	float	toFloat() const;
	Fixed& operator= (const Fixed& obj);
	bool operator> (const Fixed& obj) const;
	bool operator< (const Fixed& obj) const;
	bool operator>= (const Fixed& obj) const;
	bool operator<= (const Fixed& obj) const;
	bool operator== (const Fixed& obj) const;
	bool operator!= (const Fixed& obj) const;
	Fixed operator+ (const Fixed& obj) const;
	Fixed operator- (const Fixed& obj) const;
	Fixed operator* (const Fixed& obj) const;
	Fixed operator/ (const Fixed& obj) const;
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);
	static Fixed&	min(Fixed& objX, Fixed& objY);
	static Fixed&	min(const Fixed& objX, const Fixed& objY);
	static Fixed&	max(Fixed& objX, Fixed& objY);
	static Fixed&	max(const Fixed& objX, const Fixed& objY);
};

std::ostream& operator<< (std::ostream &os, const Fixed& obj);

#endif