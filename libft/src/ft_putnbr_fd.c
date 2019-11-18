/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:17:09 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/23 00:09:04 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int nb, int fd)
{
	int		len;
	int		f;
	long	n;

	n = (long)nb;
	f = (n >= 0) ? (0) : (1);
	n = (n >= 0) ? n : -n;
	len = ft_log(n, 10);
	if (f == 1)
		ft_putchar_fd('-', fd);
	while (len)
	{
		f = ft_pow_uint(10, len - 1);
		ft_putchar_fd(n / f + '0', fd);
		len--;
		n %= f;
	}
}
