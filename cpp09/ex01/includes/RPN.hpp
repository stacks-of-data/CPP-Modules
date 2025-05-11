/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:16:14 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/11 20:27:42 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <exception>

class RPN
{
	public:
	RPN();
	RPN(RPN& obj);
	~RPN();
	void	evaluateExp(const char *exp);
	RPN&	operator=(RPN& obj);
	class	InvalidExpression: public std::exception
	{
		const char*	what() const throw();
	};
	class	IntOverflow: public std::exception
	{
		const char*	what() const throw();
	};
	class	DivisionByZero: public std::exception
	{
		const char*	what() const throw();
	};
};