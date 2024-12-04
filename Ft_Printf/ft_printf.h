/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:25:05 by toferrei          #+#    #+#             */
/*   Updated: 2024/05/10 18:24:07 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
size_t	ft_strlen_pf(const char *str);
size_t	ft_putnbr_base_pf(long nb, char *base);
size_t	ft_putchar_fd_pf(char c, int fd);
size_t	ft_putstr_fd_pf(char *s, int fd);
size_t	ft_putnbr_base_u_pf(unsigned int nb, char *base);
size_t	prt_p(unsigned long vaarg);

#endif