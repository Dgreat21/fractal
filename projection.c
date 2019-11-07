///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   projection.c                                       :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2019/10/23 17:09:22 by dgreat            #+#    #+#             */
///*   Updated: 2019/11/05 20:05:12 by dgreat           ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "fractol.h"
//
//t_point		drw_dt_dim(t_mlx win, t_point dot)
//{
//	float		x;
//	float		y;
//	const int	zoom = win.scale;
//	t_point		res;
//
//
//	if (win.opt.bit)
//	{
//		dot.x = (int)(dot.x - win.map.x / 2) << zoom;
//		dot.y = (int)(dot.y - win.map.y / 2) << zoom;
//		dot.z = (int)dot.z << zoom;
//	}
//	else
//	{
//		dot.x = (dot.x - win.map.x / 2) * zoom;
//		dot.y = (dot.y - win.map.y / 2) * zoom;
//		dot.z *= zoom;
//	}
//	dot = rotate_x(win.rotx, dot);
//	dot = rotate_y(win.roty, dot);
//	dot = rotate_z(win.rotz, dot);
//	x = win.mid[X] + dot.x - dot.y * cos(PI / 4) + win.opt.left_right;
//	y = win.mid[Y] - dot.z + dot.y * cos(PI / 4) - win.opt.up_down;
//	res = set_dot_c(x, y, dot.hue.hex_color);
//	return (res);
//}
//
//t_point		drw_dt_iso(t_mlx win, t_point dot)
//{
//	float		x;
//	float		y;
//	const int	zoom = win.scale;
//	t_point		res;
//
//	if (win.opt.bit)
//	{
//		dot.x = (int)(dot.x - win.map.x / 2) << zoom;
//		dot.y = (int)(dot.y - win.map.y / 2) << zoom;
//		dot.z = (int)dot.z << zoom;
//	}
//	else
//	{
//		dot.x = (dot.x - win.map.x / 2) * zoom;
//		dot.y = (dot.y - win.map.y / 2) * zoom;
//		dot.z *= zoom;
//	}
//	dot = rotate_x(win.rotx, dot);
//	dot = rotate_y(win.roty, dot);
//	dot = rotate_z(win.rotz, dot);
//	x = win.mid[X] + (dot.x - dot.y) * cos(PI / 6) + win.opt.left_right;
//	y = win.mid[Y] - dot.z + (dot.x + dot.y) * cos(PI / 3) - win.opt.up_down;
//	res = set_dot_c(x, y, dot.hue.hex_color);
//	return (res);
//}
//
//t_point		drw_dt_par(t_mlx win, t_point dot)
//{
//	float		x;
//	float		y;
//	const int	zoom = win.scale;
//	t_point		res;
//
//	if (win.opt.bit)
//	{
//		dot.x = (int)(dot.x - win.map.x / 2) << zoom;
//		dot.y = (int)(dot.y - win.map.y / 2) << zoom;
//		dot.z = (int)dot.z << zoom;
//	}
//	else
//	{
//		dot.x = (dot.x - win.map.x / 2) * zoom;
//		dot.y = (dot.y - win.map.y / 2) * zoom;
//		dot.z *= zoom;
//	}
//	dot = rotate_x(win.rotx, dot);
//	dot = rotate_y(win.roty, dot);
//	dot = rotate_z(win.rotz, dot);
//	x = win.mid[X] + dot.x + win.opt.left_right;
//	y = win.mid[Y] + dot.y - win.opt.up_down;
//	res = set_dot_c(x, y, dot.hue.hex_color);
//	return (res);
//}
