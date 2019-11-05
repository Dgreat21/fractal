/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 21:46:52 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/01 05:38:23 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_end(t_list *head, t_list *elem)
{
	if (!head)
		return (elem);
	while (head->next)
		head = head->next;
	head->next = elem;
	return (head);
}
