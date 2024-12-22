/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:56:26 by amsaleh           #+#    #+#             */
/*   Updated: 2024/12/22 00:56:27 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "str memory address: " << (void *)stringREF.c_str() << '\n';
	std::cout << "stringPTR memory address: " << stringPTR << '\n';
	std::cout << "stringREF memory address: " << (void *)stringREF.c_str() << '\n';

	std::cout << "str: " << str << '\n';
	std::cout << "stringPTR: " << *stringPTR << '\n';
	std::cout << "stringREF: " << stringREF << '\n';
}