/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:17:40 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/02 22:24:37 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define DEFAULT_BUREAUCRAT_GRADE 10
#define DEFAULT_BUREAUCRAT_NAME "DEFAULT_NAME"
#include <ostream>
#include <exception>
#include <string>

class Bureaucrat
{
	private:
	const std::string	_name;
	unsigned char		_grade;
	Bureaucrat&	operator=(const Bureaucrat& obj);
	public:
	Bureaucrat();
	Bureaucrat(Bureaucrat& obj);
	Bureaucrat(const std::string name, const unsigned char grade);
	~Bureaucrat();
	std::string		getName() const;
	unsigned char	getGrade() const;
	void			gradeInc();
	void			gradeDec();
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