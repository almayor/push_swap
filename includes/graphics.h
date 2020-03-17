/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 18:41:38 by unite             #+#    #+#             */
/*   Updated: 2020/03/15 18:48:35 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H

# define GRAPHICS_H

# include "stack.h"
# include "libft.h"

typedef struct	s_display
{
	int	verbose;
	int	color;
}				t_display;

int	show_graphics(const t_stack *stackA, const t_stack *stackB,
				  const char *oper, const t_display *display);

#endif
