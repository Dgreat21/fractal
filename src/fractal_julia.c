//
// Created by Dyan Great on 11/11/2019.
//

#include "fractol.h"



static int	calculate_julia_iter(t_all *all, int x, int y)
{
	int			key;
	int 		i;
	float 		re_2;
	float 		im_2;
	t_complex	Z;
	t_complex	C;

	i = 0;
	key = 0;
	C.re = 4 * ((double)x / WIDE - 0.5);
	C.im = 4 * ((double)(LENGTH - y) / LENGTH - 0.5);
	Z = all->cmplx;

	while (++i < all->iter)
	{
		if (cmplx_abs_num(Z) > 4)
			return (i);

//		Z = cmplx_plus(cmplx_sqr(Z), (t_complex){.im = all->mouse_pos.x / 1000, .re = all->mouse_pos.y / 1000});
		Z = cmplx_plus(cmplx_sqr(Z), (t_complex){.im = 0.6 , .re = 0.3});
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
		all->cmplx.im = all->zoom * ((float)(LENGTH - y) / (LENGTH) - 0.5);
//		all->cmplx.im = (y + all->shift_y) / LENGTH + all->ud;
		while (x < WIDE)
		{
			all->cmplx.re = all->zoom * ((float)x / (WIDE) - 0.5);
//			all->cmplx.re = (x + all->shift_x) / WIDE + all->lr;
			put_pixel(all, x, y, calculate_julia_iter(all, x, y));
			x++;
		}
		y++;
	}
}

