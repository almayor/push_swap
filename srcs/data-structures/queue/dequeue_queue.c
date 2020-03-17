/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:28:11 by unite             #+#    #+#             */
/*   Updated: 2020/03/15 18:37:47 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int	dequeue_queue(t_queue *queue, char **data)
{
	t_clink	*link;

	if (!queue->first)
		return (-1);
	link = queue->first;
	*data = link->data;
	queue->first = queue->first->next;
	if (queue->first)
		queue->first->previous = 0;
	else
		queue->last = 0;
	free(link);
	return (0);
}
