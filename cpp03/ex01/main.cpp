/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:47:51 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/13 18:28:17 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap	*obj_clap = new ClapTrap("claptrap_1");
	for (int i = 0; i < 4; i++)
		obj_clap->attack("Human");
	obj_clap->takeDamage(5);
	obj_clap->attack("Human");
	obj_clap->beRepaired(5);
	obj_clap->beRepaired(0);
	for (int i = 0; i < 5; i++)
		obj_clap->attack("Human");
	delete obj_clap;
	ScavTrap	*obj_scav = new ScavTrap("scavtrap_1");
	for (int i = 0; i < 10; i++)
		obj_scav->attack("Human");
	obj_scav->takeDamage(5);
	obj_scav->attack("Human");
	obj_scav->beRepaired(5);
	for (int i = 0; i < 10; i++)
		obj_scav->attack("Human");
	delete obj_scav;
}