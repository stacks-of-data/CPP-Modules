/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:17:44 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/09 15:20:22 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#define COUNT_A 100000
#if COUNT_A < 0
	#undef COUNT_A
	#define COUNT_A 10
#endif
#define COUNT_B 10
#if COUNT_B < 0
	#undef COUNT_B
	#define COUNT_B 10
#endif
#define RAND_LIMIT 42
#if RAND_LIMIT <= 0
	#undef RAND_LIMIT
	#define RAND_LIMIT 1
#endif

#include <iostream>
#include <cstdlib>

#endif