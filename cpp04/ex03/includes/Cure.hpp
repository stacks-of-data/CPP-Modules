/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:28:32 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/18 02:00:54 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
	Cure();
	Cure(const Cure& obj);
	~Cure();
	AMateria*	clone() const;
	void	use(ICharacter& target);
	Cure&	operator= (const Cure& obj);
};

#endif