/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 05:48:33 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/18 16:11:32 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	calculate_mandelbrot_iter_pow(t_all *all, int pow)
{
	int			i;
	t_complex	z;

	i = 0;
	z = set_complex(0, 0);
	while (++i < all->iter)
	{
		if (cmplx_abs_num(z) > 4)
			return (i);
		z = cmplx_plus(cmplx_pow(z, pow), all->cmplx);
	}
	return (0);
}

static int	calculate_mandelbrot_iter(t_all *all)
{
	int			i;
	t_complex	z;

	i = 0;
	z = set_complex(0, 0);
	while (++i < all->iter)
	{
		if (cmplx_abs_num(z) > 4)
			return (i);
		z = cmplx_plus(cmplx_sqr(z), all->cmplx);
	}
	return (0);
}

void		mandelbrot(t_all *all)
{
	int			y;
	int			x;

	y = 0;
	while (y < LENGTH)
	{
		x = 0;
		all->cmplx.im = all->maxy - y * all->shift_y - all->ud;
		while (x < WIDE)
		{
			all->cmplx.re = all->minx + x * all->shift_x + all->lr;
			if (all->pow > 0)
				put_pixel(all, x, y,
						calculate_mandelbrot_iter_pow(all, all->pow));
			else
				put_pixel(all, x, y, calculate_mandelbrot_iter(all));
			x++;
		}
		y++;
	}
}
