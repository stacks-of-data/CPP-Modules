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
	void	setRawBits(int const raw);
	Fixed& operator = (Fixed& obj);
};

#endif