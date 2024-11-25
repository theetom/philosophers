/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:12:44 by toferrei          #+#    #+#             */
/*   Updated: 2024/11/24 21:29:42 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static inline bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static inline bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || 32 == c);
}

/* 
	1)check for negatives
	2) chack if the number is valid
	3) check for int max

	rturn ptr to number
 */

static const char	*valid_input(const char *str)
{
	int			len;
	const char	*number;

	len = 0;
	while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		error_exit("Feed me only positive numbers");
	if (!is_digit(*str))
		error_exit("The input is not a correct digit");
	number = str;
	while (is_digit(*str++))
		++len;
	if (len > 10)
		error_exit("The value is too big, INT_MAX is the limit");
	return (number);
}

static long	ft_atol(const char *str)
{
	long	nbr;

	nbr = 0;
	str = valid_input(str);
	while (is_digit(*str))
		nbr = (nbr * 10) + (*str++ - 48);
	if (nbr > INT_MAX)
		error_exit("The value is too big, INT_MAX is the limit");
	return (nbr);
}

// 1	actual numbers
// 2	not > int max
// 3	timestamps > 60ms

void	parse_input(t_table *table, char **argv)
{
	table->philo_nbr = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]) * 1e3;
	table->time_to_eat = ft_atol(argv[3]) * 1e3;
	table->time_to_sleep = ft_atol(argv[4]) * 1e3;
	if (table->time_to_die < 6e4
		|| table->time_to_eat < 6e4
		|| table->time_to_sleep < 6e4)
		error_exit("Use timestamps bigger than 60ms");
	if (argv[5])
		table->nbr_limits_meals = ft_atol(argv[5]);
	else
		table->nbr_limits_meals = -1;
}
