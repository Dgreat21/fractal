/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 03:07:21 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/18 16:11:17 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		close_window(void *ptr)
{
	exit(0);
	ptr = NULL;
	return (0);
}

int		key(int key)
{
	if (key == kVK_Escape)
		exit(0);
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
	mlx_key_hook(all->mlx->wp, key, (void *)0);
}

int			main(int ac, char **av)
{
	t_all	*all;

//	errno = 0;
	if (ac == 2)
	{
		all = init();
		all->key = parse_input_str(av);
		hook_init(all);
		draw(all);
		mlx_loop(all->mlx->mp);
	}
	else
		error_notice("Usage: ./fractol <fractol>\n\tYou can use this fractols:\
					\n\t1. Mandelbrot\
					\n\t2. Julia\
					\n\t3. Burning ship");
	return (0);
}
