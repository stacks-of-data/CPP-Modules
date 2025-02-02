#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
        return (0);
    }
    for (int i = 1; i < ac; i++)
    {
        std::string	str = av[i];
	    for (size_t j = 0; j < str.length(); j++)
	    {
		    if (!isupper(str[j]))
			    str.replace(j, 1, 1, toupper(str[j]));
	    }
        std::cout << str;
    }
    std::cout << '\n';
    return (0);
}