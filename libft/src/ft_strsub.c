/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:40:07 by dgreat            #+#    #+#             */
/*   Updated: 2019/04/19 21:33:38 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *tab;
	char *tmp;

	if (!s)
		return (NULL);
	if ((tab = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (start && *s)
	{
		s++;
		start--;
	}
	tmp = tab;
	while (*s && len)
	{
		*tab = *s;
		tab++;
		s++;
		len--;
	}
	*tab = 0;
	return (tmp);
}
