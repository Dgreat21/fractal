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

static int	calculate_mandelbrot_iter(t_all *all)
{
	int			key;
	int 		i;
	t_complex	Z;

	i = 0;
	key = 0;
	Z = set_complex(0, 0);
	while (++i < all->iter)
	{
		if (cmplx_abs_num(Z) > 4)
			return (i);
		Z = cmplx_plus(cmplx_sqr(Z), all->cmplx);
	}
	return (0);
}

void		mandelbrot(t_all *all)
{
	int	y;
	int	x;

	y = 0;
	while (y < LENGTH)
	{
		x = 0;
		all->cmplx.im = all->maxy - y * all->shift_y + all->ud;
		while (x < WIDE)
		{
			all->cmplx.re = all->minx + x * all->shift_x + all->lr;
			put_pixel(all, x, y, calculate_mandelbrot_iter(all));
			x++;
		}
		y++;
	}
}
