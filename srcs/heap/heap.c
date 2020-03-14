/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 01:53:26 by unite             #+#    #+#             */
/*   Updated: 2020/03/14 11:27:28 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_node
{
	int		priority;
	void	*data;
}				t_node;

typedef struct	s_heap
{
	t_node	*nodes;
	size_t	len;
	size_t	size;
}				t_heap;

int			new_heap(t_heap *heap)
{
	heap->len = 0;
	heap->size = 0;
	return (0);
}

/*
** can't use realloc and calloc
*/

static int	resize_heap(t_heap *heap)
{
	t_node	*nodes;
	size_t	i;

	heap->size = heap->size ? heap->size * 2 : 4;
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
		j = j / 2;
	}
	heap->nodes[i].priority = priority;
	heap->nodes[i].data = data;
	heap->len++;
	return (0);
}

int	pop_heap(t_heap *heap, void **data)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!heap->len)
		return (1);
	*data = heap->nodes[1].data;
	i = 1;
	while (i < heap->len)
	{
		k = heap->len;
		j = i * 2;
		if (j <= heap->len &&
			heap->nodes[j].priority < heap->nodes[k].priority)
			k = j;
		if (j + 1 <= heap->len &&
			heap->nodes[j + 1].priority < heap->nodes[k].priority)
			k = j + 1;
		heap->nodes[i] = heap->nodes[k];
		i = k;
	}
	heap->len--;
	return (0);
}

int main () {
    t_heap 	*h;
    void	*c;
    size_t	i;

    new_heap(h);
    push_heap(h, 3, "Clear drains");
    push_heap(h, 4, "Feed cat");
    push_heap(h, 5, "Make tea");
    push_heap(h, 1, "Solve RC tasks");
    push_heap(h, 2, "Tax return");
    while (pop_heap(h, &c) == 0)
    {
        printf("%s\n", (char *)c);
    }
    return 0;
}
