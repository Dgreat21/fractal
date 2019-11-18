/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:06:40 by dgreat            #+#    #+#             */
/*   Updated: 2019/04/19 18:16:36 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (!find[0])
		return ((char *)src);
	while (src[i] && i < len)
	{
		j = 0;
		if (src[i] == find[j])
		{
			k = i;
			j++;
			while (find[j] && src[++k] && src[k] == find[j] && k < len)
				j++;
			if (!find[j])
				return ((char *)(src + i));
		}
		i++;
	}
	return (NULL);
}
