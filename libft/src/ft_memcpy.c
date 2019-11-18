/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:48:53 by dgreat            #+#    #+#             */
/*   Updated: 2019/04/22 18:38:59 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	if (!dst && !src)
		return (dst);
	a = (unsigned char *)src;
	b = (unsigned char *)dst;
	while (n)
	{
		*b = *a;
		b++;
		a++;
		n--;
	}
	return (dst);
}
