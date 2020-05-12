/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_ss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:15:52 by unite             #+#    #+#             */
/*   Updated: 2020/05/12 23:11:30 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	perform_ss(t_stack *stackA, t_stack *stackB)
{
	perform_sa(stackA, stackB);
	perform_sb(stackA, stackB);
}
