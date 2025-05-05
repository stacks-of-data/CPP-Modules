/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:22:34 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/06 02:05:11 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::Serializer(const Serializer& obj)
{
	(void)obj;
}

Serializer::~Serializer()
{

}

Serializer	Serializer::operator=(const Serializer& obj)
{
	(void)obj;
	return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	Data *ptr = reinterpret_cast<Data*>(raw);
	return (ptr);
}