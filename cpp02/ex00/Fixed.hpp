/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:03:28 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/14 22:59:05 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
	int	val;
	static const int fractBits = 8;
	public:
	Fixed();
	Fixed(const Fixed& obj);
	~Fixed();
	int	getRawBits(void) const;
	void	setRawBits(const int raw);
	Fixed& operator = (const Fixed& obj);
};

#endif