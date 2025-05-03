/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:16:34 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/04 00:52:46 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void	delObjs(const Bureaucrat* obj1, const AForm* obj2, const AForm *obj3, const AForm *obj4)
{
	delete obj1;
	delete obj2;
	delete obj3;
	delete obj4;
}

int main()
{
	Intern		randomIntern;
	Bureaucrat	*b_obj = 0;
	AForm		*f_obj = 0;
	AForm		*f2_obj = 0;
	AForm		*f3_obj = 0;
	std::srand(std::time(NULL));
	try
	{
		b_obj = new Bureaucrat(std::string("Steve"), 1);
		f_obj = randomIntern.makeForm(INTERN_FORM_S_NAME, "home");
		f2_obj = randomIntern.makeForm(INTERN_FORM_R_NAME, "LOL");
		f3_obj = randomIntern.makeForm(INTERN_FORM_P_NAME, "Eric");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		delObjs(b_obj, f_obj, f2_obj, f3_obj);
		return (EXIT_FAILURE);
	}
	catch (...)
	{
		std::cerr << "Unexcpected exception" << std::endl;
		delObjs(b_obj, f_obj, f2_obj, f3_obj);
		return (EXIT_FAILURE);
	}
	std::cout << *b_obj << std::endl;
	std::cout << *f_obj << std::endl;
	std::cout << *f2_obj << std::endl;
	std::cout << *f3_obj << std::endl;
	b_obj->signForm(*f_obj);
	b_obj->executeForm(*f_obj);
	b_obj->signForm(*f2_obj);
	b_obj->executeForm(*f2_obj);
	b_obj->signForm(*f3_obj);
	b_obj->executeForm(*f3_obj);
	delObjs(b_obj, f_obj, f2_obj, f3_obj);
	try
	{
		AForm *test = randomIntern.makeForm("LOL", "LOL");
		(void)test;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Unexpected exception" << std::endl;
	}
	return (EXIT_SUCCESS);
}
