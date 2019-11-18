/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 04:19:22 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/14 20:43:58 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(int max_iter, int iteration)
{
	t_color	color;
	double	t;

	t = (double)iteration / max_iter;
	color.rgb.r = (unsigned char)(9 * (1 - t) * pow(t, 3) * 255);
	color.rgb.g = (unsigned char)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.rgb.b = (unsigned char)(8.5 * pow((1 - t), 3) * t * 255);
	color.rgb.a = 1;
	return (color.hex_color);
}

int		get_color_(int max_iter, int iteration)
{
	t_color	color;
	double	t;

	t = (double)iteration / max_iter;
	if (t == 0)
		color.hex_color = 0;
	else if (t >= 0.1)
		color.hex_color = 0xC4F1BE;
	else if (t >= 0.2)
		color.hex_color = 0x5BBA6F;
	else if (t >= 0.3)
		color.hex_color = 0x3FA34D;
	else if (t >= 0.4)
		color.hex_color = 0x2A9134;
	else if (t >= 0.5)
		color.hex_color = 0x137547;
	else if (t >= 0.6)
		color.hex_color = 0x054A29;
	else if (t >= 0.7)
		color.hex_color = 0x17301C;
	else if (t >= 0.8)
		color.hex_color = 0;
	else if (t >= 0.9)
		color.hex_color = 0;
	else if (t == 0)
		color.hex_color = 0;
	else
		color.hex_color = 1;
	color.rgb.a = 1;
	return (color.hex_color);
}

void	put_pixel(t_all *all, int x, int y, int iteration)
{
	all->mlx->data[y * WIDE + x] = get_color(all->iter, iteration);
}

void	draw(t_all *all)
{
	ft_bzero(all->mlx->data, WIDE * LENGTH * sizeof(int));
	if (all->key == MANDELBROT)
		mandelbrot(all);
	else if (all->key == JULIA)
		julia(all);
//	else if (all->key == BSHP)
//		bshp(all);
	mlx_put_image_to_window(all->mlx->mp, all->mlx->wp, all->mlx->img,
			0, 0);
}