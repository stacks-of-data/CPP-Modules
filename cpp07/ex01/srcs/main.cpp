/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:08:33 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/06 17:34:58 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"
#include <string>
#include <iostream>

void func42(void* content)
{
	*static_cast<int*>(content) = *static_cast<int*>(content) + 42;
}

void funcS42(void* content)
{
	*static_cast<std::string*>(content) += "_42";
}

void func_print_int(void* content)
{
	std::cout << "Int: " << *static_cast<int*>(content) << "\n";
}

void func_print_str(void* content)
{
	std::cout << "String: " << *static_cast<std::string*>(content) << "\n";
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