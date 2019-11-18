/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 06:22:15 by dgreat            #+#    #+#             */
/*   Updated: 2019/09/25 06:25:12 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_min(int a, int b)
{
	return ((a > b) ? (b) : (a));
}

int		ft_max(int a, int b)
{
	return ((a < b) ? (b) : (a));
}

float	ft_fmin(float a, float b)
{
	return ((a > b) ? (b) : (a));
}

float	ft_fmax(float a, float b)
{
	return ((a < b) ? (b) : (a));
}
