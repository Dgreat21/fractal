/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 21:06:22 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/01 05:38:23 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//unsigned int	ft_countw_delim(char const *s, char delim)
//{
//	unsigned int	i;
//	unsigned int	count;
//	unsigned char	f_word;
//
//	i = 0;
//	f_word = 0;
//	count = 0;
//	if (s)
//		while (s[i])
//		{
//			if (s[i] == delim || s[i] == 0)
//				if (f_word)
//					f_word = 0;
//			if (s[i] != delim && s[i])
//				if (!f_word)
//				{
//					count++;
//					f_word = 1;
//				}
//			i++;
//		}
//	return (count);
//}
//
//static unsigned int	wordend(char const *s, char const c, unsigned int i)
//{
//	while (s[i] && s[i] != c)
//		i++;
//	return (i);
//}
//
//static char			**abort_split(char **tab)
//{
//	unsigned int i;
//
//	i = 0;
//	while (tab[i])
//		ft_strdel(&tab[i++]);
//	free(tab);
//	tab = 0;
//	return (tab);
//}
//
//static void			init(unsigned int *i, unsigned int *w, unsigned int *j)
//{
//	*i = 0;
//	*w = 0;
//	*j = 0;
//}
//
//char				**ft_strsplit(char const *s, char c)
//{
//	unsigned int	tablen;
//	unsigned int	i;
//	unsigned int	w;
//	unsigned int	j;
//	char			**tab;
//
//	init(&i, &w, &j);
//	tab = 0;
//	tablen = ft_countw_delim(s, c);
//	if (s == 0)
//		return (0);
//	if ((tab = (char **)malloc(sizeof(char *) * (tablen + 1))) != 0)
//	{
//		tab[tablen] = 0;
//		while (w < tablen)
//			if (s[i] == c)
//				i++;
//			else
//			{
//				j = wordend(s, c, i);
//				if ((tab[w++] = ft_strsub(s, i, j - i)) == 0)
//					return (abort_split(tab));
//				i = j;
//			}
//	}
//	return (tab);
//}

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
