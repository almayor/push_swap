/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 10:50:47 by unite             #+#    #+#             */
/*   Updated: 2020/03/14 11:26:37 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

int	new_queue(t_queue *queue)
{
	queue->first = 0;
	queue->last = 0;
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

int main () {
    t_queue 	*q;
    char		*c;
    size_t		i;

    new_queue(q);
    enqueue_queue(q, "Clear drains");
    enqueue_queue(q, "Feed cat");
    enqueue_queue(q, "Make tea");
    enqueue_queue(q, "Solve RC tasks");
    enqueue_queue(q, "Tax return");
    while (dequeue_queue(q, &c) == 0)
    {
        printf("%s\n", c);
    }
    return 0;
}
