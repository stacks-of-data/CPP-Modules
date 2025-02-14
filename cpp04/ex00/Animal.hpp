/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:54 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/15 01:30:50 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
	protected:
	std::string	type;
	public:
	Animal();
	Animal(std::string& type);
	Animal(const Animal& obj);
	virtual ~Animal();
	std::string	getType() const;
	virtual void	makeSound() const;
	Animal&	operator= (const Animal& obj);
};

#endif