/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_ss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:15:52 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 19:41:30 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	perform_ss(t_stack *stackA, t_stack *stackB)
{
	int	rc;

	if ((rc = perform_sa(stackA, stackB)))
		return (rc);
	if ((rc = perform_sb(stackA, stackB)))
		return (rc);
	return (0);
}
