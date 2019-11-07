///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   events_bonus.c                                     :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2019/10/24 15:59:42 by fcodi             #+#    #+#             */
///*   Updated: 2019/11/05 20:05:12 by dgreat           ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "fractol.h"
//#include "keys.h"
//
//void	diametric(int key, t_mlx *win)
//{
//	if (key == kVK_ANSI_Keypad1)
//	{
//		win->opt.up_down -= 5;
//		win->opt.left_right -= 5;
//	}
//	if (key == kVK_ANSI_Keypad3)
//	{
//		win->opt.up_down -= 5;
//		win->opt.left_right += 5;
//	}
//	if (key == kVK_ANSI_Keypad7)
//	{
//		win->opt.up_down += 5;
//		win->opt.left_right -= 5;
//	}
//	if (key == kVK_ANSI_Keypad9)
//	{
//		win->opt.up_down += 5;
//		win->opt.left_right += 5;
//	}
//}
//
//void	move(int key, t_mlx *win)
//{
//	if (key == kVK_ANSI_O)
//		(win->opt.rot) = (!win->opt.rot) ? (1) : (0);
//	if (win->opt.rot)
//	{
//		if (key == kVK_ANSI_Keypad2)
//			win->opt.up_down -= 5;
//		if (key == kVK_ANSI_Keypad4)
//			win->opt.left_right -= 5;
//		if (key == kVK_ANSI_Keypad6)
//			win->opt.left_right += 5;
//		if (key == kVK_ANSI_Keypad8)
//			win->opt.up_down += 5;
//		if (key == kVK_ANSI_Keypad5)
//		{
//			win->opt.left_right = 0;
//			win->opt.up_down = 0;
//		}
//		else
//			diametric(key, win);
//	}
//	else
//		rotate(key, win);
//}
//
//void	slave(int key, t_mlx *win)
//{
//	static int	c;
//
//	c = win->opt.slave;
//	if (key == kVK_ANSI_Z)
//		c = -1;
//	else if (key == kVK_ANSI_X)
//		c = 0;
//	else if (key == kVK_ANSI_C)
//		c = 1;
//	else if (key == kVK_ANSI_V)
//		c = 2;
//	else if (key == kVK_ANSI_KeypadDecimal)
//		c++;
//	if (c >= 3)
//		c = 0;
//	win->opt.slave = c;
//}
//
//void	zoom(int key, t_mlx *win)
//{
//	if (win->opt.bit == 1)
//	{
//		win->opt.bit = 0;
//		win->scale = 10;
//	}
//	if (key == kVK_ANSI_Equal && win->scale < 100)
//	{
//		if (win->scale)
//			win->scale += 1;
//		else
//			++win->scale;
//	}
//	else if (win->scale >= 1)
//		win->scale -= 1;
//}
//
//void	zoom_bits(int key, t_mlx *win)
//{
//	if (win->opt.bit == 0)
//	{
//		win->opt.bit = 1;
//		win->scale = 1;
//	}
//	if (key == kVK_ANSI_KeypadPlus && win->scale < 100)
//	{
//		if (win->scale)
//			win->scale <<= 1;
//		else
//			++win->scale;
//	}
//	else if (win->scale >= 1)
//		win->scale >>= 1;
//}
