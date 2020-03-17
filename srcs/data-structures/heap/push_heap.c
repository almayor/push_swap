/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_heap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:37:12 by unite             #+#    #+#             */
/*   Updated: 2020/03/17 17:06:35 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

/*
** can't use realloc and calloc
*/

int	push_heap(t_heap *heap, int priority, void *data)
{
	size_t	i;
	size_t	j;

	if (heap->len + 1 == heap->size)
		heap->len--;
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
