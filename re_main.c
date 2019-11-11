/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:35:58 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/11 03:14:25 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//int		key_event(int key, void *wina)
//{
//	t_mlx	*win;
//
//	win = (t_mlx *)wina;
//	if (key == kVK_ANSI_Equal || key == kVK_ANSI_Minus)
//		zoom(key, win);
//	else if (key == kVK_ANSI_KeypadPlus || key == kVK_ANSI_KeypadMinus)
//		zoom_bits(key, win);
//	if (key >= kVK_ANSI_Z || key <= kVK_ANSI_V || key == kVK_ANSI_KeypadDecimal)
//		slave(key, win);
//	if (key == kVK_ANSI_Keypad0 || key > kVK_ANSI_A - 1 || key < kVK_ANSI_D + 1)
//		projection(key, win);
//	if (key >= kVK_ANSI_Keypad1 || key <= kVK_ANSI_Keypad9 || key == kVK_ANSI_O)
//		move(key, win);
//	if (key == kVK_ANSI_L || key == kVK_ANSI_M)
//		coloring(key, win);
//	if (key == kVK_ANSI_H || key == kVK_ANSI_N)
//		color(key, win);
//	ft_bzero(win->data, win->l * win->w * sizeof(int));
//	draw_map(win, win->list);
//	mlx_put_image_to_window(win->mp, win->wp, win->img, 0, 0);
//	return (0);
//}

//void	options(t_mlx *win)
//{
//	win->rotx = 0;
//	win->roty = 0;
//	win->rotz = 0;
//	win->opt.slave = 0;
//	win->opt.bit = 0;
//	win->opt.grad = 0;
//	win->opt.axis = 1;
//	win->low.hex_color = BLUE;
//	win->high.hex_color = RED;
//	win->opt.hue.hex_color = WHITE;
//	win->opt.color = 0;
//	win->scale = 2;
//	win->opt.left_right = 0;
//	win->opt.up_down = 0;
//}

int		get_color(t_all *fract, int i)
{
	t_color	color;
	double	t;

	t = (double)i / fract->it;
	color.rgb.r = (unsigned char)(9 * (1 - t) * pow(t, 3) * 255);
	color.rgb.g = (unsigned char)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.rgb.b = (unsigned char)(8.5 * pow((1 - t), 3) * t * 255);
	color.rgb.a = 1;
	return (color.hex_color);
}

void	put_pixel(int x, int y, t_all *all, int i)
{
	all->mlx->data[y * WIDE + x] = get_color(all, i);
}

//todo: исправить эту функцию, она работает не так, как должна
static void	calculate_mandelbrot(int x, int y, t_all *all)
{
	int	i;

	i = 0;
	all->cmplx.key = 0;
	all->cmplx.z_x = all->cmplx.c_x;
	all->cmplx.z_y = all->cmplx.c_y;
	while (i < all->it)
	{
		all->cmplx.z_x = all->cmplx.z_x * all->cmplx.z_x;
		all->cmplx.z_y = all->cmplx.z_y * all->cmplx.z_y;
		if (all->cmplx.z_x + all->cmplx.z_y > 4)
		{
			all->cmplx.key = 1;
			break ;
		}
		all->cmplx.z_y = 2 * all->cmplx.z_x *
						   all->cmplx.z_y + all->cmplx.c_y;
		all->cmplx.z_x = all->cmplx.z_x -
						   all->cmplx.z_y + all->cmplx.c_x;
		i++;
	}
	all->cmplx.key ? put_pixel(x, y, all, i) : 0;
}

//todo: исправить эту функцию, она работает не так, как должна

void		mandelbrot(t_all *all)
{
	int	y;
	int	x;

	y = 0;
	while (y < LENGTH)
	{
		x = 0;
		all->cmplx.c_y = all->maxy - y * all->shift_y + all->ud;
		while (x < WIDE)
		{
			all->cmplx.c_x = all->minx + x * all->shift_x + all->lr;
			calculate_mandelbrot(x, y, all);
			x++;
		}
		y++;
	}
}
