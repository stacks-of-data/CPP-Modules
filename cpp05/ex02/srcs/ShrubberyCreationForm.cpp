/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:11:48 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/03 22:59:19 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <dirent.h>
#include <sys/stat.h>
#include <cstring>
#include <iostream>
#include <fstream>

void	appendTreeStructure(std::string& str, int lvl, dirent *entry)
{
	while (lvl)
	{
		str.append("│   ");
		lvl--;
	}
	str.append("├──");
	str.append(entry->d_name);
	str.append("\n");
}

int	treeRecursion(DIR *dir, std::string &data, size_t lvl, std::string& dir_path)
{
	dirent	*entry = readdir(dir);
	struct stat	buf;
	while (entry)
	{
		if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, ".."))
		{
			try
			{
				std::string full_path = dir_path + entry->d_name;
				stat(full_path.c_str(), &buf);
			}
			catch (const std::exception& e)
			{
				std::cerr << e.what() << std::endl;
				closedir(dir);
				return (0);
			}
			catch (...)
			{
				std::cerr << "Unexpected exception" << std::endl;
				closedir(dir);
				return (0);
			}
			appendTreeStructure(data, lvl, entry);
			if (S_ISDIR(buf.st_mode))
			{
				try
				{
					std::string new_path(dir_path + entry->d_name + "/");
					DIR *new_dir = opendir(new_path.c_str());
					if (!new_dir)
					{
						std::cerr << "opendir: " << std::strerror(errno) << std::endl;
						closedir(dir);
						return (0);
					}
					if (!treeRecursion(new_dir, data, lvl + 1, new_path))
					{
						closedir(dir);
						return (0);
					}
				}
				catch (const std::exception& e)
				{
					std::cerr << "treeRecursion exception: " << e.what() << std::endl;
					closedir(dir);
					return (0);
				}
				catch (...)
				{
					std::cerr << "Unexcpected exception" << std::endl;
					closedir(dir);
					return (0);
				}
			}
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (1);
}

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm(DEFAULT_FORM_S_NAME, DEFAULT_FORM_SIGNED, FORM_S_SIGN_GRADE, FORM_S_EXEC_GRADE, DEFAULT_FORM_S_TARGET)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
	AForm(DEFAULT_FORM_S_NAME, DEFAULT_FORM_SIGNED, FORM_S_SIGN_GRADE, FORM_S_EXEC_GRADE, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& obj):
	AForm(obj.getName(), obj.getIsSigned(), obj.getGradeToSign(), obj.getGradeToExec(), obj.getTarget())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSigned();
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	std::string file_name;
	try
	{
		file_name.append(this->getTarget() + "_shrubbery");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		throw ShrubberyCreationForm::TreePlantingFailure();
	}
	catch (...)
	{
		std::cerr << "Unexpected exception" << std::endl;
		throw ShrubberyCreationForm::TreePlantingFailure();
	}
	std::cout << "Planting " << file_name << std::endl;
	DIR *dir = opendir(".");
	if (!dir)
	{
		std::cerr << "opendir: " << std::strerror(errno) << std::endl;
		throw ShrubberyCreationForm::TreePlantingFailure();
	}
	int	res = 0;
	std::string data;
	try
	{
		data.append(".\n");
		std::string path("./");
		res = treeRecursion(dir, data, 0, path);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		throw ShrubberyCreationForm::TreePlantingFailure();
	}
	catch (...)
	{
		std::cerr << "Unexpected exception" << std::endl;
		throw ShrubberyCreationForm::TreePlantingFailure();
	}
	if (!res)
		throw ShrubberyCreationForm::TreePlantingFailure();
	std::fstream file(file_name.c_str(), std::fstream::out);
	if (!file.is_open())
	{
		std::cerr << "Failed to create tree file" << std::endl;
    	throw ShrubberyCreationForm::TreePlantingFailure();
	}
	file << data << std::endl;
	if (file.bad())
	{
		std::cerr << "Error writing tree to file" << std::endl;
		file.close();
		throw ShrubberyCreationForm::TreePlantingFailure();
	}
	file.close();
	try
	{
		std::cout << "Tree planted!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		throw ShrubberyCreationForm::TreePlantingFailure();
	}
	catch (...)
	{
		std::cerr << "Unexpected exception" << std::endl;
		throw ShrubberyCreationForm::TreePlantingFailure();
	}
}

const char*	ShrubberyCreationForm::TreePlantingFailure::what() const throw()
{
	return ("ShrubberyCreationForm::TreePlantingFailure");
}

ShrubberyCreationForm	ShrubberyCreationForm::operator=(ShrubberyCreationForm& obj)
{
	(void)obj;
	return (*this);
}
