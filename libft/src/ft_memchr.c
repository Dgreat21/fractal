/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:48:30 by dgreat            #+#    #+#             */
/*   Updated: 2019/04/10 03:30:38 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*local;

	ch = (unsigned char)c;
	local = (unsigned char *)s;
	while (n--)
	{
		if (*local == ch)
			return ((void *)local);
		local++;
	}
	return (NULL);
}
