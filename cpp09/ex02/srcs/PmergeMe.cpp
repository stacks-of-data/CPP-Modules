/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 01:04:46 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/13 02:57:40 by amsaleh          ###   ########.fr       */
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

typedef struct s_pmerge_elem
{
	int	val;
	size_t	i;
	bool	bMove;
}	t_pmerge_elem;


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

void	splitABVec(std::vector<int>& vecA,
	std::vector<t_pmerge_elem>& vecB, t_pmerge_elem& straggler, bool& bStraggler)
{
	t_pmerge_elem data;
	data.bMove = false;
	size_t i = 0;
	size_t track = 0;
	while (i < vecA.size() - 1)
	{
		if (vecA[i] < vecA[i + 1])
		{
			data.val = vecA[i];
			data.i = track;
			vecB.push_back(data);
			vecA.erase(vecA.begin() + i);
		}
		else
		{
			data.val = vecA[i + 1];
			data.i = track + 1;
			vecB.push_back(data);
			vecA.erase(vecA.begin() + i + 1);
		}
		i++;
		track += 2;
	}
	if (vecA.size() > vecB.size())
	{
		straggler.val = vecA[i];
		straggler.i = track;
		vecA.pop_back();
		bStraggler = true;
	}
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

void debugVecA(std::vector<int>& vecA)
{
	std::cout << "VecA: ";
	for (size_t i = 0; i < vecA.size(); i++)
	{
		std::cout << vecA[i] << " ";
	}
	std::cout << std::endl;
}

void debugVecB(std::vector<t_pmerge_elem >* vecB)
{
	std::cout << "VecB: ";
	if (vecB)
	{
		for (size_t i = 0; i < vecB->size(); i++)
		{
			std::cout << vecB->operator[](i).val << " ";
		}
	}
	std::cout << std::endl;
}

void	insertBtoA(std::vector<int>& vecA, t_pmerge_elem& elem,
	std::vector<std::vector<t_pmerge_elem>* >& vecPrevB, size_t i)
{
	debugVecA(vecA);
	debugVecB(vecPrevB[0]);
	vecA.insert(vecA.begin() + i, elem.val);
	if (vecPrevB.size() > 0)
	{
		std::vector<t_pmerge_elem>* vecPtr;
		t_pmerge_elem oldData;
		size_t curr_index = elem.i;
		if (!elem.bMove)
		{
			elem.bMove = true;
			for (ssize_t j = vecPrevB.size() - 1; j > -1; j--)
			{
				vecPtr = vecPrevB[j];
				oldData = vecPtr->operator[](curr_index);
				vecPtr->erase(vecPtr->begin() + curr_index);
				oldData.bMove = true;
				vecPtr->insert(vecPtr->begin() + i, oldData);
				curr_index = oldData.i;
			}
		}
	}
	debugVecA(vecA);
	debugVecB(vecPrevB[0]);
}

void	recursiveFJVec(std::vector<int>& vecA, std::vector<std::vector<t_pmerge_elem>* >& vecPrev)
{
	std::vector<t_pmerge_elem > vecB;
	t_pmerge_elem straggler;
	straggler.bMove = false;
	bool bStraggler = false;

	splitABVec(vecA, vecB, straggler, bStraggler);
	debugVecA(vecA);
	debugVecB(&vecB);
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