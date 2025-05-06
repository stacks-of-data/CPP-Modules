/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:04:49 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/06 22:08:46 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

template <typename T>
void	func(T content);

template <typename T, typename B>
void	iter(T addr, size_t len, B func)
{
	if (len <= 0)
		return;
	for (size_t i = 0; i < len; i++)
		func(addr[i]);
}