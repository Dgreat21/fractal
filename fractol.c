/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:03:49 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/05 21:51:30 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			brightness(t_color hue, float k)
{
	hue.rgb.r = (unsigned char)round((float)hue.rgb.r * k);
	hue.rgb.g = (unsigned char)round((float)hue.rgb.g * k);
	hue.rgb.b = (unsigned char)round((float)hue.rgb.b * k);
	return (hue.hex_color);
}

void		pixel_img(t_mlx *win, t_point dot)
{
	int		point;

	if ((dot.y > 0) && (dot.y < LENGTH) && (dot.x > 0) && (dot.x < WIDE))
	{
		point = ((int)dot.y * WIDE) + ((int)dot.x);
//		if (!win->opt.color)
//		{
			win->data[point] = dot.hue.hex_color;
//			win->data[++point] = dot.hue.rgb.g;
//			win->data[++point] = dot.hue.rgb.r;
//			win->data[++point] = dot.hue.rgb.a;
//		}
//		else
//		{
//			win->data[point] = dot.color.rgb.b;
//			win->data[++point] = dot.color.rgb.g;
//			win->data[++point] = dot.color.rgb.r;
//			win->data[++point] = dot.color.rgb.a;
//		}
	}
}

void		mandelbrot(t_all win)
{
	int	y;
	int	x;

	y = 0;
	while (y < LENGTH)
	{
		x = 0;
		fract->coord.c_y = fract->maxy - y * fract->shy + fract->ud;
		while (x < WIDTH)
		{
			fract->coord.c_x = fract->minx + x * fract->shx + fract->lr;
			calculate_mandelbrot(x, y, fract);
			x++;
		}
		y++;
	}
}

void		draw(t_all win)
{

	mandelbrot(win);
}

float		perc(float start, float end, float cur)
{
	const float	d = end - start;

	if (!(d))
		return (1.0);
	else
		return (((cur - start) / d));
}
//
//int			grad(float k, t_line l, float x)
//{
//	float			f;
//	t_color			res;
//	const t_color	a = l.d0.hue;
//	const t_color	b = l.d1.hue;
//
//	if (l.dir)
//		f = perc(l.d0.x, l.d1.x, x);
//	else
//		f = perc(l.d0.y, l.d1.y, x);
//	res.rgb.r = (unsigned char)(a.rgb.r * (1 - f) + b.rgb.r * f);
//	res.rgb.g = (unsigned char)(a.rgb.g * (1 - f) + b.rgb.g * f);
//	res.rgb.b = (unsigned char)(a.rgb.b * (1 - f) + b.rgb.b * f);
//	res.hex_color = brightness(res, k);
//	return (res.hex_color);
//}
