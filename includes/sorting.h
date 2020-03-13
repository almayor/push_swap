/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 02:50:01 by unite             #+#    #+#             */
/*   Updated: 2020/02/26 08:11:57 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

#include <string.h>
#include "stack.h"
#include "operations.h"

int	insertion_sort(t_stack *stackA, t_stack *stackB, int len);
int	quick_sort(t_stack *stackA, t_stack *stackB, int len);

#endif
