/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:48:26 by dgreat            #+#    #+#             */
/*   Updated: 2019/04/15 22:21:08 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*psrc;
	unsigned char	*pdst;
	unsigned char	ch;
	size_t			i;

	i = 0;
	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	ch = (unsigned char)c;
	while (n)
	{
		*pdst = *psrc;
		pdst++;
		psrc++;
		n--;
		i++;
		if (*(psrc - 1) == ch)
		{
			return (dst + i);
		}
	}
	return (NULL);
}
