/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:28:32 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/18 14:49:02 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRE_HPP
#define FIRE_HPP

#include "AMateria.hpp"

class Fire : public AMateria
{
	public:
	Fire();
	Fire(const Fire& obj);
	~Fire();
	AMateria*	clone() const;
	void	use(ICharacter& target);
	Fire&	operator= (const Fire& obj);
};

#endif