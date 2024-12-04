/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:51:04 by toferrei          #+#    #+#             */
/*   Updated: 2024/05/10 19:10:31 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_base_pf(long nb, char *base)
{
	long	b;
	size_t	x;

	x = 0;
	b = ft_strlen_pf(base);
	if (nb < 0)
	{
		x += write(1, "-", 1);
		nb = -nb;
	}
	if (nb > b - 1)
		x += ft_putnbr_base_pf(nb / b, base);
	x += write(1, &base[nb % b], 1);
	return (x);
}
