/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 02:14:17 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/06 02:55:16 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base_utils.hpp"

Base*	generate(void)
{
	int iRand = rand() % 3;
	Base*	ptr;

	switch (iRand)
	{
		case 0:
			ptr = new A();
			return (ptr);
		case 1:
			ptr = new B();
			return (ptr);
		case 2:
			ptr = new C();
			return (ptr);
	}
	return (0);
}

void	identify(Base* p)
{
	A* ptr_a = dynamic_cast<A*>(p);
	if (ptr_a)
	{
		static_cast<void>(ptr_a);
		std::cout << "PTR is pointing to class A" << std::endl;
		return;
	}
	B* ptr_b = dynamic_cast<B*>(p);
	if (ptr_b)
	{
		static_cast<void>(ptr_b);
		std::cout << "PTR is pointing to class B" << std::endl;
		return;
	}
	C* ptr_c = dynamic_cast<C*>(p);
	if (ptr_c)
	{
		static_cast<void>(ptr_c);
		std::cout << "PTR is pointing to class C" << std::endl;
		return;
	}
	std::cerr << "Unknown PTR type" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& ref_a = dynamic_cast<A&>(p);
		static_cast<void>(ref_a);
		std::cout << "REF is referencing data of class A" << std::endl;
		return;
	}
	catch (...)
	{
	}
	try
	{
		B& ref_b = dynamic_cast<B&>(p);
		static_cast<void>(ref_b);
		std::cout << "REF is referencing data of class B" << std::endl;
		return;
	}
	catch (...)
	{
	}
	try
	{
		C& ref_c = dynamic_cast<C&>(p);
		static_cast<void>(ref_c);
		std::cout << "REF is referencing data of class C" << std::endl;
		return;
	}
	catch (...)
	{
		std::cerr << "Unknown REF type" << std::endl;
	}
}