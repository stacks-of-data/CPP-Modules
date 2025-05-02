/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:16:34 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/03 01:10:44 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

void	delObjs(Bureaucrat *obj1, Bureaucrat *obj2, Bureaucrat *obj3)
{
	delete obj1;
	delete obj2;
	delete obj3;
}

void	attempt_IncDec(Bureaucrat& obj, int mode)
{
	try
	{
		if (!mode)
			obj.gradeInc();
		else
			obj.gradeDec();
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main()
{
	Bureaucrat	*obj = 0;
	Bureaucrat	*obj2 = 0;
	Bureaucrat	*obj3 = 0;
	try
	{
		obj = new Bureaucrat(std::string("John"), 1);
		obj2 = new Bureaucrat(std::string("Steve"), 150);
		obj3 = new Bureaucrat(std::string("Eric"), 100);
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
		delObjs(obj, obj2, obj3);
		return (EXIT_FAILURE);
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
		delObjs(obj, obj2, obj3);
		return (EXIT_FAILURE);
	}
	
	std::cout << *obj;
	attempt_IncDec(*obj, 0);
	std::cout << *obj;
	std::cout << *obj2;
	attempt_IncDec(*obj2, 1);
	std::cout << *obj2;
	std::cout << *obj3;
	attempt_IncDec(*obj3, 1);
	std::cout << *obj3;
	delObjs(obj, obj2, obj3);
	return (EXIT_SUCCESS);
}
