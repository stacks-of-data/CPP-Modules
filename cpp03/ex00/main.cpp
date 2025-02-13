/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:47:51 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/13 17:10:44 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <limits>

int main()
{
	ClapTrap	obj("claptrap_1");
	obj.attack("Human");
	obj.attack("Human");
	obj.attack("Human");
	obj.attack("Human");
	obj.takeDamage(5);
	obj.attack("Human");
	obj.beRepaired(5);
	obj.beRepaired(std::numeric_limits<unsigned int>::max());
	obj.attack("Human");
	obj.attack("Human");
	obj.attack("Human");
	obj.attack("Human");
	obj.attack("Human");
}