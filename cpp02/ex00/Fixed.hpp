/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:03:28 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/08 13:34:00 by amsaleh          ###   ########.fr       */
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
	Fixed(Fixed& obj);
	~Fixed();
	int	getRawBits(void) const;
	void	setRawBits(const int raw);
	Fixed& operator = (Fixed& obj);
};

#endif