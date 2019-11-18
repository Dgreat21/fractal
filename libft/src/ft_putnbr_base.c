/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 06:17:25 by dgreat            #+#    #+#             */
/*   Updated: 2019/09/14 06:18:24 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_base(unsigned int nb, size_t base, short flag)
{
	int		len;
	int		f;
	long	n;
	int		res;

	n = (long)nb;
	len = ft_log(n, base);
	while (len)
	{
		f = ft_pow_uint(base, len - 1);
		res = n / f;
		if (base > 10 && res >= 10)
			ft_putchar((flag) ? (res + 55) : (res + 87));
		len--;
		n %= f;
	}
}
