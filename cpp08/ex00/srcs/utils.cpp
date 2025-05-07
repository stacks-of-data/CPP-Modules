/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:53:28 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/07 19:53:50 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.hpp"

int	getRandomListElement(std::list<int>& list)
{
	int iRand = rand() % list.size();
	std::list<int>::iterator it = list.begin();
	for (int i = 0; i < iRand; i++)
		it++;
	return (*it);
}