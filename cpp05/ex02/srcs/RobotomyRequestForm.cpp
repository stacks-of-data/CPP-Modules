/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:47:14 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/03 22:59:08 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <ctime>
#include <iostream>
#include <unistd.h>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm():
	AForm(DEFAULT_FORM_R_NAME, DEFAULT_FORM_SIGNED, FORM_R_SIGN_GRADE, FORM_R_EXEC_GRADE, DEFAULT_FORM_R_TARGET)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	AForm(DEFAULT_FORM_R_NAME, DEFAULT_FORM_SIGNED, FORM_R_SIGN_GRADE, FORM_R_EXEC_GRADE, target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& obj):
	AForm(obj.getName(), obj.getIsSigned(), obj.getGradeToSign(), obj.getGradeToExec(), obj.getTarget())
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSigned();
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	std::cout << "Attempting robotomy...\a" << std::endl;
	sleep(1);
	std::cout << "\a";
	bool res = std::rand() % 2;
	if (!res)
	{
		std::cerr << "Robotomy failed." << std::endl;
		throw RobotomyRequestForm::RobotomyFailure();
	}
	std::cout << this->getTarget() << " has been robotomized." << std::endl;
}

const char*	RobotomyRequestForm::RobotomyFailure::what() const throw()
{
	return ("RobotomyRequestForm::RobotomyFailure");
}

RobotomyRequestForm	RobotomyRequestForm::operator=(RobotomyRequestForm& obj)
{
	(void)obj;
	return (*this);
}