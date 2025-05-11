/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 01:16:29 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/10 01:18:27 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

int main(int ac, char** av)
{
	PmergeMe	obj;

	if (ac != 2)
	{
		std::cerr << "Incorrect number of arguments\n";
		std::cerr << "Arguments ./PmergeMe <int sequence>" << std::endl;
		return (EXIT_FAILURE);
	}
	obj.sortVector(av[1]);
	return (EXIT_SUCCESS);
}