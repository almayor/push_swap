/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_pa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:15:52 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 19:22:36 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	perform_pa(t_stack *stackA, t_stack *stackB)
{
	int	value;
	int	rc;
	
	if ((rc = pull_stack(stackB, &value)))
		return (rc);
	if ((rc = push_stack(stackA, value)))
		return (rc);
	return (0);
}
