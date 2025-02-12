/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:03:18 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/12 17:32:20 by amsaleh          ###   ########.fr       */
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
};

std::ostream& operator<< (std::ostream &os, const Fixed& obj);

#endif