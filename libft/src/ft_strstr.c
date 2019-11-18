/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:06:43 by dgreat            #+#    #+#             */
/*   Updated: 2019/04/25 18:19:50 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	res = (char *)str;
	if (to_find[0] != '\0')
	{
		while (str[i] != '\0')
		{
			j = 0;
			while (str[j + i] == to_find[j])
			{
				j++;
				if (to_find[j] == '\0')
					return (res + i);
			}
			i++;
		}
		return (0);
	}
	return ((char *)str);
}
