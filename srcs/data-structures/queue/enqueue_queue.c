/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:27:46 by unite             #+#    #+#             */
/*   Updated: 2020/03/15 18:37:44 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int	enqueue_queue(t_queue *queue, const char *data)
{
	t_clink 	*link;
	char		*data_copy;

	if (!(data_copy = ft_strdup(data)))
		return (1);
	if (!(link = malloc(sizeof(t_clink))))
	{
		free(data_copy);
		return (1);
	}
	if (queue->last)
		queue->last->next = link;
	link->data = data_copy;
	link->previous = queue->last;
	link->next = 0;
	queue->last = link;
	if (!queue->first)
		queue->first = link;
	return (0);
}
