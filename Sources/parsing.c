/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:12:44 by toferrei          #+#    #+#             */
/*   Updated: 2025/01/06 15:43:51 by toferrei         ###   ########.fr       */
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

static const char	*valid_input(const char *str)
{
	int			len;
	const char	*number;
	bool		error;

	error = false;
	len = 0;
	while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
	{
		error_exit("Feed me only positive numbers");
	}
	if (!is_digit(*str))
	{
		error_exit("The input is not a correct digit");
	}
	number = str;
	while (is_digit(*str++))
		++len;
	if (len > 10)
	{
		error_exit("The value is too big, INT_MAX is the limit");
		return (NULL)
	}
	return (number);
}

static long	ft_atol(const char *str)
{
	long	nbr;

	nbr = 0;
	str = valid_input(str);
	if (str == NULL)
		return (-1);
	while (is_digit(*str))
		nbr = (nbr * 10) + (*str++ - 48);
	if (nbr > INT_MAX)
	{
		error_exit("The value is too big, INT_MAX is the limit");
		return (-1);
	}
	return (nbr);
}

void	parse_input(t_table *table, char **argv)
{
	if (ft_atol(argv[1]) != -1)
		table->philo_nbr = ft_atol(argv[1]);
	else if (ft_atol(argv[2]) != -1)
		table->time_to_die = ft_atol(argv[2]) * 1e3;
	else if(ft_atol(argv[3]) != -1)
		table->time_to_eat = ft_atol(argv[3]) * 1e3;
	else if (ft_atol(argv[4]) != -1)
		table->time_to_sleep = ft_atol(argv[4]) * 1e3;
	else
		return ;
	if (table->time_to_die < 6e4
		|| table->time_to_eat < 6e4
		|| table->time_to_sleep < 6e4)
		{
			error_exit("Use timestamps bigger than 60ms");
			table->error = true;
			return ;
		}
	if (argv[5])
		table->nbr_limits_meals = ft_atol(argv[5]);
	else
		table->nbr_limits_meals = -1;
}
