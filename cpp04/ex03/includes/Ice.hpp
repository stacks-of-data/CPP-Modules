/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:28:32 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/18 02:00:53 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
	Ice();
	Ice(const Ice& obj);
	~Ice();
	AMateria*	clone() const;
	void	use(ICharacter& target);
	Ice&	operator= (const Ice& obj);
};

#endif