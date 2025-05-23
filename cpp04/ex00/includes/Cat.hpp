/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:02:53 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/16 21:45:16 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
	Cat();
	Cat(const std::string& sType);
	Cat(const Cat &obj);
	~Cat();
	void makeSound() const;
	Cat&	operator= (const Cat& obj);
};

#endif