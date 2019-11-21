/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 09:46:27 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/20 09:46:32 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	calculate_julia_iter_pow(t_all *all, int pow)
{
	int			i;
	t_complex	z;

	i = 0;
	z = all->cmplx;
	while (++i < all->iter)
	{
		if (cmplx_abs_num(z) > 4)
			return (i);
		z = cmplx_plus(cmplx_pow(z, pow),
				(t_complex){.im = all->mouse_pos.x, .re = all->mouse_pos.y});
	}
	return (0);
}

static int	calculate_julia_iter(t_all *all)
{
	int			i;
	t_complex	z;

	i = 0;
	z = all->cmplx;
	while (++i < all->iter)
	{
		if (cmplx_abs_num(z) > 4)
			return (i);
		z = cmplx_plus(cmplx_sqr(z),
				(t_complex){.im = all->mouse_pos.x, .re = all->mouse_pos.y});
	}
	return (0);
}

void		julia(t_all *all)
{
	int	y;
	int	x;

	y = 0;
	while (y < LENGTH)
	{
		x = 0;
		all->cmplx.im = all->zoom * ((float)(LENGTH - y) / (LENGTH) - 0.5)
				- all->ud;
		while (x < WIDE)
		{
			all->cmplx.re = all->zoom * ((float)x / (WIDE) - 0.5) + all->lr;
			if (all->pow > 0)
				put_pixel(all, x, y, calculate_julia_iter_pow(all, all->pow));
			else
				put_pixel(all, x, y, calculate_julia_iter(all));
			x++;
		}
		y++;
	}
}
