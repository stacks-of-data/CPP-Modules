/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:36:35 by amsaleh           #+#    #+#             */
/*   Updated: 2024/12/18 20:05:51 by amsaleh          ###   ########.fr       */
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

bool	CheckPhoneNumber(std::string str)
{
	size_t	i = 0;
	while (str[i])
	{
		if (!isdigit(str[i]) && str[i] != ' ')
		{
			std::cerr << "BRUH, I TOLD YOU TO INPUT A PHONE NUMBER YOU IDIOT!!!\nYOU DON'T EVEN DESERVE A RETRY.\n";
			return (0);
		}
		i++;
	}
	return (1);
}

bool	CheckSearchIndexInput(std::string str)
{
	if (str.length() > 1)
	{
		std::cerr << "BRUH, ITS A SEARCH INDEX FROM 1-8 WHY DID YOU INPUT MORE THAN 1 CHARACTER!!!\nYOU DON'T EVEN DESERVE A RETRY.\n";
		return (0);
	}
	if (!isdigit(str[0]))
	{
		std::cerr << "YOU DON'T KNOW WHAT A NUMBER IS!!!\nYOU DON'T EVEN DESERVE A RETRY.\n";
		return (0);
	}
	if (str[0] == '0' || str[0] == '9')
	{
		std::cerr << "IS IT VERY DIFFICULT TO ENTER A NUMBER FROM 1-8!!!\nYOU DON'T EVEN DESERVE A RETRY.\n";
		return (0);
	}
	return (1);
}

bool	CheckName(std::string str)
{
	size_t	i = 0;
	bool	bContainsAlpha = false;
	while (str[i])
	{
		if (isdigit(str[i]))
		{
			std::cerr << "YOU DON'T KNOW WHAT A NAME IS, WHO ENTERS A NUMBER IN A NAME!!!\nYOU DON'T EVEN DESERVE A RETRY.\n";
			return (0);
		}
		else if (!isalpha(str[i]) && !isspace(str[i]))
		{
			std::cerr << "ITS CRAZY THAT YOU ENTERED A SPECIAL CHARACTER IN A NAME!!!\nYOU DON'T EVEN DESERVE A RETRY.\n";
			return (0);
		}
		else if (isalpha(str[i]))
			bContainsAlpha = true;
		i++;
	}
	if (!bContainsAlpha)
	{
		std::cerr << "A NAME WITH ONLY WHITESPACES ARE YOU SERIOUS!!!\nYOU DON'T EVEN DESERVE A RETRY.\n";
		return (0);
	}
	return (1);
}

bool	CheckNickname(std::string str)
{
	size_t	i = 0;
	while (str[i])
	{
		if (isascii(str[i]) && !isspace(str[i]))
			return (1);
		i++;
	}
	std::cerr << "REALLY! NICKNAME WITH ONLY WHITESPACES!!!\nYOU DON'T EVEN DESERVE A RETRY.\n";
	return (0);
}

void	TruncateStr(std::string *str)
{
	if (str->length() > 10)
	{
		str->replace(9, 1, ".");
		str->erase(10);
	}
}