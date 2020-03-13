/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:01:49 by unite             #+#    #+#             */
/*   Updated: 2020/02/26 08:12:50 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operations.h"
#include "libft.h"
#include "sorting.h"

static int	scroll_back(t_stack *stackA, t_stack *stackB, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		perform_operation(stackA, stackB, "rra");
		i += 1;
	}
	return (0);
}

static int	unpartition(t_stack *stackA, t_stack *stackB, int npushed)
{
	int	i;

	i = 0;
	while (i < npushed)
	{
		perform_operation(stackA, stackB, "pa");
		i += 1;
	}
	return (0);
}

static int	partition(t_stack *stackA, t_stack *stackB, int len,
													    int *npushed)
{
	int	i;
	t_link	*link;
	int		pivot;

	link = stackA->start;
	pivot = link->value;
	i = 0;
	*npushed = 0;
	while (i < len)
	{
		if (link->value < pivot)
		{
			perform_operation(stackA, stackB, "pb");
			*npushed += 1;
		}
		perform_operation(stackA, stackB, "ra");
		i += 1;
	}
	scroll_back(stackA, stackB, len);
	return (0);
}

int	quick_sort(t_stack *stackA, t_stack *stackB, int len)
{
	int	npushed;

	if (len < 2)
		return (0);
	if (len < 15)
		return (insertion_sort(stackA, stackB, len));
	if (perform_operation(stackA, stackB, "ra") ||
		partition(stackA, stackB, len, &npushed) ||
		quick_sort(stackA, stackB, len - npushed - 1) ||
		quick_sort(stackB, stackA, npushed) ||
		unpartition(stackA, stackB, npushed) ||
		perform_operation(stackA, stackB, "rra"))
		return (1);
	return (0);
}
