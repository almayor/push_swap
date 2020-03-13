/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 02:20:08 by unite             #+#    #+#             */
/*   Updated: 2020/02/26 05:11:31 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "libft.h"
#include "stack.h"
#include <stdio.h>

# define MININT		-2147483648
# define MAXINT		2147483647

int		arguments_to_stack(t_stack *stack, char **args);
int		ft_atoi2(const char *str, int *resp);
int		is_numeric_str(const char *str);
void	print_trace(t_stack *stackA, t_stack *stackB, char *oper);


#endif
