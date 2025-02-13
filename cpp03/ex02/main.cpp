/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:47:51 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/13 20:04:25 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
	obj_scav->guardGate();
	for (int i = 0; i < 10; i++)
		obj_scav->attack("Human");
	delete obj_scav;
	FragTrap	*obj_frag = new FragTrap("fragtrap_1");
	obj_frag->highFivesGuys();
	for (int i = 0; i < 90; i++)
		obj_frag->attack("Alien");
	obj_frag->highFivesGuys();
	for (int i = 0; i < 11; i++)
		obj_frag->attack("Alien");
	delete obj_frag;
}