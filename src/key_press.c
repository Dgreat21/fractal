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
		all->zoom *= 1.01;
	if (key == kVK_ANSI_KeypadMinus)
		all->zoom /= 1.01;
}

int	key_press(int key, void *param)
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
	else if (key == kVK_ANSI_KeypadPlus || key == kVK_ANSI_KeypadMinus)
		change_iteration(all, key);
	else if (key == kVK_ANSI_Minus || key == kVK_ANSI_Equal)
		zoom(all, key);
	else if (key >= kVK_LeftArrow && key <= kVK_UpArrow)
		arrow_control(all, key);
//	else if (key == K_MEN || key == K_BOL)
//		change_move_speed(all, key);
//	else if (key == K_BACKSPCE)
//		back_pls(all);
	draw(all);
	return (0);
}
