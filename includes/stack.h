/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:11:10 by unite             #+#    #+#             */
/*   Updated: 2020/02/26 05:19:34 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

#include <stdlib.h>
#include "ft_printf.h"
#include <stdio.h>

typedef	struct			s_link
{
	int					value;
	struct s_link		*next;
	struct s_link		*previous;
}						t_link;

typedef struct			s_stack
{
	struct s_link		*start;
	struct s_link		*end;
}						t_stack;

int 					free_stack(t_stack *stack);
int						has_duplicates_stack(const t_stack *stack);
int						is_empty_stack(const t_stack *stack);
int						is_sorted_stack(const t_stack *stack);
int						new_stack(t_stack *stack);
int						print_stack(const t_stack *stack);
int						pull_stack(t_stack *stack, t_link **link);
int						push_stack(t_stack *stack, t_link *link);
int						reverse_rotate_stack(t_stack *stack);
int						rotate_stack(t_stack *stack);
int						swap_stack(t_stack *stack);


#endif
