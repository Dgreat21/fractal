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

t_all	*init(void)
{
	t_all *all;
	t_mlx *mlx;

	if ((all = (t_all *)malloc(sizeof(t_all))) == NULL)
		error_notice("malloc all_struct");
	all->mlx = init_mlx();
	all->cl = (t_cl *)malloc(sizeof(t_cl));
	all->zoom = 4;
	all->mouse = 1;
	all->speed = 0.02;
	all->ud = 0;
	all->lr = 0;
	all->iter = MAX_ITER;
	all->minx = MIN_X;
	all->maxx = MAX_X;
	all->miny = MIN_Y;
	all->maxy = MAX_Y;
	all->shift_x = SHIFT_X;
	all->shift_y = SHIFT_Y;
	return (all);
}
