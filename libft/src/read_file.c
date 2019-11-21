/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:56:38 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/20 12:56:44 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*read_file(int size, char *name)
{
	int				fd;
	int				i;
	char			*str;

	i = -1;
	if (size <= 0 || !name)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (++i < size)
		str[i] = '\0';
	if ((fd = open(name, O_RDONLY)) < 0)
	{
		ft_strdel(&str);
		return (NULL);
	}
	if ((read(fd, str, 0)) < 0)
		return (NULL);
	read(fd, str, size);
	return (str);
}
