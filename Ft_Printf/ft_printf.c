/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:25:18 by toferrei          #+#    #+#             */
/*   Updated: 2024/05/14 10:28:04 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*create lists with arguments
pritn string char by char untill 

%c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.



*/
#include "ft_printf.h"

int	funcao_2(va_list lst_arg, int prt)
{
	size_t	x;

	x = 0;
	if (prt == 'c')
		x += ft_putchar_fd_pf(va_arg(lst_arg, int), 1);
	else if (prt == 'i' || prt == 'd')
		x += ft_putnbr_base_pf(va_arg(lst_arg, int), "0123456789");
	else if (prt == 's')
		x += ft_putstr_fd_pf(va_arg(lst_arg, char *), 1);
	else if (prt == 'u')
		x += ft_putnbr_base_u_pf(va_arg(lst_arg, unsigned long), "0123456789");
	else if (prt == 'p')
		x += prt_p(va_arg(lst_arg, unsigned long));
	else if (prt == 'x')
		x += ft_putnbr_base_u_pf(va_arg(lst_arg, unsigned long),
				"0123456789abcdef");
	else if (prt == 'X')
		x += ft_putnbr_base_u_pf(va_arg(lst_arg, unsigned long),
				"0123456789ABCDEF");
	else if (prt == '%')
		x += ft_putchar_fd_pf('%', 1);
	else
		return (ft_putchar_fd_pf('%', 1) + ft_putchar_fd_pf(prt, 1));
	return (x);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst_arg;
	size_t	count;

	count = 0;
	if (!str)
		return (-1);
	va_start(lst_arg, str);
	while (*str)
	{
		if (*str == '%')
			count += funcao_2(lst_arg, *(++str));
		else
		{
			ft_putchar_fd_pf(*str, 1);
			count++;
		}
		str++;
	}
	va_end(lst_arg);
	return (count);
}

/* int	main(void)
{
	printf("\n%d\n\n", ft_printf("%b", 0));
	printf("\n%d\n", printf(" %a %v ", 0, 0));
}*/