/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 20:25:06 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/23 00:09:04 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	sys(int n)
{
	char c;

	if (n >= 0 && n <= 9)
		c = (n + '0');
	else if (n >= 10 && n < 36)
		c = (n - 10 + 'A');
	else
		c = (0);
	return (c);
}

char		*ft_itoa_base(int m, int base)
{
	char	*tab;
	char	*tmp;
	int		len;
	int		f;
	long	n;

	n = (long)m;
	f = (n >= 0) ? (0) : (1);
	n = (n >= 0) ? n : -n;
	len = ft_log(n, base);
	if ((tab = (char *)malloc(sizeof(char) * (len + f + 1))) == NULL)
		return (NULL);
	tmp = tab;
	(f == 1) ? (*(tab++) = '-') : (0);
	while (len)
	{
		f = ft_pow_uint(base, len - 1);
		*tab = sys(n / f);
		tab++;
		len--;
		n %= f;
	}
	*tab = '\0';
	return (tmp);
}
