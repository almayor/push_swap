/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_heap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:37:12 by unite             #+#    #+#             */
/*   Updated: 2020/03/17 13:18:06 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

/*
** can't use realloc and calloc
*/

static int	resize_heap(t_heap *heap)
{
	t_node	*nodes;
	size_t	i;

	heap->size = heap->size ? heap->size * 2 : 4;
	if (heap->size > MAX_HEAP)
		return (1);
	if (!(nodes = malloc(sizeof(t_node) * heap->size)))
		return (1);
	i = 1;
	while (i <= heap->len)
	{
		nodes[i] = heap->nodes[i];
		i++;
	}
	free(heap->nodes);
	heap->nodes = nodes;
	return (0);
}

int	push_heap(t_heap *heap, int priority, void *data)
{
	size_t	i;
	size_t	j;

	if (heap->len + 1 >= heap->size &&
		resize_heap(heap))
		return (1);
	i = heap->len + 1;
	j = i / 2;
	while (i > 1 && heap->nodes[j].priority > priority)
	{
		heap->nodes[i] = heap->nodes[j];
		i = j;
		j = i / 2;
	}
	heap->nodes[i].priority = priority;
	heap->nodes[i].data = data;
	heap->len++;
	return (0);
}
