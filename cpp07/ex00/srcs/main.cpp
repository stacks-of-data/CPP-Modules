/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 03:09:22 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/06 22:14:38 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tools.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
	int a = 42;
	int b = 24;
	std::cout << "Before swap(a, b):\n" << "a: " << a << "\nb: " << b << '\n';
	swap(a, b);
	std::cout << "After swap(a, b):\n" << "a: " << a << "\nb: " << b << '\n';
	std::cout << "min(a, b) = " << min(a, b) << '\n';
	std::cout << "max(a, b) = " << max(a, b) << '\n';
	std::string c;
	std::string d;
	try
	{
		c = "ABCD";
		d = "EFGH";
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << "Allocation Failure: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	std::cout << "Before swap(c, d):\n" << "c: " << c << "\nd: " << d << '\n';
	try
	{
		swap(c, d);
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << "Allocation Failure: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	
	std::cout << "After swap(c, d):\n" << "c: " << c << "\nd: " << d << '\n';
	std::cout << "min(c, d) = " << min(c, d) << '\n';
	std::cout << "max(c, d) = " << max(c, d) << std::endl;
	return (EXIT_SUCCESS);
}