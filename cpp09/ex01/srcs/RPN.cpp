/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:16:07 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/16 23:26:47 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"
#include <sstream>
#include <iostream>
#include <limits>

RPN::RPN()
{
}

RPN::RPN(RPN& obj)
{
	(void)obj;
}

RPN::~RPN()
{
}

void	RPN::evaluateExp(const char *exp)
{
	std::stringstream	ss;
	std::stack<long>	stack;
	std::string			str;
	long				res;
	long 				val1;
	long				val2;

	ss.exceptions(std::ios::badbit);
	ss << exp;
	while (ss >> str)
	{
		if (str.length() != 1)
			throw RPN::InvalidExpression();
		if (isdigit(str[0]))
			stack.push(str[0] - 0x30);
		else
		{
			if (stack.size() < 2)
				throw RPN::InvalidExpression();
			val2 = stack.top();
			stack.pop();
			val1 = stack.top();
			stack.pop();
			switch (str[0])
			{
				case '+':
					res = val1 + val2;
					break;
				case '-':
					res = val1 - val2;
					break;
				case '*':
					res = val1 * val2;
					break;
				case '/':
					if (!val2)
						throw RPN::DivisionByZero();
					res = val1 / val2;
					break;
				default:
					throw RPN::InvalidExpression();
			}
			if (res > std::numeric_limits<int>::max() || res < std::numeric_limits<int>::min())
				throw RPN::IntOverflow();
			stack.push(res);
		}
	}
	if ((ss.fail() && !ss.eof()) || stack.size() != 1)
		throw RPN::InvalidExpression();
	std::cout << stack.top() << std::endl;
}

RPN&	RPN::operator=(RPN& obj)
{
	(void)obj;
	return (*this);
}

const char*	RPN::InvalidExpression::what() const throw()
{
	return ("RPN::InvalidExpression");
}

const char*	RPN::IntOverflow::what() const throw()
{
	return ("RPN::IntOverflow");
}

const char*	RPN::DivisionByZero::what() const throw()
{
	return ("RPN::DivisionByZero");
}