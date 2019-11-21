/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 04:07:44 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/11 10:09:51 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	default_(t_all *all)
{
	all->zoom = 4;
	all->mouse = 1;
	all->speed = 0.03;
	all->ud = 0;
	all->lr = 0;
	all->iter = MAX_ITER;
	all->minx = MIN_X;
	all->maxx = MAX_X;
	all->miny = MIN_Y;
	all->maxy = MAX_Y;
	all->shift_x = SHIFT_X;
	all->shift_y = SHIFT_Y;
}

void	change_iteration(t_all *all, int key)
{
	if (key == kVK_ANSI_Equal)
		all->iter += 2;
	if (key == kVK_ANSI_Minus)
		all->iter -= 2;
	if (all->iter < 0)
		all->iter = 0;
}

void	arrow_control(t_all *all, int key)
{
	if (key == kVK_LeftArrow)
		all->lr += all->speed;
	else if (key == kVK_RightArrow)
		all->lr -= all->speed;
	else if (key == kVK_DownArrow)
		all->ud -= all->speed;
	else if (key == kVK_UpArrow)
		all->ud += all->speed;
}

void	zoom(t_all *all, int key)
{
	if (key == kVK_ANSI_KeypadPlus)
	{
		all->minx *= 0.95;
		all->maxx *= 0.95;
		all->miny *= 0.95;
		all->iter += 1;
		all->zoom /= 1.1;
		all->speed /= all->zoom * 8;
	}
	if (key == kVK_ANSI_KeypadMinus)
	{
		all->minx *= 1.1;
		all->maxx *= 1.1;
		all->miny *= 1.1;
		all->iter -= 1;
		all->zoom *= 1.1;
		all->speed *= all->zoom / 8;
	}
}

int		key_press(int key, void *param)
{
	t_all	*all;

	all = (t_all *)param;
	if (key == kVK_Escape)
		exit(0);
	else if (key == kVK_ANSI_B)
		all->key = BSHP;
	else if (key == kVK_ANSI_J)
		all->key = JULIA;
	else if (key == kVK_ANSI_M)
		all->key = MANDELBROT;
	else if (key == kVK_ANSI_D)
		default_(all);
	else if (key == kVK_ANSI_KeypadPlus || key == kVK_ANSI_KeypadMinus)
		change_iteration(all, key);
	else if (key == kVK_ANSI_Minus || key == kVK_ANSI_Equal)
		zoom(all, key);
	else if (key >= kVK_LeftArrow && key <= kVK_UpArrow)
		arrow_control(all, key);
	run_fractol(all);
	return (0);
}
