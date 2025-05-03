/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:22:17 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/03 23:00:38 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <ctime>
#include <iostream>
#include <unistd.h>
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm():
	AForm(DEFAULT_FORM_P_NAME, DEFAULT_FORM_SIGNED, FORM_P_SIGN_GRADE, FORM_P_EXEC_GRADE, DEFAULT_FORM_P_TARGET)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
	AForm(DEFAULT_FORM_P_NAME, DEFAULT_FORM_SIGNED, FORM_P_SIGN_GRADE, FORM_P_EXEC_GRADE, target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& obj):
	AForm(obj.getName(), obj.getIsSigned(), obj.getGradeToSign(), obj.getGradeToExec(), obj.getTarget())
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSigned();
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm	PresidentialPardonForm::operator=(PresidentialPardonForm& obj)
{
	(void)obj;
	return (*this);
}