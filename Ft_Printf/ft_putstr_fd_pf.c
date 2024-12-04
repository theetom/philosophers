/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:44:55 by toferrei          #+#    #+#             */
/*   Updated: 2024/05/10 17:19:24 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstr_fd_pf(char *s, int fd)
{
	size_t	x;

	x = 0;
	if (!s)
		return (x += (write(1, "(null)", 6)));
	while (*s)
		x += ft_putchar_fd_pf(*s++, fd);
	return (x);
}
