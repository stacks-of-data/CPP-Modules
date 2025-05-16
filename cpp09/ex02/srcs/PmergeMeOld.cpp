/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 01:04:46 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/16 02:07:40 by amsaleh          ###   ########.fr       */
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

void	vecLabelingFunc(std::vector<int>& vecA,
	std::vector<std::vector<size_t> >& recVecsAIdx,
	std::vector<std::vector<size_t> >& recVecsBIdx,
	size_t lvl)
{
	std::vector<size_t> vecAIdx, vecBIdx;
	if (lvl == 0)
	{
		for (size_t i = 0; i < vecA.size() - 1; i += 2)
		{
			if (vecA[i] < vecA[i + 1])
			{
				vecAIdx.push_back(i + 1);
				vecBIdx.push_back(i);
			}
			else
			{
				vecAIdx.push_back(i);
				vecBIdx.push_back(i + 1);
			}
		}
		if (vecA.size() % 2)
			vecBIdx.push_back(vecA.size() - 1);
	}
	else
	{
		std::vector<size_t>& lastVecAIdx = recVecsAIdx.back();
		for (size_t i = 0; i < lastVecAIdx.size() - 1; i += 2)
		{
			if (vecA[lastVecAIdx[i]] < vecA[lastVecAIdx[i + 1]])
			{
				vecAIdx.push_back(lastVecAIdx[i + 1]);
				vecBIdx.push_back(lastVecAIdx[i]);
			}
			else
			{
				vecAIdx.push_back(lastVecAIdx[i]);
				vecBIdx.push_back(lastVecAIdx[i + 1]);
			}
		}
		if (lastVecAIdx.size() % 2)
			vecBIdx.push_back(lastVecAIdx[lastVecAIdx.size() - 1]);
	}
	recVecsAIdx.push_back(vecAIdx);
	recVecsBIdx.push_back(vecBIdx);
}

size_t    binarySearchBlockIndex(std::vector<int>& vec,
	size_t idxB,
	std::vector<size_t>& vecIdxA)
{
    size_t low = 0;
    size_t high = vecIdxA.size();
    size_t mid;

    while (low < high)
    {
        mid = (low + high) / 2;
        if (vec[idxB] == vec[vecIdxA[mid]])
            return (mid + 1);
        if (vec[idxB] > vec[vecIdxA[mid]])
            low = mid + 1;
        else
		{
			if (mid == 0)
				break;
            high = mid - 1;
		}
    }
	if (low < vecIdxA.size() && vec[idxB] > vec[vecIdxA[low]])
		return (low + 1);
    return (low);
}

void debugVec(std::vector<int>& vec)
{
	std::cout << "Vec: ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

void	moveVecAData(std::vector<int>& vecA,
	size_t iBlockB,
	size_t iBlockA,
	size_t blockSize)
{
	std::vector<int>::iterator itA = vecA.begin() + (iBlockA * blockSize);
	std::vector<int>::iterator itAE = vecA.begin() + ((iBlockA + 1) * blockSize);
	std::vector<int>::iterator itB = vecA.begin() + (iBlockB * blockSize);
	std::swap_ranges(itA, itAE, itB);
}

void	movePairB(std::vector<int>& vecA,
	std::vector<std::vector<size_t> >& recVecsAIdx,
	std::vector<std::vector<size_t> >& recVecsBIdx,
	size_t iBlockB,
	size_t iBlockA,
	size_t blockSize)
{
	(void)recVecsAIdx;
	(void)recVecsBIdx;
	if (iBlockB == iBlockA)
		return;
	//size_t blocksDistance = iBlockB - iBlockA;
	moveVecAData(vecA, iBlockB, iBlockA, blockSize);
	// size_t currBlockSize = 1;
	// size_t i = recVecsAIdx.size() - 1;
	
}

void	recursiveFJVec(std::vector<int>& vecA,
	std::vector<std::vector<size_t> >& recVecsAIdx,
	std::vector<std::vector<size_t> >& recVecsBIdx,
	size_t lvl = 0)
{
	vecLabelingFunc(vecA, recVecsAIdx, recVecsBIdx, lvl);
	std::vector<size_t> vecAIdx = recVecsAIdx.back();
	std::vector<size_t> vecBIdx = recVecsBIdx.back();
	if (vecAIdx.size() > 2)
		recursiveFJVec(vecA, recVecsAIdx, recVecsBIdx, lvl + 1);
	size_t blockSize = pow(2, lvl);
	(void)blockSize;
	// std::cout << "vecAIdx:" << std::endl;
	// for (size_t i = 0; i < vecAIdx.size(); i++)
	// 	std::cout << vecAIdx[i] << " ";
	// std::cout << std::endl;
	// std::cout << "vecBIdx:" << std::endl;
	// for (size_t i = 0; i < vecBIdx.size(); i++)
	// 	std::cout << vecBIdx[i] << " ";
	// std::cout << std::endl;

	// size_t tmp = binarySearchBlockIndex(vecA, recVecsBIdx.back()[0], recVecsAIdx.back());
	// std::cout << "binarySearchBlockIndex: " << tmp << std::endl;

	movePairB(vecA, recVecsAIdx, recVecsBIdx, recVecsBIdx.back()[0] / blockSize, 0, blockSize);
	debugVec(vecA);
	recVecsAIdx.pop_back();
	recVecsBIdx.pop_back();
}

void	PmergeMe::sortVector(const char* arg)
{
	try
	{
		std::vector<int>	vecAOld;
		std::vector<int>	vecA;
		std::vector<std::vector<size_t> > recVecsAIdx, recVecsBIdx;
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
		recursiveFJVec(vecA, recVecsAIdx, recVecsBIdx);
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