/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:15:59 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/11 20:28:48 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"
#include <iostream>
#include <cstdlib>

int main(int ac, char** av)
{
	RPN	obj;
	if (ac != 2)
	{
		std::cerr << "\e[91mIncorrect number of arguments\n";
		std::cerr << "Arguments: ./RPN <expression>\e[39m" << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		obj.evaluateExp(av[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << "\e[91mAn error has occurred: " << e.what() << "\e[39m" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}