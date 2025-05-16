/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 00:49:45 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/16 22:20:11 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <iostream>
#include <sys/time.h>
#include <string>
#include <sstream>
#include <algorithm>
#include "../includes/utils.hpp"

class PmergeMe
{
	private:
	bool	m_bDisplayed;
	public:
	PmergeMe();
	PmergeMe(PmergeMe& obj);
	~PmergeMe();
	void			sortVector(const int ac, const char** av);
	void			sortDeque(const int ac, const char** av);
	void			sort(const int ac, const char** av);
	PmergeMe&		operator=(PmergeMe& obj);
	class	InvalidSequence: public std::exception
	{
		const char*	what() const throw();
	};
};
