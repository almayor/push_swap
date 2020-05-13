/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tab2stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:40:01 by unite             #+#    #+#             */
/*   Updated: 2020/05/13 18:08:17 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_tab2stack(char **tab, t_stack *stack)
{
	int	val;

	while (*tab)
	{
		if (!ps_isnumeric_str(*tab) ||
			ps_atoi(*tab, &val))
			return ((errno = EINVAL));
		if (append_stack(stack, val))
			return ((errno = ENOMEM));
		tab += 1;
	}
	if (!isset_stack(stack))
		return ((errno = EINVAL));
	return (0);
}
