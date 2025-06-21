/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 01:04:46 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/16 22:20:08 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe(): m_bDisplayed(false)
{
}

PmergeMe::PmergeMe(PmergeMe& obj): m_bDisplayed(obj.m_bDisplayed)
{
}

PmergeMe::~PmergeMe()
{
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

std::vector<int>	FJSortVec(std::vector<int>& vec)
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

std::deque<int>	FJSortDeque(std::deque<int>& deq)
{
	std::deque<int>	res;
	std::deque<TBlock>	main, deqA, deqB;
	TBlock	tmpBlock;

	for (size_t i = 0; i < deq.size(); i++)
	{
		setBlockData(tmpBlock, deq[i]);
		main.push_back(tmpBlock);
	}
	for (size_t i = 0; i < main.size() - 1; i += 2)
	{
		if (main[i].val < main[i + 1].val)
		{
			setBlockData(tmpBlock, main[i + 1].val, &main[i + 1], &main[i]);
			deqA.push_back(tmpBlock);
			setBlockData(tmpBlock, main[i].val);
			deqB.push_back(tmpBlock);
		}
		else
		{
			setBlockData(tmpBlock, main[i].val, &main[i], &main[i + 1]);
			deqA.push_back(tmpBlock);
			setBlockData(tmpBlock, main[i + 1].val);
			deqB.push_back(tmpBlock);
		}
	}
	if (deq.size() % 2)
	{
		setBlockData(tmpBlock, main[main.size() - 1].val);
		deqB.push_back(tmpBlock);
	}
	recursiveFJ(deqA, deqB);
	for (size_t i = 0; i < deqA.size(); i++)
		res.push_back(deqA[i].val);
	return (res);
}

long long	getTimestampMicro()
{
	struct timeval data;
	gettimeofday(&data, NULL);
	return (static_cast<long long>(data.tv_sec) * 1000000 + data.tv_usec);
}

void	PmergeMe::sortVector(const int ac, const char** av)
{
	std::vector<int>	vec, res;
	int					tmp;
	std::stringstream	ss;
	ss.exceptions(std::ios::badbit);
	long long	start, end;
	double		timeRes;
	
	start = getTimestampMicro();
	for (int i = 1; i < ac; i++)
	{
		ss << av[i];
		while (!ss.eof())
		{
			ss >> tmp;
			if (ss.fail() || tmp < 0)
				throw PmergeMe::InvalidSequence();
			vec.push_back(tmp);
		}
		ss.clear();
	}
	if (!vec.size())
		throw PmergeMe::InvalidSequence();
	res = FJSortVec(vec);
	end = getTimestampMicro();
	if (this->m_bDisplayed == false)
	{
		displaySortedSequence(vec, res);
		this->m_bDisplayed = true;
	}
	timeRes = (double)(end - start) / 1000;
	std::cout << "Time to process a range of " << res.size()
		<< " elements with std::vector using Ford-Johnson sort: " << timeRes << std::endl;
	start = getTimestampMicro();
	std::sort(vec.begin(), vec.end());
	end = getTimestampMicro();
	timeRes = (double)(end - start) / 1000;
	std::cout << "Time to process a range of " << res.size()
		<< " elements with std::vector using std::sort: " << timeRes << std::endl;
}

void	PmergeMe::sortDeque(const int ac, const char** av)
{
	std::deque<int>	deq, res;
	int					tmp;
	std::stringstream	ss;
	ss.exceptions(std::ios::badbit);
	long long	start, end;
	double		timeRes;
	
	start = getTimestampMicro();
	for (int i = 1; i < ac; i++)
	{
		ss << av[i];
		while (!ss.eof())
		{
			ss >> tmp;
			if (ss.fail() || tmp < 0)
				throw PmergeMe::InvalidSequence();
			deq.push_back(tmp);
		}
		ss.clear();
	}
	if (!deq.size())
		throw PmergeMe::InvalidSequence();
	res = FJSortDeque(deq);
	end = getTimestampMicro();
	if (this->m_bDisplayed == false)
	{
		displaySortedSequence(deq, res);
		this->m_bDisplayed = true;
	}
	timeRes = (double)(end - start) / 1000;
	std::cout << "Time to process a range of " << res.size()
		<< " elements with std::deque using Ford-Johnson sort: " << timeRes << std::endl;
	start = getTimestampMicro();
	std::sort(deq.begin(), deq.end());
	end = getTimestampMicro();
	timeRes = (double)(end - start) / 1000;
	std::cout << "Time to process a range of " << res.size()
		<< " elements with std::deque using std::sort: " << timeRes << std::endl;
}

void	PmergeMe::sort(const int ac, const char** av)
{
	sortVector(ac, av);
	sortDeque(ac, av);
}

PmergeMe&	PmergeMe::operator=(PmergeMe& obj)
{
	(void)obj;
	this->m_bDisplayed = obj.m_bDisplayed;
	return (*this);
}

const char*	PmergeMe::InvalidSequence::what() const throw()
{
	return ("PmergeMe::InvalidSequence");
}