/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:53:19 by dgreat            #+#    #+#             */
/*   Updated: 2019/04/26 21:12:59 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*res;

	if (!s)
		return (NULL);
	start = 0;
	while (ft_iswhitespace(s[start]))
		start++;
	end = ft_strlen(s) - 1;
	while (ft_iswhitespace(s[end]) && end >= start)
		end--;
	res = ft_strnew(end - start + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	return (res);
}
