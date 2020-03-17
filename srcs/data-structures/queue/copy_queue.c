/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:28:37 by unite             #+#    #+#             */
/*   Updated: 2020/03/15 18:37:50 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int	copy_queue(const t_queue *queueA, t_queue **queueB)
{
	t_clink	*linkA;
	char	*dataB;

	if (new_queue(queueB))
		return (1);
	linkA = queueA->first;
	while (linkA)
	{
		if (!(dataB = ft_strdup(linkA->data)))
		{
			free_queue(*queueB);
			return (1);
		}
		enqueue_queue(*queueB, dataB);
		linkA = linkA->next;
	}
	return (0);
}
