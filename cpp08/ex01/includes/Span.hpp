/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:47:09 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/09 15:17:33 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdint.h>
#include <vector>
#include <exception>

class Span
{
	private:
	int			*m_arr;
	uint32_t	m_size;
	uint32_t	m_curr_size;
	bool		m_sorted;
	public:
	Span();
	Span(const uint32_t n);
	Span(const Span& obj);
	~Span();
	void	addNumber(int n);
	template <class T>
	void	addNumbers(const T& itB, const T& itE)
	{
		std::size_t len = std::distance(itB, itE);
		if (this->m_curr_size + len > this->m_size)
			throw Span::ExceededMaxSize();
		T it = itB;
		while (it != itE)
		{
			if (this->m_curr_size > 0)
				if (*it < this->m_arr[this->m_curr_size - 1])
					this->m_sorted = false;
			this->m_arr[this->m_curr_size] = *it;
			this->m_curr_size++;
			it++;
		}
	}
	long	shortestSpan();
	long	longestSpan();
	Span&	operator=(const Span& obj);
	class	ExceededMaxSize: public std::exception
	{
		const char*	what() const throw();
	};
	class	ImpossibleSpan: public std::exception
	{
		const char*	what() const throw();
	};
};

#endif