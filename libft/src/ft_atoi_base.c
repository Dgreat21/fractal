/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 23:14:55 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/23 00:09:04 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		num(char c)
{
	if (47 < c && c < 58)
		return (c - 48);
	if (64 < c && c < 91)
		return (c - 55);
	if (96 < c && c < 123)
		return (c - 87);
	return (100);
}

static int		sys(char c, int base)
{
	if (num(c) < base)
		return (1);
	else
		return (0);
}

int				ft_atoi_base(const char *s, int base)
{
	long int	nb;
	int			i;
	int			f;
	long int	pnb;

	i = 0;
	pnb = 0;
	f = 0;
	nb = 0;
	while ((s[i] >= '\t' && s[i] <= '\r') || s[i] == ' ')
		i++;
	if ((s[i] > 47 && s[i] < 58) || (s[i] > 64 && s[i] < 91) || (s[i] == '+'))
		f++;
	(s[i] > 96 && s[i] < 123) ? (f++) : (0);
	(s[i] == '-') ? (f--) : (0);
	((s[i] == '+') || (s[i] == '-')) ? (i++) : (0);
	while (sys(s[i], base) && s[i])
	{
		pnb = nb;
		nb = nb * base + num(s[i]);
		i++;
		if (pnb != nb / base)
			return ((f > 0) ? -1 : 0);
	}
	return (nb * f);
}
