/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 01:04:46 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/16 17:10:23 by amsaleh          ###   ########.fr       */
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

typedef struct	SBlock
{
	int				val;
	struct SBlock*	prevA;
	struct SBlock*	prevB;
}	TBlock;

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

size_t    binarySearchBlockIndex(std::vector<TBlock>& vecA, int val)
{
    size_t low = 0;
    size_t high = vecA.size();
    size_t mid;

    while (low < high)
    {
        mid = (low + high) / 2;
        if (val == vecA[mid].val)
            return (mid + 1);
        if (val > vecA[mid].val)
            low = mid + 1;
        else
		{
			if (mid == 0)
				break;
            high = mid - 1;
		}
    }
	if (low < vecA.size() && val > vecA[low].val)
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

void	setBlockData(TBlock& block,
	int val,
	TBlock* prevA = NULL,
	TBlock* prevB = NULL)
{
	block.val = val;
	block.prevA = prevA;
	block.prevB = prevB;
}

void	packBlocks(std::vector<TBlock>& vecAOld,
	std::vector<TBlock>& vecBOld,
	std::vector<TBlock>& vecA,
	std::vector<TBlock>& vecB)
{
	TBlock	tmpBlock;

	for (size_t i = 0; i < vecAOld.size() - 1; i += 2)
	{
		if (vecAOld[i].val < vecAOld[i + 1].val)
		{
			setBlockData(tmpBlock, vecAOld[i + 1].val, &vecAOld[i + 1], &vecBOld[i + 1]);
			vecA.push_back(tmpBlock);;
			setBlockData(tmpBlock, vecAOld[i].val, &vecAOld[i], &vecBOld[i]);
			vecB.push_back(tmpBlock);
		}
		else
		{
			setBlockData(tmpBlock, vecAOld[i].val, &vecAOld[i], &vecBOld[i]);
			vecA.push_back(tmpBlock);
			setBlockData(tmpBlock, vecAOld[i + 1].val, &vecAOld[i + 1], &vecBOld[i + 1]);
			vecB.push_back(tmpBlock);
		}
	}
	if (vecAOld.size() % 2)
	{
		setBlockData(tmpBlock, vecAOld[vecAOld.size() - 1].val, &vecAOld[vecAOld.size() - 1], &vecBOld[vecAOld.size() - 1]);
		vecB.push_back(tmpBlock);
	}
}

void	unpackBlocks(std::vector<TBlock>& packedVecA,
	std::vector<TBlock>& vecA,
	std::vector<TBlock>& vecB)
{
	std::vector<TBlock>	unpackedVecA, unpackedVecB;

	for (size_t i = 0; i < packedVecA.size(); i++)
	{
		unpackedVecA.push_back(*(packedVecA[i].prevA));
		unpackedVecB.push_back(*(packedVecA[i].prevB));
	}
	vecA = unpackedVecA;
	if (vecA.size() != vecB.size())
	{
		TBlock tmp = vecB.back();
		vecB = unpackedVecB;
		vecB.push_back(tmp);
	}
	else
		vecB = unpackedVecB;
}

void	recursiveFJ(std::vector<TBlock>& vecA,
	std::vector<TBlock>& vecB)
{
	std::vector<TBlock>	res, newVecA, newVecB;
	if (vecA.size() > 2)
	{
		packBlocks(vecA, vecB, newVecA, newVecB);
		recursiveFJ(newVecA, newVecB);
		unpackBlocks(newVecA, vecA, vecB);
	}
	vecA.insert(vecA.begin(), vecB[0]);
	for (size_t i = 1; i < vecB.size(); i++)
	{
		size_t j = binarySearchBlockIndex(vecA, vecB[i].val);
		vecA.insert(vecA.begin() + j, vecB[i]);
	}
	vecB.clear();
}

std::vector<int>	FJSort(std::vector<int>& vec)
{
	std::vector<int>	res;
	std::vector<TBlock>	main, vecA, vecB;
	TBlock	tmpBlock;

	for (size_t i = 0; i < vec.size(); i++)
	{
		setBlockData(tmpBlock, vec[i]);
		main.push_back(tmpBlock);
	}
	for (size_t i = 0; i < main.size() - 1; i += 2)
	{
		if (main[i].val < main[i + 1].val)
		{
			setBlockData(tmpBlock, main[i + 1].val, &main[i + 1], &main[i]);
			vecA.push_back(tmpBlock);
			setBlockData(tmpBlock, main[i].val);
			vecB.push_back(tmpBlock);
		}
		else
		{
			setBlockData(tmpBlock, main[i].val, &main[i], &main[i + 1]);
			vecA.push_back(tmpBlock);
			setBlockData(tmpBlock, main[i + 1].val);
			vecB.push_back(tmpBlock);
		}
	}
	if (vec.size() % 2)
	{
		setBlockData(tmpBlock, main[main.size() - 1].val);
		vecB.push_back(tmpBlock);
	}
	recursiveFJ(vecA, vecB);
	for (size_t i = 0; i < vecA.size(); i++)
		res.push_back(vecA[i].val);
	return (res);
}

void	PmergeMe::sortVector(const char* arg)
{
	try
	{
		std::vector<int>	vec, res;
		std::stringstream	ss(arg);
		int					tmp;

		ss.exceptions(std::ios::badbit);
		while (!ss.eof() && ss >> tmp)
		{
			if (tmp < 0)
				throw PmergeMe::InvalidInt();
			vec.push_back(tmp);
		}
		if (ss.fail())
			throw PmergeMe::InvalidInt();
		res = FJSort(vec);
		if (this->m_bDisplayed == false)
		{
			displayVec(vec, res);
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