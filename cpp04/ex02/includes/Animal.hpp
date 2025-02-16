/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:54 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/16 20:51:19 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
	protected:
	std::string	type;
	Animal();
	Animal(const std::string& type);
	Animal(const Animal& obj);
	Animal&	operator= (const Animal& obj);
	public:
	virtual ~Animal();
	std::string	getType() const;
	virtual void	makeSound() const;
};

#endif