/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 21:06:22 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/23 00:04:38 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_go_next(char const *s, char c)
{
	int	i;

	i = 0;
	if (!s || !c)
		return (NULL);
	while (s[i] && s[i] != c)
		i++;
	while (s[i] && s[i] == c)
		i++;
	if (!s[i])
		return (NULL);
	return ((char *)s + i);
}

static int		ft_strlendel(char const *s, char c)
{
	int	i;
	int	res;

	i = 0;
	if (!s || !c)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	res = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		res++;
	}
	return (res);
}

static	void	ft_clear(char ***res)
{
	int	i;

	if (!res || !(*res))
		return ;
	i = 0;
	while ((*res)[i])
	{
		free((*res)[i]);
		i++;
	}
	free(*res);
	*res = NULL;
}

static void		ft_move(char **now, char c, char ***res, int j)
{
	if (!((*res)[j] = ft_strsub(*now, 0, ft_strlendel(*now, c))))
		ft_clear(res);
	*now = ft_go_next(*now, c);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	char	*now;
	int		i;
	int		j;
	int		len;

	if (!s || !c)
		return (NULL);
	len = ft_word_counter(s, c);
	if (!(res = (char **)malloc((len + 1) * sizeof(char *))))
		return (NULL);
	res[len] = NULL;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	now = (char *)s + i;
	j = 0;
	while (j < len)
	{
		ft_move(&now, c, &res, j);
		if (!res)
			return (NULL);
		j++;
	}
	return (res);
}
