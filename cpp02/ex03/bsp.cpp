/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:09:43 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/14 23:13:25 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (a == b || a == c || b == c)
	{
		std::cerr << "bsp: some vertices are identical!" << std::endl;
		return (false);
	}
	Fixed sl_ab = (a.getX() * b.getY()) - (a.getY() * b.getX());
	Fixed sl_bc = (b.getX() * c.getY()) - (b.getY() * c.getX());
	Fixed sl_ca = (c.getX() * a.getY()) - (c.getY() * a.getX());
	Fixed sl_bp = (b.getX() * point.getY()) - (b.getY() * point.getX());
	Fixed sl_pa = (point.getX() * a.getY()) - (point.getY() * a.getX());
	Fixed sl_ap = (a.getX() * point.getY()) - (a.getY() * point.getX());
	Fixed sl_pc = (point.getX() * c.getY()) - (point.getY() * c.getX());
	Fixed sl_cp = (c.getX() * point.getY()) - (c.getY() * point.getX());
	Fixed sl_pb = (point.getX() * b.getY()) - (point.getY() * b.getX());
	Fixed sl_abp_res = sl_ab + sl_bp + sl_pa;
	Fixed sl_bcp_res = sl_bc + sl_cp + sl_pb;
	Fixed sl_cap_res = sl_ca + sl_ap + sl_pc;
	return ((sl_abp_res > 0 && sl_bcp_res > 0 && sl_cap_res > 0) || (sl_abp_res < 0 && sl_bcp_res < 0 && sl_cap_res < 0));
}