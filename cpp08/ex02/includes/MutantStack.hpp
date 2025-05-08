/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 23:47:38 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/08 03:11:52 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>

template <class T>
class MutantStack: public std::stack<T>
{
	public:
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;
	typedef typename std::deque<T>::reverse_iterator reverse_iterator;
	typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;
	MutantStack(): std::stack<T>()
	{
	}
	MutantStack(MutantStack& obj): std::stack<T>(obj)
	{
	}
	~MutantStack()
	{
	}
	MutantStack&	operator=(MutantStack& obj)
	{
		
	}
	iterator	begin()
	{
		return (this->c.begin());
	}
	const_iterator	cbegin() const
	{
		return (this->c.cbegin());
	}
	iterator	end()
	{
		return (this->c.end());
	}
	const_iterator	cend() const
	{
		return (this->c.cend());
	}
	reverse_iterator	rbegin()
	{
		return (this->c.rbegin());
	}
	const_reverse_iterator	crbegin() const
	{
		return (this->c.crbegin());
	}
	reverse_iterator	rend()
	{
		return (this->c.rend());
	}
	const_reverse_iterator	crend() const
	{
		return (this->c.crend());
	}
};