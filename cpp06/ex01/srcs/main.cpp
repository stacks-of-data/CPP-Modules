/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:22:38 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/06 02:05:48 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include <iostream>

int main()
{
	Data data;
	Data *ptr = &data;
	uintptr_t raw = Serializer::serialize(ptr);
	if (Serializer::deserialize(raw) == ptr)
		std::cout << "PTR is the same" << std::endl;
	else
		std::cout << "PTR is different" << std::endl;
	return (0);
}