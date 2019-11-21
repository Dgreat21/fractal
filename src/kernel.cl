/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    kernel.cl                                          :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: dgreat <marvin@42.fr>                      +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2019/11/20 13:01:19 by dgreat            #+#    #+#            */
/*    Updated: 2019/11/20 13:01:24 by dgreat           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define ABS(a)(a <= 0.0) ? -a : a
# define SQR(n) n * n

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_argb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_argb;

typedef union		u_color
{
	int				hex_color;
	t_argb			rgb;
}					t_color;

typedef struct		s_fractol
{
	int				length;
	int				wide;
	int				key;
	int				iter;
	int				color;
	int				pow;
	int				mouse;

	double			maxy;
	double			minx;
	double			lr;
	double			ud;
	double			shift_y;
	double			shift_x;
	double			mouse_pos_x;
	double			mouse_pos_y;
	double			zoom;
}					t_all;


t_complex		cmplx_plus(t_complex a, t_complex b)
{
	t_complex	c;

	c.re = a.re + b.re;
	c.im = a.im + b.im;
	return (c);
}

double			cmplx_abs_num(t_complex x)
{
	double		a = x.re;
	double		b = x.im;
	double		z;

	z = sqrt(a * a + b * b);
	return (z);
}

t_complex		cmplx_mult(t_complex a, t_complex b)
{
	t_complex	c;

	c.re = (a.re * b.re) - (a.im * b.im);
	c.im = (a.re * b.im) + (a.im * b.re);
	return (c);
}

t_complex		cmplx_pow(t_complex a, int power)
{
	t_complex	c;
	int			i;

	i = 0;
	c = a;
	while (++i < power)
		c = cmplx_mult(a, c);
	return (c);
}



t_complex		cmplx_sqr(t_complex a)
{
	return (cmplx_mult(a, a));
}

t_complex		cmplx_sqr_abs(t_complex a)
{
	t_complex	c;

	a.re = fabs(a.re);
	a.im = fabs(a.im);
	c.re = (a.re * a.re) - (a.im * a.im);
	c.im = (a.re * a.im) + (a.im * a.re);
	return (c);
}

int				color(int i, int color_key, int fractol, int repeats)
{
	int n = i;
	double t = (double)i / (double)repeats;
	int s = 100;

	if (color_key == 0)
		return (((n * 140 / s) << 8) + ((n * 255 / s) << 8) + n * 105 / s);
	if (color_key == 1)
		return (((n * 255 / 10) << 16) + ((n * 255 / 10) << 8) + n * 25 / 10);
	if (color_key == 2)
		return (((n * 255 / 40) << 16) + ((n * 255 / 10) << 8) + n * 255 / 300);
	if (color_key == 3)
		return (RGB((115.5 *  0.6 *(n) + 1), (125.5 *  0.4 *(n) + 1), (94.5 * (1 - 0.1 * (n)))));
	if (color_key == 4)
		return (((n * 80 / s) << 8) + ((n * 255 / s) << 16) + n * 145 / s);
	if (color_key == 5)
		return (RGB((75.5 *  0.1 *(n) + 1), (125.5 *  0.1 *(n) + 1), (34.5 * (1 - 0.1 * (n)))));
	if (color_key == 6)
		return (((n * 255 / s) << 2) + ((n * 255 / s) << 16) + n * 255 / s);
	if (color_key == 7)
		return (RGB((127.5 *  0.4 *(n) + 1), (127.5 *  0.1 *(n) + 1), (127.5 * (1 - 0.7 * (n)))));
	if (color_key == 8)
		return ((int)((255 - 37) * (1 - t) * t * t * t * 255) * (int)((255) * t * t * (1 - t) * (\
			1 - t) * 255) * (int)((154 - 30) * (1 - t) * (1 - t) * (1 - t) * t * 255));
	if (color_key == 9)
		return ((int)((134 - 6) * (1 - t) * t * t * t * 255) * (int)((134) * t * t * (1 - t) * (\
			1 - t) * 255) * (int)((134 - 6.5) * (1 - t) * (1 - t) * (1 - t) * t * 255));
}

int			__get_color(int max_iter, int iteration)
{
	t_color		color;
	double		t;

	t = (double)iteration / max_iter;
	color.rgb.r = (unsigned char)(9 * (1 - t) * pow(t, 3) * 255);
	color.rgb.g = (unsigned char)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.rgb.b = (unsigned char)(8.5 * pow((1 - t), 3) * t * 255);
	color.rgb.a = 1;
	return (color.hex_color);
}

void			__put_pixel(t_all *all, int x, int y, __global int *data, int iteration)
{
	data[y * all->wide + x] = __get_color(all->iter, iteration);
}

void			__mandelbrot(t_all *all, int x, int y, __global int *data)
{
	int			i;
	t_complex	z;
	t_complex	cmplx;

	i = 0;
	z.re = 0;
	z.im = 0;
	cmplx.re = all->zoom * ((float)x / (all->wide) - 0.5) + all->lr;
	cmplx.im = all->zoom * ((float)(all->length - y) / (all->length) - 0.5) - all->ud;
	while (++i < all->iter)
	{
		if (cmplx_abs_num(z) > 4)
			break;
		z = cmplx_plus(cmplx_pow(z, all->pow), cmplx);
	}
	__put_pixel(all, x, y, data, i);
}

void			__julia(t_all *all, int x, int y, __global int *data)
{
	int			i;
	t_complex	z;
	t_complex	c;


	i = 0;
	z.im = all->zoom * ((float)(all->length - y) / (all->length) - 0.5) - all->ud;
	z.re = all->zoom * ((float)x / (all->wide) - 0.5) + all->lr;

	while (++i < all->iter)
	{
		if (cmplx_abs_num(z) > 4)
			break ;
		z = cmplx_plus(cmplx_pow(z, all->pow), (t_complex){.im = all->mouse_pos_x, .re = all->mouse_pos_y});
	}
	__put_pixel(all, x, y, data, i);
}

void			__burning_ship(t_all *all, int x, int y, __global int *data)
{
	int			i;
	t_complex	z;
	t_complex	cmplx;

	i = 0;
	z.re = 0;
	z.im = 0;
	cmplx.im = -1* all->zoom * ((float)(all->length - y) / (all->length) - 0.5) - all->ud;
	cmplx.re = all->zoom * ((float)x / (all->wide) - 0.5) + all->lr;
	while (++i < all->iter)
	{
		if (cmplx_abs_num(z) > 4)
			break;
		z = cmplx_plus(cmplx_sqr_abs(z), cmplx);
	}
	__put_pixel(all, x, y, data, i);
}


void			__choose_fractal(t_all *all, int x, int y, __global int *data)
{
	if (all->key == 1)
		__mandelbrot(all, x, y, data);
	else if (all->key == 2)
		__julia(all, x, y, data);
	else
		__burning_ship(all, x, y, data);
}

__kernel void	fractol(__global int	*data,
						__global int	*i_arg,
						__global double	*f_arg)
{
	t_all	all;
	int		g_id;
	int		x;
	int		y;

	g_id = get_global_id(0);

	x = g_id % 1000;
	y = g_id / 1000;

	all.length = i_arg[0];
	all.wide = i_arg[1];
	all.key = i_arg[2];
	all.iter = i_arg[3];
	all.color = i_arg[4];
	all.pow = i_arg[5];
	all.mouse = i_arg[6];

	all.maxy = f_arg[0];
	all.minx = f_arg[1];
	all.shift_y = f_arg[2];
	all.shift_x = f_arg[3];
	all.lr = f_arg[4];
	all.ud = f_arg[5];
	all.mouse_pos_x = f_arg[6];
	all.mouse_pos_y = f_arg[7];
	all.zoom = f_arg[8];
	__choose_fractal(&all, x, y, data);
}

