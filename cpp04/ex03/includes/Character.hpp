/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 23:46:41 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/18 02:00:48 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
	std::string	_name;
	AMateria*	inventory[4];
	public:
	Character();
	Character(const std::string& name);
	Character(const Character& obj);
	~Character();
	std::string const& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	AMateria*	getInvSlotPtr(int index) const;
	Character&	operator= (const Character& obj);
};

#endif