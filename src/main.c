/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 03:07:21 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/18 17:19:04 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			close_window(void *ptr)
{
	exit(0);
	ptr = NULL;
	return (0);
}

static char	*to_upper(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	return (str);
}

static int	parse_input_str(char **av)
{
	if (!(ft_strcmp(to_upper(av[1]), S_MANDELBROT)))
		return (MANDELBROT);
	else if (!(ft_strcmp(av[1], S_JULIA)))
		return (JULIA);
	else if (!(ft_strcmp(av[1], S_BSHP)))
		return (BSHP);
	return (0);
}

void		hook_init(t_all *all)
{
	mlx_hook(all->mlx->wp, 17, 0, close_window, all);
	mlx_hook(all->mlx->wp, 2, 0, key_press, all);
	mlx_hook(all->mlx->wp, 6, 0, mouse_hand, all);
	mlx_hook(all->mlx->wp, 4, 0, mouse_click, all);
}

int			main(int ac, char **av)
{
	t_all	*all;
	int		pow;

	if (ac == 3)
	{
		pow = ft_atoi(av[2]);
		pow = (pow > 2 && pow <= 50) ? (pow) : (0);
	}
	else if (ac == 2)
		pow = 2;
	if (ac == 2 || pow)
	{
		all = init();
		all->key = parse_input_str(av);
		all->pow = (pow >= 2) ? (pow) : (0);
		hook_init(all);
		init_cl(all);
		run_fractol(all);
		mlx_loop(all->mlx->mp);
	}
	else
		error_notice("Usage: ./fractol <fractol>\n\tYou can use this\
		fractols:\n\t1. Mandelbrot\n\t2. Julia\n\t3. Burning ship\
		you can add power to Mandekbrot and Julia [3 - 10]");
	return (0);
}
