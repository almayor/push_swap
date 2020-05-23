/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:28:33 by unite             #+#    #+#             */
/*   Updated: 2020/05/23 22:23:03 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_exit(int code)
{
	if (errno == ENOMEM)
		ft_putendl_fd("Not enough space/cannot allocate memory", 2);
	else if (errno == EINVAL)
		ft_putendl_fd("Error", 2);
	else if (errno)
		ft_dprintf(2, "Other error (errno = %d)\n", errno);
	exit(code);
}
