/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_sa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:15:07 by unite             #+#    #+#             */
/*   Updated: 2020/02/26 05:14:20 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "stack.h"

int	perform_sa(t_stack *stackA, t_stack *stackB)
{
	(void)stackB;
	return (swap_stack(stackA));
}
