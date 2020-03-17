/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_heap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:36:46 by unite             #+#    #+#             */
/*   Updated: 2020/03/17 17:06:09 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

int			new_heap(t_heap **heap)
{
	if (!(*heap = malloc(sizeof(t_heap))) ||
		!((*heap)->nodes = malloc(sizeof(t_node) * HEAP_SIZE)))
		return (1);
	(*heap)->len = 0;
	(*heap)->size = HEAP_SIZE;
	return (0);
}
