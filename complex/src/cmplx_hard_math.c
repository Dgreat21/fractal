/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmplx_hard_math.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 06:23:02 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/11 08:31:18 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../complex.h"

//float 		cmplx_arg(t_complex a)
//{
//	if (a.re > 0 && a.im > 0)
//		return (atan(a.im / a.re));
//	else if ((a.re == 0  || a.re == 1) && a.im == 0)
//		return (0);
//	else if (a.re == 0)
//	{
//		if (a.im < 0)
//			return (-M_PI_2);
//		else
//			return (M_PI_2);
//	}
//	if (a.re < 0 && a.im > 0)
//		return (M_PI_2 + atan(a.im / a.re));
//	if (a.re < 0 && a.im < 0)
//		return (atan(a.im / a.re) - M_PI_2);
//	return (0);
//}

t_complex	cmplx_pow(t_complex a, int power)
{
	t_complex c;//todo
	int i;
//	const float abs = cmplx_abs_num(a);
//	const float arg = cmplx_arg(a);
//
//	c.re = cos(arg);
//	c.im = sin(arg);
//
//	c = cmplx_mult_num(c, pow(abs, power));
	i = 0;
	c = a;
	while (++i < power)
		c = cmplx_mult(a, c);
	return (c);
}
//
//t_complex	cmplx_deg(t_complex a, int pow)
//{
//	t_complex c;//todo
//
//	c.re =
//}

t_complex	cmplx_mult(t_complex a, t_complex b)
{
	t_complex  c;

	c.re = (a.re * b.re) - (a.im * b.im);
	c.im = (a.re * b.im) + (a.im * b.re);
	return (c);
}

t_complex	cmplx_sqr(t_complex a)
{
	return (cmplx_mult(a, a));
}

//t_complex	cmplx_dev(t_complex a, t_complex b)
//{//todo
//	const t_complex c;
//
//	c = set_num(a.re - b.re, a.im - b.im);
//	return (c);
//}
