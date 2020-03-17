/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_queue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 03:17:26 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 17:26:17 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int	print_queue(const t_queue *queue)
{
	t_clink	*link;

	link = queue->first;
	if (!link)
		return (0);
	ft_printf("Forward links: %s", link->data);
	while (link && (link = link->next))
		ft_printf("->%s", link->data);
	ft_printf("\n");
	link = queue->last;
	ft_printf("Backward links: %s", link->data);
	while (link && (link = link->previous))
		ft_printf("<-%s", link->data);
	ft_printf("\n");
	return (0);
}