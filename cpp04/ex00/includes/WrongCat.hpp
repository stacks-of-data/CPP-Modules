/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:02:53 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/15 01:32:00 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
	std::string	type;
	public:
	WrongCat();
	WrongCat(std::string& sType);
	WrongCat(const WrongCat &obj);
	~WrongCat();
	void makeSound() const;
	WrongCat&	operator= (const WrongCat& obj);
};

#endif