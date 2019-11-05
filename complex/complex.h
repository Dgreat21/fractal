/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 08:46:39 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/05 19:36:50 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_COMPLEX_H
# define FDF_COMPLEX_H

typedef			struct s_complex
{
float			re;
float			im;
const void*		set_complex;
const void*		cplx_plus;
const void*		cplx_minus;
const void*		cplx_mult_num;
const void*		cplx_rev_num;
const void*		cplx_abs_num;
const void*		cplx_arg;
const void*		cplx_mult;
}				t_complex;

t_complex			contruct();

t_complex			set_complex(float re, float im);

t_complex			cplx_plus(t_complex a, t_complex b);

t_complex			cplx_minus(t_complex a, t_complex b);

t_complex			cplx_mult_num(t_complex x, float alpha);

t_complex			cplx_rev_num(t_complex x);

float				cplx_abs_num(t_complex x);

float 				cplx_arg(t_complex a);

t_complex			cplx_mult(t_complex a, t_complex b);


#endif FDF_COMPLEX_H
