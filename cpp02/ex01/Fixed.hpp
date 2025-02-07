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
	Fixed(const int iVal);
	~Fixed();
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	int	toInt();
	Fixed& operator= (Fixed& obj);
	Fixed& operator<< (Fixed& obj);
};

#endif