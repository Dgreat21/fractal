/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:09:31 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/18 17:28:53 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		 mouse_hand(int x, int y, void *param)
{
	t_all 	*all;

	all = (t_all *)param;
	all->mouse_pos = set_dot(4 * (x / WIDE - 0.5),
			4 * ((LENGTH - y) / LENGTH - 0.5));
	return (0);
}
