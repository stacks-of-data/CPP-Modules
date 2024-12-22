/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:58:19 by amsaleh           #+#    #+#             */
/*   Updated: 2024/12/22 21:34:02 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
	private:
	std::string	weapon_type;
	public:
	Weapon(std::string weapon_type);
	~Weapon();
	const std::string	getType();
	void				setType(std::string new_weapon_type);
};

#endif