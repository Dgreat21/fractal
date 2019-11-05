/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_simple_operation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 08:52:40 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/04 13:00:24 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

t_complex	cplx_plus(t_complex a, t_complex b)
{
	const t_complex	c;

	c = set_num(a.re + b.re, a.im + b.im);
	return (c);
}

t_complex	cplx_minus(t_complex a, t_complex b)
{
	const t_complex	c;

	c = set_num(a.re - b.re, a.im - b.im);
	return (c);
}

t_complex	cplx_mult_num(t_complex x, float alpha)
{
	const t_complex	c;

	c = set_num(alpha * x.re, alpha * x.im);
	return (c);
}

t_complex	cplx_rev_num(t_complex x)
{
	const t_complex	c;

	c = set_num(x.re, -x.im);
	return (c);
}

float		cplx_abs_num(t_complex x)
{
	const float		a = x.re;
	const float		b = y.im;
	const float		z;

	z = abs(sqrt(a * a + b * b));
	return (z);
}