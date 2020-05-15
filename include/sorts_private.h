/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 18:09:07 by unite             #+#    #+#             */
/*   Updated: 2020/05/15 02:37:20 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTS_H
# define SORTS_H

# include "stack.h"
# include "libftprintfgnl.h"
# include <limits.h>

# define NBATCHES	4

int		perform_operation(t_stack *sa, t_stack *sb, char *oper);

void	prepare_stacks_fwd_fwd(t_stack *sa, t_stack *sb, int ia, int ib);
void	prepare_stacks_fwd_rev(t_stack *sa, t_stack *sb, int ia, int jb);
void	prepare_stacks_rev_fwd(t_stack *sa, t_stack *sb, int ja, int ib);
void	prepare_stacks_rev_rev(t_stack *sa, t_stack *sb, int ja, int jb);

#endif
