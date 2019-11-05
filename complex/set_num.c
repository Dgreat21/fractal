/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 08:44:36 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/05 19:52:31 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

t_complex			contruct()
{
	t_complex z;

	set_complex = set_complex;
	cplx_plus = cplx_plus;
	cplx_minus = cplx_minus;
	cplx_mult_num = cplx_mult_num;
	cplx_rev_num = cplx_rev_num;
	cplx_abs_num = cplx_abs_num;
	cplx_arg = cplx_arg;
	cplx_mult = cplx_mult;
}


t_complex	set_complex(float re, float im)
{
	t_complex num;

	num = contruct();
	num.re = re;
	num.im = im;
	return (num);
}