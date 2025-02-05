/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:56:26 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/05 21:44:24 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "str memory address: " << &str << '\n';
	std::cout << "stringPTR memory address: " << stringPTR << '\n';
	std::cout << "stringREF memory address: " << &stringREF << '\n';

	std::cout << "str: " << str << '\n';
	std::cout << "stringPTR: " << *stringPTR << '\n';
	std::cout << "stringREF: " << stringREF << '\n';
}