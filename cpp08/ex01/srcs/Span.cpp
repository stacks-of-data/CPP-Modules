/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:18:25 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/07 22:39:35 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <limits>
#include <cstdlib>

Span::Span(): m_size(0)
{
}

Span::Span(const uint32_t n): m_size(n)
{
	this->m_vec.reserve(n);
}

Span::Span(const Span& obj)
{
	this->m_size = obj.m_size;
	this->m_vec = obj.m_vec;
}

Span::~Span()
{
}

void	Span::addNumber(int n)
{
	if (this->m_vec.size() == this->m_size)
		throw Span::ExceededMaxSize();
	this->m_vec.push_back(n);
}

long	Span::shortestSpan() const
{
	if (this->m_vec.size() < 2)
		throw Span::ImpossibleSpan();
	long shortest_span = std::numeric_limits<long>::max();
	for (long i = this->m_vec.size() - 1; i > 0; i--)
	{
		long lTmp = this->m_vec[i] - this->m_vec[i - 1];
		long lAbs = labs(lTmp);
		if (lAbs < shortest_span)
			shortest_span = lAbs;
	}
	return (shortest_span);
}

long	Span::longestSpan() const
{
	if (this->m_vec.size() < 2)
		throw Span::ImpossibleSpan();
	long longest_span = std::numeric_limits<long>::min();
	for (long i = this->m_vec.size() - 1; i > 0; i--)
	{
		long lTmp = this->m_vec[i] - this->m_vec[i - 1];
		long lAbs = labs(lTmp);
		if (lAbs > longest_span)
			longest_span = lAbs;
	}
	return (longest_span);
}

Span&	Span::operator=(const Span& obj)
{
	this->m_size = obj.m_size;
	this->m_vec = obj.m_vec;
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