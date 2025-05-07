/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:18:25 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/08 01:10:56 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <limits>
#include <cstdlib>
#include <algorithm>

Span::Span(): m_arr(0), m_size(0), m_curr_size(0), m_sorted(true)
{
}

Span::Span(const uint32_t n): m_size(n), m_curr_size(0), m_sorted(true)
{
	this->m_arr = new int[this->m_size];
}

Span::Span(const Span& obj)
{
	this->m_size = obj.m_size;
	this->m_curr_size = obj.m_curr_size;
	this->m_arr = new int[this->m_size];
	for (uint32_t i = 0; i < this->m_curr_size; i++)
		this->m_arr[i] = obj.m_arr[i];
}

Span::~Span()
{
	delete[] this->m_arr;
}

void	Span::addNumber(int n)
{
	if (this->m_curr_size == this->m_size)
		throw Span::ExceededMaxSize();
	if (this->m_curr_size > 0)
		if (n < this->m_arr[this->m_curr_size - 1])
			this->m_sorted = false;
	this->m_arr[this->m_curr_size] = n;
	this->m_curr_size++;
}

long	Span::shortestSpan()
{
	if (this->m_curr_size < 2)
		throw Span::ImpossibleSpan();
	if (this->m_sorted == false)
	{
		std::sort(&this->m_arr[0], &this->m_arr[this->m_curr_size]);
		this->m_sorted = true;
	}
	long shortest_span = std::numeric_limits<long>::max();
	for (long i = 0; i < this->m_curr_size - 1; i++)
	{
		long lTmp = labs(this->m_arr[i] - this->m_arr[i + 1]);
		if (lTmp < shortest_span)
			shortest_span = lTmp;
	}
	return (shortest_span);
}

long	Span::longestSpan()
{
	if (this->m_curr_size < 2)
		throw Span::ImpossibleSpan();
	if (this->m_sorted == false)
	{
		std::sort(&this->m_arr[0], &this->m_arr[this->m_curr_size]);
		this->m_sorted = true;
	}
	return (labs(this->m_arr[this->m_curr_size - 1] - this->m_arr[0]));
}

Span&	Span::operator=(const Span& obj)
{
	delete[] this->m_arr;
	this->m_size = obj.m_size;
	this->m_curr_size = obj.m_curr_size;
	this->m_arr = new int[this->m_size];
	this->m_sorted = obj.m_sorted;
	for (uint32_t i = 0; i < this->m_curr_size; i++)
		this->m_arr[i] = obj.m_arr[i];
	return (*this);
}

const char*	Span::ExceededMaxSize::what() const throw()
{
	return ("Span::ExceededMaxSize");
}

const char*	Span::ImpossibleSpan::what() const throw()
{
	return ("Span::ImpossibleSpan");
}