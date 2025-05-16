/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 00:49:45 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/16 18:10:29 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <vector>

class PmergeMe
{
	private:
	bool	m_bDisplayed;
	public:
	PmergeMe();
	PmergeMe(PmergeMe& obj);
	~PmergeMe();
	void	sortList(const char* arg);
	void	sortVector(const int ac, const char** av);
	PmergeMe&	operator=(PmergeMe& obj);
	class	InvalidInt: public std::exception
	{
		const char*	what() const throw();
	};
};