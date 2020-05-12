/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:56:29 by unite             #+#    #+#             */
/*   Updated: 2020/05/12 23:29:57 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ps_atoi(const char *str, int *resp)
{
	long long	res;
	int			negative;

	while (ft_isspace(*str))
		str++;
	negative = 0;
	if (*str == '-' || *str == '+')
	{
		negative = *str == '-' ? 1 : 0;
		str++;
	}
	res = 0;
	while (ft_isdigit(*str))
	{
		res = res * 10 - (*str - '0');
		str++;
		if (res < MININT && negative)
			ps_exit("Error\n", 1);
		if (res < -MAXINT && !negative)
			ps_exit("Error\n", 1);
	}
	*resp = negative ? res : -res;
	return (0);
}
