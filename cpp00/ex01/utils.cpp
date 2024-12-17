/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:36:35 by amsaleh           #+#    #+#             */
/*   Updated: 2024/12/18 01:51:20 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool	CheckInputErrors(bool bDisplay)
{
	if (std::cin.bad())
	{
		if (bDisplay)
			std::cerr << "I/O Error, Exiting!\n";
		return (0);
	}
	if (std::cin.eof())
	{
		if (bDisplay)
			std::cerr << "\nEOF, Exiting!\n";
		return (0);
	}
	if (std::cin.fail())
	{
		if (bDisplay)
			std::cerr << "Input Error, Exiting!\n";
		return (0);
	}
	return (1);
}

bool	CheckInputErrorsStr(std::string input)
{
	if (!CheckInputErrors(false))
		return (0);
	if (input.empty())
	{
		std::cerr << "Input is empty, aborting contact add!\n";
		return (0);
	}
	return (1);
}