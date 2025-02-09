/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:09:51 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/09 17:09:52 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}
Point::Point(const float new_x, const float new_y) : x(new_x), y(new_y) {}
Point::Point(const Point& obj) : x(obj.x), y(obj.y) {}
Point::~Point() {}

Point&	Point::operator= (const Point& obj)
{
	std::cerr << "USELESS (Point attributes are const, they can't be modified)" << std::endl;
	return (*this);
}