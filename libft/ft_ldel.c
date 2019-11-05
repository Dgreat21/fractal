/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 21:56:33 by dgreat            #+#    #+#             */
/*   Updated: 2019/11/01 05:38:23 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_ldel(t_list *prev, t_list *curr)
{
	prev->next = curr->next;
	curr->next = NULL;
	free(curr->content);
	free(curr);
	curr = NULL;
	return (prev);
}
