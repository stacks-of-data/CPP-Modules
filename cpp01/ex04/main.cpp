#include <iostream>
#include <fstream>
#include <string>

int	checkArgs(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Correct usage: sed filename s1 s2\n";
		return (0);
	}
	std::string	filename = av[1];
	std::string	s1 = av[2];
	if (filename.empty())
	{
		std::cout << "File argument is empty!\n";
		return (0);
	}
	if (s1.empty())
	{
		std::cout << "s1 argument is empty!\n";
		return (0);
	}
	return (1);
}

int main(int ac, char **av)
{
	if (!checkArgs(ac, av))
		return (0);
	std::string	filename = av[1];
	std::string	s1 = av[2];
	std::ifstream	infile(filename);
	if (!infile.is_open())
	{
		std::cout << "Attempt to open " << filename << " failed!\n";
		return (0);
	}
	std::string	data = "";
	std::string	line;
	while (true)
	{
		std::getline(infile, line);
		if (infile.eof())
			break;
		data.append(line.append("\n"));
	}
	infile.close();
	std::ofstream	outfile(filename.append(".replace"));
	if (!outfile.is_open())
	{
		std::cout << "Attempt to open " << filename << " failed!\n";
		return (0);
	}
	outfile << data;
	outfile.close();
	return (0);
}