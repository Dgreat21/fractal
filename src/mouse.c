/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:09:31 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/18 17:28:53 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_zoom(int button, t_point pos, t_all *all)
{
	if (button == MOUSE_SCROLL_UP)
	{
		all->minx *= 0.95;
		all->maxx *= 0.95;
		all->miny *= 0.95;
		all->iter += 2;
		all->zoom *= 0.9;
	}
	if (button == MOUSE_SCROLL_DOWN)
	{
		all->minx *= 1.1;
		all->maxx *= 1.1;
		all->miny *= 1.1;
		all->iter -= 2;
		all->zoom *= 1.1;
	}
	all->maxy = all->miny + (all->maxx - all->minx) * WIDE / LENGTH;
	all->shift_x = (all->maxx - all->minx) / (WIDE - 1);
	all->shift_y = (all->maxy - all->miny) / (LENGTH - 1);
}

int		mouse_click(int button, int x, int y, void *param)
{
	t_all		*all;
	t_point		pos;

	all = (t_all*)param;
	pos = set_dot(x, y);
	if (button == 1)
		all->mouse = !all->mouse;
	else if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		mouse_zoom(button, pos, all);
	run_fractol(all);
	return (0);
}

int		mouse_hand(int x, int y, void *param)
{
	t_all		*all;

	all = (t_all *)param;
	if (all->mouse)
	{
		all->mouse_pos = set_dot((float)x / WIDE, (float)y / LENGTH);
		run_fractol(all);
	}
	return (0);
}
