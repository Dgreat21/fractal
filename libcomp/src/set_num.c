/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 08:44:36 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/11 06:24:42 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

t_complex	set_complex(float re, float im)
{
	t_complex num;

	num.re = re;
	num.im = im;
	return (num);
}
