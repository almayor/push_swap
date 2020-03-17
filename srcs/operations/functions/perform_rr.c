/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:15:52 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 19:22:26 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	perform_rr(t_stack *stackA, t_stack *stackB)
{
	int	rc;

	if ((rc = perform_ra(stackA, stackB)))
		return (rc);
	if ((rc = perform_rb(stackA, stackB)))
		return (rc);
	return (0);
}
