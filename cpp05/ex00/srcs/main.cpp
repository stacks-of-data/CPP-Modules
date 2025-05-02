/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:16:34 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/02 22:07:14 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <iostream>

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
	Bureaucrat	obj(std::string("John"), 1);
	Bureaucrat	obj2(std::string("Steve"), 150);
	Bureaucrat	obj3(std::string("Eric"), 100);
	std::cout << obj;
	attempt_IncDec(obj, 0);
	std::cout << obj;
	std::cout << obj2;
	attempt_IncDec(obj2, 1);
	std::cout << obj2;
	std::cout << obj3;
	attempt_IncDec(obj3, 1);
	std::cout << obj3;
}
