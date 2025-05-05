/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_utils.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 02:29:29 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/06 02:35:48 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_UTILS_HPP
#define BASE_UTILS_HPP

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <cstdlib>
#include <iostream>

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif