/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:10:37 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/03 23:47:46 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
	_forms_names[0] = INTERN_FORM_S_NAME;
	_forms_names[1] = INTERN_FORM_R_NAME;
	_forms_names[2] = INTERN_FORM_P_NAME;
}

Intern::Intern(const Intern& obj)
{
	(void)obj;
	_forms_names[0] = INTERN_FORM_S_NAME;
	_forms_names[1] = INTERN_FORM_R_NAME;
	_forms_names[2] = INTERN_FORM_P_NAME;
}

Intern::~Intern()
{
}

int	Intern::getFormIndex(const std::string& name)
{
	for (int i = 0; i < 3; i++)
	{
		if (!name.compare(this->_forms_names[i]))
			return (i);
	}
	return (-1);
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{
	int	i = this->getFormIndex(name);
	AForm	*res;
	if (i == -1)
	{
		std::cerr << "Form doesn't exist." << std::endl;
		throw FormCreationFailure();
	}
	try
	{
		switch (i)
		{
			case 0:
				res = new ShrubberyCreationForm(target);
				break;
			case 1:
				res = new RobotomyRequestForm(target);
				break;
			case 2:
				res = new PresidentialPardonForm(target);
				break;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Form creation failure.\n";
		std::cerr << e.what() << std::endl;
		throw;
	}
	catch (...)
	{
		std::cerr << "Unexpected exception" << std::endl;
		throw;
	}
	std::cout << "Intern creates " << name << std::endl;
	return (res);
}

const char*	Intern::FormCreationFailure::what() const throw()
{
	return ("Intern::FormCreationFailure");
}

Intern&	Intern::operator=(const Intern& obj)
{
	(void)obj;
	_forms_names[0] = INTERN_FORM_S_NAME;
	_forms_names[1] = INTERN_FORM_R_NAME;
	_forms_names[2] = INTERN_FORM_P_NAME;
	return (*this);
}