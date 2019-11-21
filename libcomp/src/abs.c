/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 06:14:54 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/11 06:17:24 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int		ft_abs(float x)
{
	if (x >= 0)
		return (round(x));
	else
		return (round(-x));
}