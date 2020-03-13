/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_to_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 02:27:48 by unite             #+#    #+#             */
/*   Updated: 2020/02/26 05:39:38 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include "stack.h"

static int	count_arguments(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i += 1;
	return (i);
}

int			arguments_to_stack(t_stack *stack, char **args)
{
	t_link	*link;
	int		value;
	int		nargs;
	int		i;

	nargs = count_arguments(args);
	i = 0;
	while (i < nargs)
	{
		if (!is_numeric_str(args[nargs - 1 - i]) ||
			ft_atoi2(args[nargs - 1 - i], &value) ||
			!(link = malloc(sizeof(t_link))))
			return (1);
		link->value = value;
		push_stack(stack, link);
		i += 1;
	}
	if (has_duplicates_stack(stack))
		return (1);
	return (0);
}
