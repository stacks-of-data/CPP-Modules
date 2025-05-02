/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:19:21 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/03 00:58:39 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#define DEFAULT_FORM_NAME "DEFAULT_NAME"
#define DEFAULT_FORM_SIGNED false
#define DEFAULT_FORM_GRADETOSIGN 42
#define DEFAULT_FORM_GRADETOEXEC 42
#include <ostream>
#include <exception>
#include <string>
#include <stdint.h>

class Bureaucrat;

class Form
{
	private:
	const std::string	_name;
	bool				_bSigned;
	const uint8_t		_gradeToSign;
	const uint8_t		_gradeToExec;
	Form&	operator=(const Form& obj);
	public:
	Form();
	Form(const Form& obj);
	Form(const std::string& name, const bool bSigned,
		const uint8_t gradeToSign, const uint8_t gradeToExec);
	~Form();
	const std::string&	getName() const;
	bool				getIsSigned() const;
	uint8_t				getGradeToSign() const;
	uint8_t				getGradeToExec() const;
	void				beSigned(const Bureaucrat& obj);
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

std::ostream&	operator<<(std::ostream& os, const Form& obj);

#endif