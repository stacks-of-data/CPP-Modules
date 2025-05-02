/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:16:34 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/03 02:26:23 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include <iostream>
#include <cstdlib>

void	delObjs(Bureaucrat* obj1, Bureaucrat* obj2, Form* obj3, Form* obj4)
{
	delete obj1;
	delete obj2;
	delete obj3;
	delete obj4;
}

void	attemptSign(Bureaucrat *b_obj, Form *f_obj)
{
	try
	{
		b_obj->signForm(*f_obj);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Unexcpected exception" << std::endl;
	}
}

int main()
{
	Bureaucrat	*b_obj = 0;
	Bureaucrat	*b2_obj = 0;
	Form		*f_obj = 0;
	Form		*f2_obj = 0;
	try
	{
		b_obj = new Bureaucrat();
		b2_obj = new Bureaucrat(std::string("Steve"), 11);
		f_obj = new Form(std::string("LOL"), false, 10, 10);
		f2_obj = new Form(std::string("IDK"), false, 1, 1);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		delObjs(b_obj, b2_obj, f_obj, f2_obj);
		return (EXIT_FAILURE);
	}
	catch (...)
	{
		std::cerr << "Unexcpected exception" << std::endl;
		delObjs(b_obj, b2_obj, f_obj, f2_obj);
		return (EXIT_FAILURE);
	}
	std::cout << *b_obj << std::endl;
	std::cout << *f_obj << std::endl;
	attemptSign(b_obj, f_obj);
	std::cout << *f_obj << std::endl;
	attemptSign(b_obj, f_obj);
	std::cout << *b2_obj << std::endl;
	std::cout << *f2_obj << std::endl;
	attemptSign(b2_obj, f2_obj);
	delObjs(b_obj, b2_obj, f_obj, f2_obj);
	return (EXIT_SUCCESS);
}
