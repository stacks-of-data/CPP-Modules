/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:29:06 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/07 23:17:44 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include "../includes/utils.hpp"
#include <vector>

#define COUNT 5
#if COUNT <= 0
	#undef COUNT
	#define COUNT 1
#endif
#define RAND_LIMIT 42
#if RAND_LIMIT <= 0
	#undef RAND_LIMIT
	#define RAND_LIMIT 1
#endif

int main()
{
	std::srand(time(NULL));
	std::cout << (int)time(NULL) << std::endl;
	std::vector<int> vec;
	std::list<int> list;
	try
	{
		for (std::size_t i = 0; i < COUNT; i++)
			vec.push_back(rand() % (RAND_LIMIT + 1));
		for (std::size_t i = 0; i < COUNT; i++)
			list.push_back(rand() % (RAND_LIMIT + 1));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	
	std::cout << "VECTOR PREVIEW:" << std::endl;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "LIST PREVIEW:" << std::endl;
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << '\n';
	int iVecN = vec[rand() % COUNT];
	int iListN = getRandomListElement(list);
	std::cout << "Selected " << iVecN << " to look for in the vector" << std::endl;
	std::cout << "Selected " << iListN << " to look for in the list" << std::endl;
	
	attemptEasyFind(vec, iVecN);
	attemptEasyFind(list, iListN);

	return (EXIT_SUCCESS);
}