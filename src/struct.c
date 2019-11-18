/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 08:49:56 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/11 05:12:42 by dgreat           ###   ########.fr       */
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

