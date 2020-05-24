/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:28:33 by unite             #+#    #+#             */
/*   Updated: 2020/05/24 07:09:53 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_exit(int code)
{
	if (errno == ENOMEM)
		ft_dprintf(2, "Not enough space/cannot allocate memory");
	else if (errno == EINVAL)
		ft_dprintf(2, "Error\n");
	else if (errno)
		ft_dprintf(2, "Other error (errno = %d)\n", errno);
	exit(code);
}
