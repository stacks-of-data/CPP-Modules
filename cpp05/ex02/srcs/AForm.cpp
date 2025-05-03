/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:19:24 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/03 22:42:09 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include <iostream>

AForm::AForm(): _name(DEFAULT_FORM_NAME), _bSigned(DEFAULT_FORM_SIGNED),
	_gradeToSign(DEFAULT_FORM_GRADETOSIGN), _gradeToExec(DEFAULT_FORM_GRADETOEXEC), _target(DEFAULT_FORM_TARGET)
{
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw AForm::GradeTooLowException();
	else if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& obj): _name(obj.getName()), _bSigned(obj.getIsSigned()),
	_gradeToSign(obj.getGradeToSign()), _gradeToExec(obj.getGradeToExec()), _target(obj.getTarget())
{
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw AForm::GradeTooLowException();
	else if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const std::string& name, const bool bSigned,
	const uint8_t gradeToSign, const uint8_t gradeToExec, const std::string& target): _name(name), _bSigned(bSigned),
	_gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _target(target)
{
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw AForm::GradeTooLowException();
	else if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw AForm::GradeTooHighException();
}

const std::string&	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getIsSigned() const
{
	return (this->_bSigned);
}

uint8_t	AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

uint8_t	AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}

const std::string&	AForm::getTarget() const
{
	return (this->_target);
}

void	AForm::beSigned(const Bureaucrat& obj)
{
	uint8_t	bureaucratGrade = obj.getGrade();
	if (bureaucratGrade > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	if (this->_bSigned == true)
	{
		std::cout << this->_name << " is already signed" << std::endl;
		return;
	}
	this->_bSigned = true;
	std::cout << obj.getName() << " signed " << this->_name << std::endl;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("AForm::GradeTooHighException");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("AForm::GradeTooLowException");
}

const char*	AForm::FormNotSigned::what() const throw()
{
	return ("AForm::FormNotSigned");
}

AForm&	AForm::operator=(const AForm& obj)
{
	(void)obj;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const AForm& obj)
{
	std::string	status;

	if (obj.getIsSigned())
		status = "True";
	else
		status = "False";
	
	os << "-------------------------\n";
	os << "Form Name: " << obj.getName() << "\nIs Signed: " << status
		<< "\nGrade to Sign: " << (int)obj.getGradeToSign()
		<< "\nGrade to Execute: " << (int)obj.getGradeToExec();
	os << "\n-------------------------";
	return (os);
}