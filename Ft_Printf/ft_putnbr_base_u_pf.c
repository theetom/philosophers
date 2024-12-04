/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_u_pf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:33:07 by toferrei          #+#    #+#             */
/*   Updated: 2024/11/14 14:48:09 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_base_u_pf(unsigned int nb, char *base)
{
	long	b;
	size_t	x;

	x = 0;
	b = ft_strlen_pf(base);
	if (nb > b - 1)
		x += ft_putnbr_base_pf(nb / b, base);
	x += write(1, &base[nb % b], 1);
	return (x);
}
