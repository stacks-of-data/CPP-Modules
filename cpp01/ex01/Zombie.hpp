/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:32:33 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/02 19:05:55 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
	std::string	z_name;
	public:
	Zombie();
	Zombie(std::string z_name);
	~Zombie();
	void	setZombieName(std::string z_name);
	void	announce(void);
};

Zombie*	zombieHorde(int N, std::string name);

#endif