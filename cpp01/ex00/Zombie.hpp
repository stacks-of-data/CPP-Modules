/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:32:33 by amsaleh           #+#    #+#             */
/*   Updated: 2024/12/21 23:10:01 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
	private:
	std::string	z_name;
	public:
	Zombie(std::string z_name);
	~Zombie();
	void	announce(void);
};

Zombie*	newZombie(std::string z_name);
void	randomChump(std::string z_name);

#endif