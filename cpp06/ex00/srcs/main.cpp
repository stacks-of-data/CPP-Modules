/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:07:21 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/06 02:57:53 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Incorrect count of arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		ScalarConverter::convert(av[1]);
	}
	catch (const std::stringstream::failure& e)
	{
		std::cerr << "Writing to stream failure: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << "Allocation failure: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}