/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 08:49:56 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/05 20:05:12 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point	set_dot(float x, float y)
{
	t_point	dot;

	dot.x = x;
	dot.y = y;
	return (dot);
}

t_point	set_dot_c(float x, float y, int hue)
{
	t_point	dot;

	dot = set_dot(x, y);
	dot.hue.hex_color = hue;
	return (dot);
}

t_point	set_xyz(float x, float y, char *z_color, int color)
{
	t_point		dot;
	t_string	*cache;

	dot.x = x;
	dot.y = y;
	cache = ft_strsplit(z_color, ',');
	dot.z = ft_atoi(cache[0]);
	if (cache[1])
		dot.color.hex_color = ft_atoi_base(cache[1] + 2, 16);
	else
		dot.color.hex_color = color;
	dot.hue.hex_color = color;
	free_str(cache);
	return (dot);
}

void	swap_glist(t_point *a, t_point *b)
{
	ft_fswap(&(a->x), &(b->x));
	ft_fswap(&(a->y), &(b->y));
	ft_swap(&(a->hue.hex_color), &(b->hue.hex_color));
}

t_line	line(t_point a, t_point b)
{
	t_line	l;
	t_point d;

	l.d0 = a;
	l.d1 = b;
	d = set_dot(l.d1.x - l.d0.x, l.d1.y - l.d0.y);
	if (fabsf(d.y) > fabsf(d.x))
	{
		l.dir = 0;
		l.k = (d.x) / (d.y);
		(a.y > b.y) ? (swap_glist(&l.d0, &l.d1)) : (0);
	}
	else
	{
		l.dir = 1;
		l.k = (d.y) / (d.x);
		(a.x > b.x) ? (swap_glist(&l.d0, &l.d1)) : (0);
	}
	return (l);
}
