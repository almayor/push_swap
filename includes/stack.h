/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:32:31 by unite             #+#    #+#             */
/*   Updated: 2020/03/16 09:22:18 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H

# define STACK_H

# include <stdlib.h>
# include "libft.h"

typedef	struct			s_ilink
{
	int					value;
	struct s_ilink		*next;
	struct s_ilink		*previous;
}						t_ilink;

typedef struct			s_stack
{
	struct s_ilink		*start;
	struct s_ilink		*end;
}						t_stack;

int	append_stack(t_stack *stack, int value);
int	copy_stack(const t_stack *stackA, t_stack **stackB);
int	free_stack(t_stack *stack);
int	has_duplicates_stack(const t_stack *stack);
int	is_empty_stack(const t_stack *stack);
int	is_sorted_stack(const t_stack *stack);
int	new_stack(t_stack **stack);
int	print_stack(const t_stack *stack);
int	pull_stack(t_stack *stack, int *value);
int	push_stack(t_stack *stack, int value);
int	reverse_rotate_stack(t_stack *stack);
int	rotate_stack(t_stack *stack);
int	swap_stack(t_stack *stack);
int	len_stack(const t_stack *stack);

#endif
