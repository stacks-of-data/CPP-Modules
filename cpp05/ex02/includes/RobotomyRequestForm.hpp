/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:42:59 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/03 23:54:42 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#define DEFAULT_FORM_R_NAME "Robotomy Request"
#define DEFAULT_FORM_R_TARGET "DEFAULT_TARGET"
#define FORM_R_SIGN_GRADE 72
#define FORM_R_EXEC_GRADE 45
#include <exception>
#include <string>
#include "../includes/AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
	RobotomyRequestForm	operator=(RobotomyRequestForm& obj);
	public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& obj);
	~RobotomyRequestForm();
	void	execute(const Bureaucrat& executor) const;
	class RobotomyFailure: public std::exception
	{
		public:
		const char* what() const throw();
	};
};

#endif