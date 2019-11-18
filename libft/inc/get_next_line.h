/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:18:34 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/23 00:09:04 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# define BUFF_SIZE 5000000

typedef struct		s_mlist
{
	void			*data;
	size_t			size;
	int				x;
}					t_mlist;

enum				e_strings{glue, duplicate, linebreak};

int					get_next_line(const int fd, char **line);

#endif
