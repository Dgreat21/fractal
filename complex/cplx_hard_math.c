/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_hard_math.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 08:57:28 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/05 18:54:50 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

float 		cplx_arg(t_complex a)
{
	if (a.re > 0)
		return (arctan(a.im / a.re));
	else if ((a.re == 0  || a.re == 1) && a.im == 0)
		return (0);
	else if (a.re == 0)
	{
		if (a.im < 0)
			return (-PI / 2);
		else
			return (PI / 2);
	}
	if (a.re < 0 && a.im > 0)
		return (PI / 2 + arctan(a.im / a.re))
	if (a.re < 0 && a.im > 0)
		return (arctan(a.im / a.re) - PI / 2)
	return (0);
}

//t_complex	cplx_pow(t_complex a, int pow)
//{
//	t_complex c;//todo
//
//	c.re =
//}
//
//t_complex	cplx_deg(t_complex a, int pow)
//{
//	t_complex c;//todo
//
//	c.re =
//}

t_complex	cplx_mult(t_complex a, t_complex b)
{
	const t_complex c;

	c.re = (a.re * b.re) - (a.im * b.im);
	c.im = (a.re * b.im) + (a.im * b.re);
	return (c);
}

//t_complex	cplx_dev(t_complex a, t_complex b)
//{//todo
//	const t_complex c;
//
//	c = set_num(a.re - b.re, a.im - b.im);
//	return (c);
//}
