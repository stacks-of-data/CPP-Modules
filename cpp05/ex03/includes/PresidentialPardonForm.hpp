/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:16:55 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/03 23:53:37 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#define DEFAULT_FORM_P_NAME "Presidential Pardon"
#define DEFAULT_FORM_P_TARGET "DEFAULT_TARGET"
#define FORM_P_SIGN_GRADE 25
#define FORM_P_EXEC_GRADE 5
#include <string>
#include "../includes/AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
	PresidentialPardonForm	operator=(PresidentialPardonForm& obj);
	public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& obj);
	~PresidentialPardonForm();
	void	execute(const Bureaucrat& executor) const;
};

#endif