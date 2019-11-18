/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:48:58 by dgreat            #+#    #+#             */
/*   Updated: 2019/04/26 21:29:27 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*pdst;
	const char		*psrc;
	size_t			i;

	psrc = src;
	pdst = dst;
	i = 0;
	if (pdst > psrc)
	{
		while (len > 0)
		{
			--len;
			pdst[len] = psrc[len];
		}
	}
	else if (pdst < psrc)
	{
		while (i < len)
		{
			pdst[i] = psrc[i];
			i++;
		}
	}
	return (dst);
}
