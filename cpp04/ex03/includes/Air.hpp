/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Air.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:28:32 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/18 15:27:26 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AIR_HPP
#define AIR_HPP

#include "AMateria.hpp"

class Air : public AMateria
{
	public:
	Air();
	Air(const Air& obj);
	~Air();
	AMateria*	clone() const;
	void	use(ICharacter& target);
	Air&	operator= (const Air& obj);
};

#endif