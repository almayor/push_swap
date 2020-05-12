/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:15:52 by unite             #+#    #+#             */
/*   Updated: 2020/05/12 23:21:09 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	perform_rr(t_stack *stackA, t_stack *stackB)
{
	perform_ra(stackA, stackB);
	perform_rb(stackA, stackB);
}
