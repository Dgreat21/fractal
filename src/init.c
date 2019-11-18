/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 03:11:51 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/11 10:45:38 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



t_mlx	*window(int w, int l)
{
	t_mlx	*win;

	if ((win = (t_mlx *)malloc(sizeof(t_mlx))) == NULL)
		error_notice("malloc win");
//	options(win);
//	win->wide = w;
//	win->length = l;
//	win->mid[X] = w / 2;
//	win->mid[Y] = l / 2;
	win->mp = mlx_init();
	win->wp = mlx_new_window(win->mp, w, l, "fdf");
	if ((win->img = mlx_new_image(win->mp, win->wide, win->length)) == NULL)
		error_notice("mlx_new_image error");
	if ((win->data = (int *)mlx_get_data_addr(win->img,
											  &(win->bpp), &(win->line_size),	&(win->endian))) == NULL)
		error_notice("mlx_get_data_addr error");
//	mlx_hook(win->wp, 17, 0, close_window, &win);
//	mlx_hook(win->wp, 2, 0, key_press, &win);
//	mlx_key_hook(win->wp, key, (void *)0);
	return (win);
}

t_mlx	*init_mlx(void)
{
	t_mlx	*res;

	if (!(res = (t_mlx *)malloc(sizeof(t_mlx))))
		error_notice("error malloc t_mlx");
	res->mp = mlx_init();
	if (!(res->wp = mlx_new_window(res->mp, WIDE, LENGTH, "Fractol")))
		error_notice("error create window");
	if (!(res->img = mlx_new_image(res->mp, WIDE, LENGTH)))
		error_notice("error image creation");
	res->data = (int *)mlx_get_data_addr(res->img, &res->bpp,
											  &res->line_size, &res->endian);

	return (res);
}


t_all	*init()
{
	t_all *all;
	t_mlx *mlx;

	if ((all = (t_all *)malloc(sizeof(t_all))) == NULL)
		error_notice("malloc all_struct");
//	mlx = window(WIDE, LENGTH);
//	all->mlx = mlx;
//	all->mlx = window(WIDE, LENGTH);
	all->mlx = init_mlx();

	all->zoom = 4;
//	all->mouse = ;
//	all->color = ;
	all->speed = 0.01;
	all->ud = 0;
	all->lr = 0;
	all->iter = MAX_ITER;
	all->minx = MIN_X;
	all->maxx = MAX_X;
	all->miny = MIN_Y;
	all->maxy = MAX_Y;
	all->shift_x = SHIFT_X;
	all->shift_y= SHIFT_Y;

	return (all);
}