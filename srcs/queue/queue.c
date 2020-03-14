/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 10:50:47 by unite             #+#    #+#             */
/*   Updated: 2020/03/14 12:47:58 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

typedef struct	s_node
{
	char			*data;
	struct s_node	*next;
	struct s_node	*previous;
}				t_node;

typedef struct	s_queue
{
	t_node *first;
	t_node *last;	
}				t_queue;

int free_queue(t_queue *queue)
{
	t_node	*tmp;

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

int	new_queue(t_queue **queue)
{
	if (!(*queue = malloc(sizeof(t_queue))))
		return (1);
	(*queue)->first = 0;
	(*queue)->last = 0;
	return (0);
}

int	enqueue_queue(t_queue *queue, char *data)
{
	t_node 	*node;
	char	*data_copy;

	if (!(node = malloc(sizeof(t_node))))
		return (1);
	if (queue->last)
		queue->last->next = node;
	node->data = data;
	node->previous = queue->last;
	node->next = 0;
	queue->last = node;
	if (!queue->first)
		queue->first = node;
	return (0);
}

int	dequeue_queue(t_queue *queue, char **data)
{
	t_node	*node;

	if (!queue->first)
		return (1);
	node = queue->first;
	*data = node->data;
	queue->first = queue->first->next;
	if (queue->first)
		queue->first->previous = 0;
	else
		queue->last = 0;
	free(node);
	return (0);
}

int	copy_queue(const t_queue *queueA, t_queue **queueB)
{
	t_node	*nodeA;
	char	*dataB;

	if (new_queue(queueB))
		return (1);
	nodeA = queueA->first;
	while (nodeA)
	{
		if (!(dataB = ft_strdup(nodeA->data)))
		{
			free_queue(*queueB);
			return (1);
		}
		enqueue_queue(*queueB, dataB);
		nodeA = nodeA->next;
	}
	return (0);
}

// int main () {
//     t_queue 	*q;
//     char		*c;
//     size_t		i;

//     new_queue(&q);
//     enqueue_queue(q, "Clear drains");
//     enqueue_queue(q, "Feed cat");
//     enqueue_queue(q, "Make tea");
//     enqueue_queue(q, "Solve RC tasks");
//     enqueue_queue(q, "Tax return");
//     while (dequeue_queue(q, &c) == 0)
//     {
//         printf("%s\n", c);
//     }
//     return 0;
// }

int main () {
    t_queue 	*q1;
    t_queue 	*q2;
    char		*c;
    size_t		i;

    new_queue(&q1);
    enqueue_queue(q1, "Clear drains");
    enqueue_queue(q1, "Feed cat");
    enqueue_queue(q1, "Make tea");
    enqueue_queue(q1, "Solve RC tasks");
    enqueue_queue(q1, "Tax return");
    copy_queue(q1, &q2);
    while (dequeue_queue(q2, &c) == 0)
    {
        printf("%s\n", c);
    }
    while (dequeue_queue(q1, &c) == 0)
    {
        printf("%s\n", c);
    }
    return 0;
}
