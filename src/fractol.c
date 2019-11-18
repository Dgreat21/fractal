/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:03:49 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/11 05:11:07 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			brightness(t_color hue, float k)
{
	hue.rgb.r = (unsigned char)round((float)hue.rgb.r * k);
	hue.rgb.g = (unsigned char)round((float)hue.rgb.g * k);
	hue.rgb.b = (unsigned char)round((float)hue.rgb.b * k);
	return (hue.hex_color);
}

float		perc(float start, float end, float cur)
{
	const float	d = end - start;

	if (!(d))
		return (1.0);
	else
		return (((cur - start) / d));
}
