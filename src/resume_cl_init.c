/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resume_cl_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 23:46:39 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/20 23:46:41 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				fill_background(int color, t_all *f)
{
	int				x;
	int				y;
	int				i;

	i = -1;
	while (++i < WIDE * LENGTH)
	{
		x = i % WIDE;
		y = i / WIDE;
		f->mlx->data[y * WIDE + x] = color;
	}
}

void				*run_fractol(t_all *f)
{
	size_t		kernel_num;
	int			ret;
	int			mem[32];
	double		dmem[32];

	mlx_clear_window(f->mlx->mp, f->mlx->wp);
	fill_background(0, f);
	kernel_num = WIDE * LENGTH;
	fill_arg(f, mem, dmem);
	ret = clEnqueueWriteBuffer(f->cl->queue, f->cl->cl_i_arg, CL_TRUE, 0,
			sizeof(int) * 32, mem, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(f->cl->queue, f->cl->cl_f_arg, CL_TRUE, 0,
			sizeof(double) * 32, dmem, 0, NULL, NULL);
	ret = clEnqueueNDRangeKernel(f->cl->queue, f->cl->kernel, 1, NULL,
			&kernel_num, NULL, 0, NULL, NULL);
	ret = clEnqueueReadBuffer(f->cl->queue, f->cl->cl_data, CL_TRUE, 0,
			sizeof(int) * WIDE * LENGTH, f->mlx->data, 0, NULL, NULL);
	mlx_put_image_to_window(f->mlx->mp, f->mlx->wp, f->mlx->img, 0, 0);
	return (f);
}
