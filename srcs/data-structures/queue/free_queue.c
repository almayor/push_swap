/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:26:49 by unite             #+#    #+#             */
/*   Updated: 2020/03/15 18:37:42 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int free_queue(t_queue *queue)
{
	t_clink	*tmp;

	while (queue->first)
	{
		tmp = queue->first->next;
		free(queue->first->data);
		free(queue->first);
		queue->first = tmp;
	}
	free(queue);
	return (0);
}
