/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:05:41 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/03 23:53:44 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#define DEFAULT_FORM_S_NAME "Shrubbery Creation"
#define DEFAULT_FORM_S_TARGET "DEFAULT_TARGET"
#define FORM_S_SIGN_GRADE 145
#define FORM_S_EXEC_GRADE 137
#include <exception>
#include <string>
#include "../includes/AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
	ShrubberyCreationForm	operator=(ShrubberyCreationForm& obj);
	public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& obj);
	~ShrubberyCreationForm();
	void	execute(const Bureaucrat& executor) const;
	class TreePlantingFailure: public std::exception
	{
		public:
		const char*	what() const throw();
	};
};

#endif