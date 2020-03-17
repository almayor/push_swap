/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 15:54:31 by unite             #+#    #+#             */
/*   Updated: 2020/03/17 17:06:47 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP_H

# define HEAP_H
# define HEAP_PRIVATE_H
# define HEAP_SIZE	1024

# include <stdlib.h>
# include "libft.h"

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

int	free_heap(t_heap *heap);
int	new_heap(t_heap **heap);
int	pop_heap(t_heap *heap, void **data);
int	push_heap(t_heap *heap, int priority, void *data);

#endif
