/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:58:19 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/02 19:05:43 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

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