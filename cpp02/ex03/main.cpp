/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:03:21 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/11 22:52:09 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point a(0, 0);
	Point b(30, 10);
	Point c(15, 20);
	bool res = bsp(a, b, c, Point(1, 1));
	std::cout << res << std::endl;
	return 0;
}