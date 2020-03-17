/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:15:52 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 19:22:22 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	perform_rrr(t_stack *stackA, t_stack *stackB)
{
	int	rc;

	if ((rc = perform_rra(stackA, stackB)))
		return (rc);
	if ((rc = perform_rrb(stackA, stackB)))
		return (rc);
	return (0);
}
