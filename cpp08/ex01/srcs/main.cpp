/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:54:31 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/09 15:20:27 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include "../includes/utils.hpp"

int main()
{
	std::srand(time(NULL));

	std::cout << "Test Case A" << std::endl;
	try
	{
		Span spA = Span(COUNT_A);
		int randLimitP1 = RAND_LIMIT + 1;
		try
		{
			for (size_t i = 0; i < COUNT_A; i++)
				spA.addNumber(rand() % randLimitP1);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "Shortest span: " << spA.shortestSpan() << std::endl;
			std::cout << "Longest span: " << spA.longestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	
	std::cout << "Test Case B" << std::endl;
	try
	{
		Span spB = Span(COUNT_B);
		std::vector<int> vec;
		for (size_t i = 0; i < COUNT_B; i++)
			vec.push_back(rand() % (RAND_LIMIT + 1));
		try
		{
			spB.addNumbers(vec.begin(), vec.end());
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "Shortest span: " << spB.shortestSpan() << std::endl;
			std::cout << "Longest span: " << spB.longestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (0);
}