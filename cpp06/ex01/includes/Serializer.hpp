/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:22:22 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/06 02:46:31 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

struct Data
{
	char	cVal;
	short	sVal;
	int		iVal;
};


class Serializer
{
	private:
	Serializer();
	Serializer(const Serializer& obj);
	~Serializer();
	Serializer	operator=(const Serializer& obj);
	public:
	static uintptr_t	serialize(Data* ptr);
	static Data*	deserialize(uintptr_t raw);
};

#endif