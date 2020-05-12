/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_rrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:15:52 by unite             #+#    #+#             */
/*   Updated: 2020/05/12 23:20:21 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	perform_rrb(t_stack *stackA, t_stack *stackB)
{
	(void)stackA;
	reverse_rotate_stack(stackB);
}
