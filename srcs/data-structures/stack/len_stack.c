/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 09:20:38 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 09:25:00 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	len_stack(const t_stack *stack)
{
	t_ilink	*link;
	int		len;

	len = 0;
	link = stack->start;
	while (link)
	{
		len++;
		link = link->next;
	}
	return (len);
}
