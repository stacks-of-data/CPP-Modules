/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:51:05 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/09 15:20:39 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <list>
#include <cstdlib>
#include <vector>

#define COUNT 5
#if COUNT <= 0
	#undef COUNT
	#define COUNT 1
#endif
#define RAND_LIMIT 42
#if RAND_LIMIT <= 0
	#undef RAND_LIMIT
	#define RAND_LIMIT 1
#endif

template <class T>
void	attemptEasyFind(T& container, int iVal)
{
	try
	{
		easyfind(container, iVal);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Container doesn't contain the provided value" << std::endl;
	}
}

int	getRandomListElement(std::list<int>& list);

#endif