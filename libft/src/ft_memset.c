/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 06:18:27 by dgreat            #+#    #+#             */
/*   Updated: 2019/04/22 18:38:00 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*cptr;
	unsigned long	*lptr;
	unsigned char	uc;
	unsigned long	ul;
	size_t			mod;

	lptr = (unsigned long *)dest;
	uc = (unsigned char)c;
	ul = (unsigned long)uc;
	mod = sizeof(unsigned long);
	ul *= 0x101010101010101;
	mod = n / sizeof(unsigned long);
	while (mod--)
		*(lptr++) = ul;
	mod = n % sizeof(unsigned long);
	cptr = (unsigned char *)lptr;
	while (mod--)
		*(cptr++) = uc;
	return (dest);
}
