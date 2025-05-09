/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:53:28 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/09 15:08:10 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>
#include <list>
#include "../includes/utils.hpp"

int	getRandomListElement(std::list<int>& list)
{
	int iRand = rand() % list.size();
	std::list<int>::iterator it = list.begin();
	std::advance(it, iRand);
	return (*it);
}