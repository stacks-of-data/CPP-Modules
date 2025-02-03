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

void	Harl::complain(std::string level)
{
	std::string	levels_str[] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};
	void	(Harl::*methods_ptr[])(void) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
	};
	for (int i = 0; i < 4; i++)
	{
		if (!levels_str[i].compare(level))
		{
			(this->*methods_ptr[i])();
			return;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]\n";
}

Harl::Harl()
{
}

Harl::~Harl()
{
}