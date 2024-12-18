#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
        return (0);
    }
    size_t j;
    for (size_t i = 1; i < ac; i++)
    {
        j = 0;
        while (av[i][j])
        {
            if (islower(av[i][j]))
                av[i][j] = toupper(av[i][j]);
            j++;
        }
        std::cout << av[i];
    }
    std::cout << "\n";
    return (0);
}