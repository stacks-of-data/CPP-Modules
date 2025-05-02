/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:19:24 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/03 00:58:34 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Form.hpp>
#include <Bureaucrat.hpp>
#include <iostream>

Form::Form(): _name(DEFAULT_FORM_NAME), _bSigned(DEFAULT_FORM_SIGNED),
	_gradeToSign(DEFAULT_FORM_GRADETOSIGN), _gradeToExec(DEFAULT_FORM_GRADETOEXEC)
{
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw Form::GradeTooLowException();
	else if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form& obj): _name(obj.getName()), _bSigned(obj.getIsSigned()),
	_gradeToSign(obj.getGradeToSign()), _gradeToExec(obj.getGradeToExec())
{
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw Form::GradeTooLowException();
	else if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const std::string& name, const bool bSigned,
	const uint8_t gradeToSign, const uint8_t gradeToExec): _name(name), _bSigned(bSigned),
	_gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw Form::GradeTooLowException();
	else if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw Form::GradeTooHighException();
}

Form::~Form()
{
}

const std::string&	Form::getName() const
{
	return (this->_name);
}

bool	Form::getIsSigned() const
{
	return (this->_bSigned);
}

uint8_t	Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

uint8_t	Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

void	Form::beSigned(const Bureaucrat& obj)
{
	uint8_t	bureaucratGrade = obj.getGrade();
	if (bureaucratGrade > 150)
		throw Form::GradeTooLowException();
	else if (bureaucratGrade < 1)
		throw Form::GradeTooHighException();
	if (this->_bSigned == true)
	{
		std::cout << this->_name << " is already signed" << std::endl;
		return;
	}
	if (bureaucratGrade <= this->_gradeToSign)
	{
		this->_bSigned = true;
		std::cout << obj.getName() << " signed " << this->_name << std::endl;
	}
	else
		std::cout << obj.getName() << " couldn't sign " << this->_name << " because grade is too low" << std::endl;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Form::GradeTooHighException");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Form::GradeTooLowException");
}

Form&	Form::operator=(const Form& obj)
{
	(void)obj;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Form& obj)
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
	os << "\n-------------------------" << std::endl;
	return (os);
}