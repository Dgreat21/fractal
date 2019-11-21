/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcomp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 08:46:39 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/11 06:48:23 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_COMPLEX_H
# define FDF_COMPLEX_H

# include "math.h"

typedef struct		s_complex
{
	float			re;
	float			im;
}					t_complex;

t_complex			contruct();

int					ft_abs(float x);

t_complex			set_complex(float re, float im);

t_complex			cmplx_plus(t_complex a, t_complex b);

t_complex			cmplx_minus(t_complex a, t_complex b);

t_complex			cmplx_pow(t_complex a, int power);

t_complex			cmplx_mult_num(t_complex x, float alpha);

t_complex			cmplx_rev_num(t_complex x);

float				cmplx_abs_num(t_complex x);

float				cmplx_arg(t_complex a);

t_complex			cmplx_mult(t_complex a, t_complex b);

t_complex			cmplx_sqr(t_complex a);

t_complex			cmplx_sqr_abs(t_complex a);

#endif
