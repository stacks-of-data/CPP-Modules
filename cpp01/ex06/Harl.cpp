#include "Harl.hpp"
#include <ctime>

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\nCurrent status is ok, system is running without any issue, \
all good and working smoothly current timestamp is: " << std::time(NULL) << "\n";
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\nWhy the system is so slow, you should improve it to be faster.\n";
}

void	Harl::warning(void)
{
	std::cerr << "[ WARNING ]\nI am not sure why this was done, it can cause issues but okay!\n";
}

void	Harl::error(void)
{
	std::cerr << "[ ERROR ]\nWHAT HAVE YOU DONE!!!!! FIX THE ISSUE!!!!\n";
}

int	getHarlFilterLevel(std::string level, std::string *levels_str)
{
	for (int i = 0; i < 4; i++)
	{
		if (!level.compare(levels_str[i]))
			return (i);
	}
	return (-1);
}

void	Harl::complain(std::string level)
{
	std::string	levels_str[] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};
	void	(Harl::*methods_ptr[])(void) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
	};
	int level_i = getHarlFilterLevel(level, levels_str);
	switch (level_i)
	{
		case -1:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
		case 0:
			(this->*methods_ptr[0])();
		case 1:
			(this->*methods_ptr[1])();
		case 2:
			(this->*methods_ptr[2])();
		case 3:
			(this->*methods_ptr[3])();
	}
}

Harl::Harl()
{
}

Harl::~Harl()
{
}