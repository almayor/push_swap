/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:29:23 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 19:46:18 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>
# include "libft.h"

typedef struct	s_clink
{
	char			*data;
	struct s_clink	*next;
	struct s_clink	*previous;
}				t_clink;

typedef struct	s_queue
{
	t_clink *first;
	t_clink *last;	
}				t_queue;

int	copy_queue(const t_queue *queueA, t_queue **queueB);
int	dequeue_queue(t_queue *queue, char **data);
int	enqueue_queue(t_queue *queue, const char *data);
int free_queue(t_queue *queue);
int	new_queue(t_queue **queue);
int	print_queue(const t_queue *queue);
int	len_queue(const t_queue *queue);

#endif
