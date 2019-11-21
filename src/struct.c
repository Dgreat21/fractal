/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 08:49:56 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/11 05:12:42 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point	set_dot(float x, float y)
{
	t_point	dot;

	dot.x = x;
	dot.y = y;
	return (dot);
}

void	swap_glist(t_point *a, t_point *b)
{
	ft_fswap(&(a->x), &(b->x));
	ft_fswap(&(a->y), &(b->y));
}
