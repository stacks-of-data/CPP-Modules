/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:03:21 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/09 22:53:28 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point obj(2, 2);
	Point obj1(10, 10);
	Point obj2(1, 1);
	bool res = bsp(obj, obj1, obj2, Point(9.6, 9));
	std::cout << res << std::endl;
	return 0;
}