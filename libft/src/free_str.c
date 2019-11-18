/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:57:16 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/23 03:14:09 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_str(char **stock)
{
	int i;

	i = 0;
	while (stock[i])
	{
		free(stock[i]);
		stock[i] = NULL;
		i++;
	}
	free(stock);
	stock = NULL;
	return ;
}
