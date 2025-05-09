/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:51:05 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/09 15:13:54 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <cstdlib>

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