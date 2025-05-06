/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 03:09:22 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/06 03:32:32 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tools.hpp"
#include <iostream>

int main()
{
	int a = 42;
	int b = 24;
	std::cout << "Before swap(a, b):\n" << "a: " << a << "\nb: " << b << '\n';
	swap(a, b);
	std::cout << "After swap(a, b):\n" << "a: " << a << "\nb: " << b << '\n';
	std::cout << "min(a, b) = " << min(a, b) << '\n';
	std::cout << "max(a, b) = " << max(a, b) << '\n';
	std::string c = "ABCD";
	std::string d = "EFGH";
	std::cout << "Before swap(c, d):\n" << "c: " << c << "\nd: " << d << '\n';
	swap(c, d);
	std::cout << "After swap(c, d):\n" << "c: " << c << "\nd: " << d << '\n';
	std::cout << "min(c, d) = " << min(c, d) << '\n';
	std::cout << "max(c, d) = " << max(c, d) << std::endl;
	return (0);
}