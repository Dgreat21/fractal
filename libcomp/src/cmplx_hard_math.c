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

#include "complex.h"

t_complex	cmplx_pow(t_complex a, int power)
{
	t_complex	c;
	int			i;

	i = 0;
	c = a;
	while (++i < power)
		c = cmplx_mult(a, c);
	return (c);
}

t_complex	cmplx_mult(t_complex a, t_complex b)
{
	t_complex	c;

	c.re = (a.re * b.re) - (a.im * b.im);
	c.im = (a.re * b.im) + (a.im * b.re);
	return (c);
}

t_complex	cmplx_sqr(t_complex a)
{
	return (cmplx_mult(a, a));
}

t_complex	cmplx_sqr_abs(t_complex a)
{
	t_complex	c;

	a.re = fabs(a.re);
	a.im = fabs(a.im);
	c = cmplx_sqr(a);
	return (c);
}
