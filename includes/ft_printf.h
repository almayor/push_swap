/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 04:38:18 by unite             #+#    #+#             */
/*   Updated: 2020/02/26 04:41:13 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_dprintf(int fd, const char *format, ...);
int	ft_vprintf(const char *format, va_list ap);
int	ft_vdprintf(int fd, const char *format, va_list ap);

#endif
