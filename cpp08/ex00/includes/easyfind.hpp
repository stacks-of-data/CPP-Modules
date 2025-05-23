/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:42:00 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/09 15:16:43 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <class T>
void easyfind(T& t, int iVal)
{
	typename T::iterator it = std::find(t.begin(), t.end(), iVal);
	if (it == t.end())
		throw std::exception();
	size_t i = std::distance(t.begin(), it);
	std::cout << "Found first occurrence at index " << i << std::endl;
}

#endif