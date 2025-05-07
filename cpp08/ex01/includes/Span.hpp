/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:47:09 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/07 22:55:35 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <vector>
#include <exception>

class Span
{
	private:
	std::vector<int>	m_vec;
	uint32_t			m_size;
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
		if (this->m_vec.size() + len > this->m_size)
			throw Span::ExceededMaxSize();
		T it = itB;
		while (it != itE)
		{
			this->m_vec.push_back(*it);
			it++;
		}
	}
	long	shortestSpan() const;
	long	longestSpan() const;
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