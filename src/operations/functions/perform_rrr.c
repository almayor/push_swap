/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:15:52 by unite             #+#    #+#             */
/*   Updated: 2020/05/12 23:12:12 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	perform_rrr(t_stack *stackA, t_stack *stackB)
{
	perform_rra(stackA, stackB);
	perform_rrb(stackA, stackB);
}
