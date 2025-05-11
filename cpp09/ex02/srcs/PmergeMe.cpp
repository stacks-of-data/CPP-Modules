/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 01:04:46 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/12 01:45:03 by amsaleh          ###   ########.fr       */
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

void	PmergeMe::sortList(const char* arg)
{
	(void)arg;
}

void	recursiveVecSplit(std::vector<int>& vecA, std::vector<int>& vecB, std::size_t pairCount, std::size_t lvl)
{
	if (pairCount < 2)
		return;
	std::size_t indexInc = lvl * 2;
	std::size_t indexLimit = vecA.size() - lvl;
	for (std::size_t i = 0; i < indexLimit; i += indexInc)
	{
		size_t iAddLvl = i + indexInc / 2;
		size_t iAddLvl2 = iAddLvl + indexInc / 2;
		int maxS1 = std::numeric_limits<int>::min();
		int maxS2 = std::numeric_limits<int>::min();
		for (std::size_t j = i; j < iAddLvl; j++)
			if (vecA[j] > maxS1)
				maxS1 = vecA[j];
		for (std::size_t j = iAddLvl; j < iAddLvl2; j++)
			if (vecA[j] > maxS2)
				maxS2 = vecA[j];
		if (maxS1 > maxS2)
		{
			for (std::size_t j = i; j < iAddLvl; j++)
				std::swap(vecA[j], vecA[j + indexInc / 2]);
			for (std::size_t j = i; j < iAddLvl; j++)
				std::swap(vecB[j], vecB[j + indexInc / 2]);
		}
	}
	recursiveVecSplit(vecA, vecB, pairCount / 2, lvl + 1);
}

void	splitAB(std::vector<int>& vecA, std::vector<int>& vecB)
{
	std::size_t i = 0;
	while (i < vecA.size() - 1)
	{
		if (vecA[i + 1] < vecA[i])
		{
			vecB.push_back(vecA[i + 1]);
			vecA.erase(vecA.begin() + i + 1);
		}
		else
		{
			vecB.push_back(vecA[i]);
			vecA.erase(vecA.begin() + i);
		}
		i++;
	}
	if (vecA.size() > vecB.size())
	{
		vecB.push_back(vecA.back());
		vecA.pop_back();
	}
}

void	PmergeMe::sortVector(const char* arg)
{
	try
	{
		std::vector<int>	vecAOld;
		std::vector<int>	vecA;
		std::vector<int>	vecB;
		std::vector<int>	vecRes;
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
		splitAB(vecA, vecB);
		recursiveVecSplit(vecA, vecB, vecA.size(), 1);
		insertionSortVec(vecRes, vecA, vecB);
		if (this->m_bDisplayed == false)
		{
			// displayVec(vecAOld, vecRes);
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