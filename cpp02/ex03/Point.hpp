/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:09:53 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/09 17:09:56 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
	const Fixed x;
	const Fixed y;
	public:
	Point();
	Point(const float new_x, const float new_y);
	Point(const Point& obj);
	~Point();
	Point&	operator= (const Point& obj);
};

#endif