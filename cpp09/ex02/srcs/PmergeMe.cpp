/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 01:04:46 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/13 19:52:50 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <deque>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <cmath>
#include <stdint.h>


PmergeMe::PmergeMe(): m_bDisplayed(false)
{
}

PmergeMe::PmergeMe(PmergeMe& obj): m_bDisplayed(false)
{
	(void)obj;
}

PmergeMe::~PmergeMe()
{
}

void	displayVec(std::vector<int>& vecAOld, std::vector<int>& vecA)
{
	std::vector<int>::iterator it = vecAOld.begin();
	std::vector<int>::iterator itE = vecAOld.end();

	std::cout << "Before: ";
	while (it != itE)
	{
		std::cout << *it;
		if (it + 1 != itE)
			std::cout << ' ';
		else
			std::cout << '\n';
		it++;
	}
	std::cout << "After: ";
	it = vecA.begin();
	itE = vecA.end();
	while (it != itE)
	{
		std::cout << *it;
		if (it + 1 != itE)
			std::cout << ' ';
		else
			std::cout << '\n';
		it++;
	}
	std::cout.flush();
}

void	vecLabels(std::vector<int>& vecA, std::vector<uintptr_t>& vecLabels, size_t lvl)
{
	
}

size_t    binarySearchIndex(std::vector<int>& vec, int val)
{
    size_t low = 0;
    size_t high = vec.size();
    size_t mid;

    while (low < high)
    {
        mid = (low + high) / 2;
        if (vec[mid] == val)
            return (mid + 1);
        if (val > vec[mid])
            low = mid + 1;
        else
		{
			if (mid == 0)
				break;
            high = mid - 1;
		}
    }
    if (val > vec[low])
        return (low + 1);
    return (low);
}

void debugVec(std::vector<int>& vec, int mode)
{
	if (!mode)
		std::cout << "VecA: ";
	else
		std::cout << "VecB: ";
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

void	recursiveFJVec(std::vector<int>& vecA, std::vector<std::vector<int> >& vecLabels)
{
	std::vector<int> pend;
	int straggler;
	bool bStraggler = false;

	splitABVec(vecA, pend, straggler, bStraggler);
	debugVec(vecA, 0);
	if (vecA.size() > 1)
	{
		vecPrev.push_back(&vecB);
		recursiveFJVec(vecA, vecPrev);
	}
	std::cout << "Process" << std::endl;
	insertBtoA(vecA, vecB[0], vecPrev, 0);
	std::size_t i = 1;
	while (i < vecB.size())
	{
		std::size_t j = binarySearchIndex(vecA, vecB[i].val);
		insertBtoA(vecA, vecB[i], vecPrev, j);
		i++;
	}
	if (bStraggler)
	{
		std::size_t j = binarySearchIndex(vecA, straggler.val);
		insertBtoA(vecA, straggler, vecPrev, j);
	}
	vecPrev.pop_back();
}

void	PmergeMe::sortVector(const char* arg)
{
	try
	{
		std::vector<int>	vecAOld;
		std::vector<int>	vecA;
		std::vector<std::vector<t_pmerge_elem>* >	vecPrev;
		std::stringstream	ss(arg);
		int					tmp;

		ss.exceptions(std::ios::badbit);
		while (!ss.eof() && ss >> tmp)
		{
			if (tmp < 0)
				throw PmergeMe::InvalidInt();
			vecA.push_back(tmp);
		}
		if (ss.fail())
			throw PmergeMe::InvalidInt();
		if (this->m_bDisplayed == false)
			vecAOld = vecA;
		recursiveFJVec(vecA, vecPrev);
		if (this->m_bDisplayed == false)
		{
			displayVec(vecAOld, vecA);
			this->m_bDisplayed = true;
		}
	}
	catch (const std::exception& e)
	{
		throw;
	}
}
PmergeMe&	PmergeMe::operator=(PmergeMe& obj)
{
	(void)obj;
	this->m_bDisplayed = false;
	return (*this);
}

const char*	PmergeMe::InvalidInt::what() const throw()
{
	return ("PmergeMe::InvalidInt");
}