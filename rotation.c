/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:32:44 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/05 20:05:12 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point 		rotate_x(double angle, t_point dot)
{
	t_point d;

	d = dot;
	d.x = dot.x;
	d.y = dot.y * cos(angle) + dot.z * sin(angle);
	d.z = dot.z * cos(angle) - dot.y * sin(angle);
	return (d);
}

t_point 		rotate_y(double angle, t_point dot)
{
	t_point d;

	d = dot;
	d.x = dot.x * cos(angle) + dot.z * sin(angle);
	d.z = -dot.x * sin(angle) + dot.z * cos(angle);
	return (d);
}

t_point 		rotate_z(double angle, t_point dot)
{
	t_point d;

	d = dot;
	d.x = dot.x * cos(angle) - dot.y * sin(angle);
	d.y = dot.y * cos(angle) - dot.x * sin(angle);
	return (d);
}