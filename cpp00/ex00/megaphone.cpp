#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
        return (0);
    }
    std::string	str = av[1];
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isupper(str[i]))
			str.replace(i, 1, 1, toupper(str[i]));
	}
    std::cout << str << "\n";
    return (0);
}