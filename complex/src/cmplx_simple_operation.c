/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmplx_simple_operation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 06:24:06 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/11 08:06:41 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../complex.h"

t_complex	cmplx_plus(t_complex a, t_complex b)
{
	t_complex	c;

	c = set_complex(a.re + b.re, a.im + b.im);
	return (c);
}

t_complex	cmplx_minus(t_complex a, t_complex b)
{
	t_complex	c;

	c = set_complex(a.re - b.re, a.im - b.im);
	return (c);
}

t_complex	cmplx_mult_num(t_complex x, float alpha)
{
	t_complex	c;

	c = set_complex(alpha * x.re, alpha * x.im);
	return (c);
}

t_complex	cmplx_rev_num(t_complex x)
{
	t_complex	c;

	c = set_complex(x.re, -x.im);
	return (c);
}

float		cmplx_abs_num(t_complex x)
{
	const float		a = x.re;
	const float		b = x.im;
	float			z;

	z = sqrt(a * a + b * b);
	return (z);
}
