/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:10:37 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/03 23:47:13 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include <string>
#include <exception>

#define INTERN_FORM_P_NAME "Presidential Pardon"
#define INTERN_FORM_R_NAME "Robotomy Request"
#define INTERN_FORM_S_NAME "Shrubbery Creation"

class Intern
{
	private:
	std::string	_forms_names[3];
	int	getFormIndex(const std::string& name);
	public:
	Intern();
	Intern(const Intern& obj);
	~Intern();
	AForm*	makeForm(const std::string& name, const std::string& target);
	Intern&	operator=(const Intern& obj);
	class FormCreationFailure: public std::exception
	{
		const char*	what() const throw();	
	};
};