/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 03:26:25 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/05 20:05:12 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		grad_init(t_mlx *win)
{
	int		i;
	int		j;

	i = -1;
	while (++i < win->map.y)
	{
		j = -1;
		while (++j < win->map.x)
		{
			if (win->opt.color)
				win->list[i][j].hue = win->opt.hue;
			else if (win->opt.grad)
			{
				if (win->list[i][j].z >= 10)
					win->list[i][j].hue = win->high;
				else
					win->list[i][j].hue = win->low;
			}
			else
				win->list[i][j].hue = win->list[i][j].color;
		}
	}
}

void		create_proj(t_mlx *win, t_point **tab,
		t_point (*f)(t_mlx, t_point), void (*draw)(t_mlx*, t_line))
{
	int		i;
	int		j;
	t_point	a;
	t_point	b;

	i = -1;
	while (++i < win->map.y - 1)
	{
		j = -1;
		while (++j < win->map.x - 1)
		{
			a = f(*win, tab[i][j]);
			b = f(*win, tab[i][j + 1]);
			draw(win, line(a, b));
			b = f(*win, tab[i + 1][j]);
			draw(win, line(a, b));
		}
		draw(win, line(f(*win, tab[i][j]), f(*win, tab[i + 1][j])));
	}
	j = -1;
	while (++j < win->map.x - 1)
	{
		draw(win, line(f(*win, tab[i][j]), f(*win, tab[i][j + 1])));
	}
}

void		draw_map(t_mlx *win, t_point **map)
{
	const void	*projection = NULL;
	const void	*draw;

	grad_init(win);

	if (win->opt.axis == 1)
		projection = (drw_dt_iso);
	else if (win->opt.axis == 0)
		projection = (drw_dt_dim);
	else if (win->opt.axis == -1)
		projection = drw_dt_par;
	if (win->opt.slave == -1)
		draw = dot_md;
	else if (win->opt.slave == 1)
		draw = drawer_grad;
	else if (win->opt.slave == 0)
		draw = drawer;
	else
		draw = brez;
	create_proj(win, map, projection, draw);
//	mlx_put_image_to_window(win->mp, win->wp, win->img, 0, 0);
}
