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

std::string	sed_process(std::ifstream &infile, std::string s1, std::string s2)
{
	std::string	data = "";
	std::string	line;
	size_t		start;
	size_t		pattern_pos;
	int			last_line = 0;

	while (true)
	{
		start = 0;
		std::getline(infile, line);
		if (infile.eof())
		{
			if (line.empty())
				break;
			last_line = 1;
		}
		pattern_pos = line.find(s1);
		while (pattern_pos != std::string::npos)
		{
			if (start < pattern_pos)
			{
				data.append(line, start, pattern_pos - start);
				data.append(s2);
				start = pattern_pos + s1.length();
			}
			else
			{
				data.append(s2);
				start = pattern_pos + s1.length();
			}
			pattern_pos = line.find(s1, start);
		}
		if (start < line.length())
			data.append(line, start, line.length() - start);
		if (last_line)
			break;
		data.append("\n");
	}
	return (data);
}

int main(int ac, char **av)
{
	if (!checkArgs(ac, av))
		return (0);
	std::string	filename = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];
	std::ifstream	infile;
	infile.open(filename.c_str(), std::ifstream::in);
	if (!infile.is_open())
	{
		std::cout << "Attempt to open " << filename << " failed!\n";
		return (1);
	}
	std::string data = sed_process(infile, s1, s2);
	infile.close();
	std::ofstream	outfile;
	outfile.open(filename.append(".replace").c_str(), std::ofstream::out);
	if (!outfile.is_open())
	{
		std::cout << "Attempt to open " << filename << " failed!\n";
		return (1);
	}
	outfile << data;
	outfile.close();
	return (0);
}