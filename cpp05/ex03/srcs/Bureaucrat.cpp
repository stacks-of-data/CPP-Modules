/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:17:03 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/04 00:58:41 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(): _name(DEFAULT_BUREAUCRAT_NAME), _grade(DEFAULT_BUREAUCRAT_GRADE)
{
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj): _name(obj.getName()), _grade(obj.getGrade())
{
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const std::string& name, const uint8_t grade): _name(name), _grade(grade)
{
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
}

const std::string&	Bureaucrat::getName() const
{
	return (this->_name);
}

uint8_t	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::gradeInc()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::gradeDec()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm(AForm& obj) const
{
	if (obj.getIsSigned())
	{
		std::cout << obj.getName() << " is already signed" << std::endl;
		return;
	}
	try
	{
		obj.beSigned(*this);
		std::cout << this->_name << " signed " << obj.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign " << obj.getName()
			<< " because " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << this->_name << " couldn't sign " << obj.getName()
			<< " because " << "unexpected exception" << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << "\nForm execution failed." << std::endl;
	}
	catch (...)
	{
		std::cerr << "Unexpected exception\nExecution failed." << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat::GradeTooHighException");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat::GradeTooLowException");
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	(void)obj;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << (int)obj.getGrade() << ".";
	return (os);
}