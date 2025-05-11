/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:15:23 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/11 17:11:12 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>
#include <exception>

int main(int ac, char **av)
{
	BitcoinExchange	obj;
	if (ac != 2)
	{
		std::cerr << "\e[91mIncorrect number of arguments\n";
		std::cerr << "Arguments: ./btc <filename>\e[39m" << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		obj.InitMap();
		obj.ParseFile(av[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << "An error occured: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}