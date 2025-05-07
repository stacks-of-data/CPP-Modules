/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:42:00 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/07 19:18:40 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>
#include <iostream>

template <class T>
void easyfind(T& t, int iVal)
{
	for (typename T::iterator it = t.begin(); it != t.end(); it++)
	{
		if (*it == iVal)
		{
			size_t i = std::distance(t.begin(), it);
			std::cout << "Found first occurrence at index " << i << std::endl;
			return;
		}
	}
	throw std::exception();
}
