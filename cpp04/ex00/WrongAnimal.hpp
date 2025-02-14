/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:02:53 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/15 01:31:49 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	protected:
	std::string	type;
	public:
	WrongAnimal();
	WrongAnimal(std::string& type);
	WrongAnimal(const WrongAnimal& obj);
	virtual ~WrongAnimal();
	std::string	getType() const;
	void	makeSound() const;
	WrongAnimal&	operator= (const WrongAnimal& obj);
};

#endif