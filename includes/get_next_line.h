/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 04:37:40 by unite             #+#    #+#             */
/*   Updated: 2020/02/26 04:56:54 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE	32
# define EOL		'\n'

# include "libft.h"

typedef struct		s_list
					t_list;

typedef struct		s_fd_cache
{
	int				fd;
	t_list			*cache;
}					t_fd_cache;

int					get_next_line(const int fd, char **line);
int					get_next_line_untrim(const int fd, char **line);

#endif
