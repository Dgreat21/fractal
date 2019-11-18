//header


#include "fractol.h"


static int	calculate_burning_ship_iter(t_all *all)
{

	int 		i;
	t_complex	z;

	i = 0;
	z = set_complex(0, 0);
	while (++i < all->iter)
	{
		if (cmplx_abs_num(z) > 4)
			return (i);
//		z = cmplx_plus(cmplx_sqr(z), all->cmplx);
		z = cmplx_plus(cmplx_sqr_abs(z), all->cmplx);
	}
	return (0);
}

void		burning_ship(t_all *all)
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
			put_pixel(all, x, y, calculate_burning_ship_iter(all));
			x++;
		}
		y++;
	}
}