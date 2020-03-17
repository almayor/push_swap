/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 09:20:38 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 19:50:23 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int	len_queue(const t_queue *queue)
{
	t_clink	*link;
	int		len;

	len = 0;
	link = queue->first;
	while (link)
	{
		len++;
		link = link->next;
	}
	return (len);
}
