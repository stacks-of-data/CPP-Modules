/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:17:40 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/03 22:55:47 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define DEFAULT_BUREAUCRAT_GRADE 10
#define DEFAULT_BUREAUCRAT_NAME "DEFAULT_NAME"
#include <ostream>
#include <exception>
#include <string>
#include <stdint.h>

class AForm;

class Bureaucrat
{
	private:
	const std::string	_name;
	uint8_t				_grade;
	Bureaucrat&	operator=(const Bureaucrat& obj);
	public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& obj);
	Bureaucrat(const std::string& name, const uint8_t grade);
	~Bureaucrat();
	const std::string&	getName() const;
	uint8_t				getGrade() const;
	void				gradeInc();
	void				gradeDec();
	void				signForm(AForm& obj) const;
	void				executeForm(const AForm& form) const;
	class GradeTooHighException: public std::exception
	{
		public:
		const char*	what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		public:
		const char*	what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif