/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:19:21 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/03 22:40:59 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#define DEFAULT_FORM_NAME "DEFAULT_NAME"
#define DEFAULT_FORM_TARGET "DEFAULT_TARGET"
#define DEFAULT_FORM_SIGNED false
#define DEFAULT_FORM_GRADETOSIGN 42
#define DEFAULT_FORM_GRADETOEXEC 42
#include <ostream>
#include <exception>
#include <string>
#include <stdint.h>

class Bureaucrat;

class AForm
{
	private:
	const std::string	_name;
	bool				_bSigned;
	const uint8_t		_gradeToSign;
	const uint8_t		_gradeToExec;
	std::string			_target;
	AForm&	operator=(const AForm& obj);
	protected:
	AForm();
	AForm(const AForm& obj);
	AForm(const std::string& name, const bool bSigned,
		const uint8_t gradeToSign, const uint8_t gradeToExec, const std::string& target);
	public:
	virtual ~AForm() {};
	const std::string&	getName() const;
	bool				getIsSigned() const;
	uint8_t				getGradeToSign() const;
	uint8_t				getGradeToExec() const;
	const std::string&	getTarget() const;
	void				beSigned(const Bureaucrat& obj);
	virtual void		execute(const Bureaucrat& executor) const = 0;
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
	class FormNotSigned: public std::exception
	{
		public:
		const char*	what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, const AForm& obj);

#endif