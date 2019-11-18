/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:55:36 by dgreat            #+#    #+#             */
/*   Updated: 2019/04/23 22:54:25 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*res;

	if (!lst || !f || !(res = (*f)(lst)))
		return (NULL);
	while ((lst = lst->next))
	{
		tmp = (*f)(lst);
		if (!tmp)
		{
			ft_lst_clear(res);
			return (NULL);
		}
		ft_lstadd_end(res, tmp);
	}
	return (res);
}
