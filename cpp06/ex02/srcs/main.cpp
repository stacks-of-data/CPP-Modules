/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 02:30:19 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/06 02:50:00 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base_utils.hpp"
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	Base *ptr1 = 0;
	Base *ptr2 = 0;
	try
	{
		ptr1 = generate();
		ptr2 = generate();
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << "Allocation failure: " << e.what() << std::endl;
		delete ptr1;
		delete ptr2;
		return (EXIT_FAILURE);
	}
	identify(ptr1);
	identify(*ptr2);
	Base test;
	identify(test);
	delete ptr1;
	delete ptr2;
	return (EXIT_SUCCESS);
}