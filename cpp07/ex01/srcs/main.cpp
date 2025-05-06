/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:08:33 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/06 22:10:13 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"
#include <string>
#include <iostream>

void func42(int& content)
{
	content += 42;
}

void funcS42(std::string& content)
{
	content += "_42";
}

void func_print_int(int& content)
{
	std::cout << "Int: " << content << "\n";
}

void func_print_str(const std::string& content)
{
	std::cout << "String: " << content << "\n";
}

int main()
{
	int arr_i[6] = {10, 9, 7, 6, 1, 2};
	std::string arr_s[4];
	try
	{
		arr_s[0] = "Steve";
		arr_s[1] = "John";
		arr_s[2] = "Eric";
		arr_s[3] = "Nick";
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	
	std::cout << "Before Iter fun42:\n";
	iter(arr_i, 6, func_print_int);
	iter(arr_i, 6, func42);
	std::cout << "After Iter fun42:\n";
	iter(arr_i, 6, func_print_int);

	std::cout << "Before Iter funS42:\n";
	iter(arr_s, 4, func_print_str);

	try
	{
		iter(arr_s, 4, funcS42);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	
	std::cout << "After Iter funS42:\n";
	iter(arr_s, 4, func_print_str);
	
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}