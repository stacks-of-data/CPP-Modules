/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 01:52:41 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/08 19:30:30 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <list>

#define COUNT 10

int main()
{
	std::srand(time(NULL));
	try
	{
		MutantStack<int>	ms;
		for (size_t i = 0; i < COUNT; i++)
			ms.push(rand() % 43);
		std::cout << "Mutant Stack Preview" << std::endl;
		for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); it++)
			std::cout << *it << std::endl;
		std::cout << "Mutant Stack Reverse Preview" << std::endl;
		for (MutantStack<int>::reverse_iterator it = ms.rbegin(); it != ms.rend(); it++)
			std::cout << *it << std::endl;
		std::sort(ms.begin(), ms.end());
		std::cout << "Sort Preview" << std::endl;
		for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); it++)
			std::cout << *it << std::endl;
		std::cout << "Copying MSTACK to vector" << std::endl;
		std::vector<int> vec(ms.begin(), ms.end());
		std::cout << "Vector Preview" << std::endl;
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}