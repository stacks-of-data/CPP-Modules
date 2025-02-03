#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;
	if (ac < 2)
		return (0);
	std::string level = av[1];
	harl.complain(level);
	return (0);
}