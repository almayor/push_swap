/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:40:13 by unite             #+#    #+#             */
/*   Updated: 2020/02/25 19:44:59 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	is_empty_stack(const t_stack *stack)
{
	if (!stack)
		return (-1);
	if (stack->start == NULL && stack->end == NULL)
		return (1);
	else
		return (0);
}
