/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 01:47:16 by unite             #+#    #+#             */
/*   Updated: 2020/02/26 08:14:57 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "stack.h"
#include "libft.h"
#include "operations.h"

int	insertion_sort(t_stack *stackA, t_stack *stackB, int len)
{
	int	nshifted;
	int	nsorted;

	nsorted = 0;
	nshifted = 0;
	while (nsorted < len)
	{
		while (stackA->start->value < stackB->start->value)
		{
			if (nshifted >= nsorted - 1)
				break ;
			perform_operation(stackA, stackB, "rb");
			nshifted += 1;
		}
		perform_operation(stackA, stackB, "pb");
		if (nshifted == nsorted - 1)
			perform_operation(stackA, stackB, "sb");
		while (nshifted-- > 0)
			perform_operation(stackA, stackB, "rrb");
		nsorted += 1;
	}
	return (0);
}
