/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:59:54 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/18 19:26:33 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class AAnimal
{
	protected:
	std::string	type;
	AAnimal();
	AAnimal(const std::string& type);
	AAnimal(const AAnimal& obj);
	AAnimal&	operator= (const AAnimal& obj);
	public:
	virtual ~AAnimal();
	std::string	getType() const;
	virtual void	makeSound() const = 0;
};

#endif