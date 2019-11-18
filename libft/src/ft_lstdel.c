/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 21:04:28 by dgreat            #+#    #+#             */
/*   Updated: 2019/04/23 18:01:51 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*target;
	t_list	*tmp;

	if (!alst || !(*alst) || !del)
		return ;
	target = *alst;
	while (target)
	{
		tmp = target->next;
		ft_lstdelone(&target, del);
		target = tmp;
	}
	*alst = NULL;
}
