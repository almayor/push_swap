/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_rra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:15:52 by unite             #+#    #+#             */
/*   Updated: 2020/05/12 23:20:41 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	perform_rra(t_stack *stackA, t_stack *stackB)
{
	(void)stackB;
	reverse_rotate_stack(stackA);
}
