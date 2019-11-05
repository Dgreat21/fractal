/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:35:58 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/05 21:42:00 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

int		close_window(void *ptr)
{
	exit(0);
	ptr = NULL;
	return (0);
}

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

t_mlx	*window(int w, int l)
{
	t_mlx	*win;

	if ((win = (t_mlx *)malloc(sizeof(t_mlx))) == NULL)
		error_notice("malloc win");
//	options(win);
	win->w = w;
	win->l = l;
	win->mid[X] = w / 2;
	win->mid[Y] = l / 2;
	win->mp = mlx_init();
	win->wp = mlx_new_window(win->mp, w, l, "fdf");
	if ((win->img = mlx_new_image(win->mp, win->w, win->l)) == NULL)
		error_notice("mlx_new_image error");
	if ((win->data = (int *)mlx_get_data_addr(win->img,
			&(win->bpp), &(win->lsize),	&(win->endian))) == NULL)
		error_notice("mlx_get_data_addr error");
	mlx_hook(win->wp, 17, 0, close_window, &win);
//	mlx_hook(win->wp, 2, 0, key_event, win);
//	mlx_key_hook(win->wp, key, (void *)0);
	return (win);
}

int		main(int ac, char **av)
{
//	char		symb[2];
	t_all		*win;

	if (ac == 1)
		error_notice("no option");
	else if (ac == 2)
	{
//		if (av[1] == "mandelbrot")
			win->mlx = window(WIDE, LENGTH);
			draw(win);
	}
	else
		error_notice("Too much arguments");
//	if (fd == -1)
//		error_notice("File opening error");
//	reader(fd);
	return (0);
}
