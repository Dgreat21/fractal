/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:59:25 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/05 20:05:12 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		dot_md(t_mlx *win, t_line l)
{
	pixel_img(win, l.d0);
	pixel_img(win, l.d1);
}

void		brez(t_mlx *win, t_line l)
{
	float	x;
	float	y;
	int		end;

	x = (l.dir) ? (l.d0.x) : (l.d0.y);
	y = (l.dir) ? (l.d0.y) : (l.d0.x);
	end = (l.dir) ? (l.d1.x) : (l.d1.y);
	--x;
	if (l.dir)
		while (++x <= end)
		{
			pixel_img(win, set_dot_c(x, y, l.d0.hue.hex_color));
			y += l.k;
		}
	else
		while (++x <= end)
		{
			pixel_img(win, set_dot_c(y, x, l.d0.hue.hex_color));
			y += l.k;
		}
}

void		drawer(t_mlx *win, t_line l)
{
	float	x;
	float	y;
	int		end;

	x = (l.dir) ? (l.d0.x - 1) : (l.d0.y - 1);
	y = (l.dir) ? (l.d0.y) : (l.d0.x);
	end = (int)((l.dir) ? (l.d1.x) : (l.d1.y));
	if (l.dir)
		while (++x <= end)
		{
			pixel_img(win, set_dot_c(x, y, brightness(l.d0.hue, 1 - fract(y))));
			pixel_img(win, set_dot_c(x, y + 1, brightness(l.d0.hue, fract(y))));
			y += l.k;
		}
	else
		while (++x <= end)
		{
			pixel_img(win, set_dot_c(y, x, brightness(l.d0.hue, 1 - fract(y))));
			pixel_img(win, set_dot_c(y + 1, x, brightness(l.d0.hue, fract(y))));
			y += l.k;
		}
}

void		drawer_grad(t_mlx *win, t_line l)
{
	float			x;
	float			y;
	int				end;

	x = (l.dir) ? (l.d0.x - 1) : (l.d0.y - 1);
	y = (l.dir) ? (l.d0.y) : (l.d0.x);
	end = (l.dir) ? (l.d1.x) : (l.d1.y);
	if (l.dir)
		while (++x <= end)
		{
			pixel_img(win, set_dot_c(x, y, grad(1 - fract(y), l, x)));
			pixel_img(win, set_dot_c(x, y + 1, grad(fract(y), l, x)));
			y += l.k;
		}
	else
		while (++x <= end)
		{
			pixel_img(win, set_dot_c(y, x, grad(1 - fract(y), l, x)));
			pixel_img(win, set_dot_c(y + 1, x, grad(fract(y), l, x)));
			y += l.k;
		}
}
