/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 04:31:40 by unite             #+#    #+#             */
/*   Updated: 2020/05/22 05:22:44 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	advanced_sort(t_stack *st_a, t_stack *st_b)
{
	advanced_split_stacks(st_a, st_b);
	advanced_merge_stacks(st_a, st_b);
}
